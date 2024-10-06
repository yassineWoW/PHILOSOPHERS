/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:07:47 by yimizare          #+#    #+#             */
/*   Updated: 2024/10/06 18:36:57 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_death(t_philo *philo, int i)
{
	size_t	time;

	pthread_mutex_lock(philo->data->meals_mutex);
	pthread_mutex_lock(philo->data->m_last_time);
	time = ft_get_time() - philo[i].last_time_ate;
	pthread_mutex_unlock(philo->data->m_last_time);
	pthread_mutex_lock(philo->data->mutex1);
	if (philo->data->stopping || time > philo->data->tt_die)
	{
		philo->data->stopping = 1;
		printf("%ld  %d died\n", ft_get_time() - \
		philo->data->starting, philo[i].philo_id);
		pthread_mutex_unlock(philo->data->mutex1);
		pthread_mutex_unlock(philo->data->meals_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->data->mutex1);
	pthread_mutex_unlock(philo->data->meals_mutex);
	return (0);
}

int check_philos_ate(t_philo *philo)
{
	pthread_mutex_lock(philo->data->meals_mutex);
	pthread_mutex_lock(philo->data->mutex1);
	if (philo->data->full_philos == philo->data->philos_num)
	{
		philo->data->stopping = 1;
		pthread_mutex_unlock(philo->data->mutex1);
		pthread_mutex_unlock(philo->data->meals_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->data->meals_mutex);
	pthread_mutex_unlock(philo->data->mutex1);
	return (0);
}

void	*ft_monitor(void *philos)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)philos;
	i = 0;
	while (1)
	{
		if (check_philo_death(philo, i) || check_philos_ate(philo))
			break ;
		i = (i + 1) % philo->data->philos_num;
		usleep(500);
	}
	return (NULL);
}