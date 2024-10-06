/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:37:10 by yimizare          #+#    #+#             */
/*   Updated: 2024/10/06 18:59:30 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->data->mutex1);
	if (philo->data->stopping) {
		pthread_mutex_unlock(philo->data->mutex1);
		return (1);
	}
	pthread_mutex_unlock(philo->data->mutex1);
	pthread_mutex_lock(philo->left_fork);
	ft_print_take_fork(philo, 0);
	if (one_philo(philo))
		return (1);
	pthread_mutex_lock(philo->right_fork);
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
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int		ft_sleep(t_philo *philo)
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

int		ft_think(t_philo *philo)
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
		usleep(250);
	while (!philo->data->stopping)
	{
		if (ft_eat(philo) || ft_sleep(philo) || ft_think(philo))
			break ;
		usleep(400);
	}
	return (NULL);
}
