/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:37:10 by yimizare          #+#    #+#             */
/*   Updated: 2024/10/10 21:15:26 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_for_stoppage(t_philo *philo)
{
	pthread_mutex_lock(philo->data->mutex1);
	if (philo->data->stopping)
	{
		pthread_mutex_unlock(philo->data->mutex1);
		return (1);
	}
	pthread_mutex_unlock(philo->data->mutex1);
	return (0);
}

int	ft_eat(t_philo *philo)
{
	if (check_for_stoppage(philo))
		return (1);
	pthread_mutex_lock(philo->first_fork);
	ft_print_take_fork(philo, 0);
	if (one_philo(philo))
		return (1);
	pthread_mutex_lock(philo->second_fork);
	ft_print_take_fork(philo, 1);
	pthread_mutex_lock(philo->data->m_last_time);
	philo->last_time_ate = ft_get_time();
	pthread_mutex_unlock(philo->data->m_last_time);
	ft_usleep(philo->data->tt_eat);
	pthread_mutex_lock(philo->data->m_last_time);
	if (philo->meals < philo->data->meals_to_eat)
		philo->meals++;
	pthread_mutex_unlock(philo->data->m_last_time);
	if (check_meals(philo))
		return (1);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(philo->data->mutex1);
	if (philo->data->stopping)
	{
		pthread_mutex_unlock(philo->data->mutex1);
		return (1);
	}
	pthread_mutex_unlock(philo->data->mutex1);
	time = ft_get_time() - philo->data->starting;
	pthread_mutex_lock(philo->data->mutex2);
	printf("%ld  %d is sleeping\n", time, philo->philo_id);
	pthread_mutex_unlock(philo->data->mutex2);
	ft_usleep(philo->data->tt_sleep);
	return (0);
}

int	ft_think(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(philo->data->mutex1);
	if (philo->data->stopping)
	{
		pthread_mutex_unlock(philo->data->mutex1);
		return (1);
	}
	pthread_mutex_unlock(philo->data->mutex1);
	time = ft_get_time() - philo->data->starting;
	pthread_mutex_lock(philo->data->mutex2);
	printf("%ld  %d is thinking\n", time, philo->philo_id);
	pthread_mutex_unlock(philo->data->mutex2);
	return (0);
}

void	*routine(void *my_philo)
{
	t_philo	*philo;

	philo = (t_philo *)my_philo;
	if (philo->philo_id % 2 == 0)
		usleep(120);
	while (true)
	{
		if (philo->data->philos_num % 2)
			usleep(400);
		pthread_mutex_lock(philo->data->mutex1);
		if (philo->data->stopping)
		{
			pthread_mutex_unlock(philo->data->mutex1);
			break ;
		}
		pthread_mutex_unlock(philo->data->mutex1);
		if (ft_eat(philo) || ft_sleep(philo) || ft_think(philo))
		{
			break ;
		}
		usleep(100);
	}
	return (NULL);
}
