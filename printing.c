/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:02:28 by yimizare          #+#    #+#             */
/*   Updated: 2024/10/09 14:06:40 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_take_fork(t_philo *philo, int flag)
{
	long	time;

	time = ft_get_time() - philo->data->starting;
	pthread_mutex_lock(philo->data->mutex2);
	pthread_mutex_lock(philo->data->mutex1);
	if (philo->data->stopping)
	{
		pthread_mutex_unlock(philo->data->mutex1);
		pthread_mutex_unlock(philo->data->mutex2);
		return ;
	}
	pthread_mutex_unlock(philo->data->mutex1);
	if (flag)
	{
		printf("%ld  %d has taken a fork\n", time, philo->philo_id);
		printf("%ld  %d is eating\n", time, philo->philo_id);
	}
	else
		printf("%ld  %d has taken a fork\n", time, philo->philo_id);
	pthread_mutex_unlock(philo->data->mutex2);
}
