/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:28:01 by yimizare          #+#    #+#             */
/*   Updated: 2024/10/10 13:11:29 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char **av, int flag)
{
	if (ft_atoi(av[1]) == -1 || ft_atoi(av[2]) == -1 || ft_atoi(av[3]) == -1
		|| ft_atoi(av[4]) == -1 || (av[5] && ft_atoi(av[5]) == -1))
		return (1);
	data->philos_num = ft_atoi(av[1]);
	data->tt_die = ft_atoi(av[2]);
	data->tt_eat = ft_atoi(av[3]);
	data->tt_sleep = ft_atoi(av[4]);
	if (flag)
		data->meals_to_eat = ft_atoi(av[5]);
	else
		data->meals_to_eat = -1;
	data->full_philos = 0;
	data->stopping = 0;
	data->starting = 0;
	return (0);
}

int	init_mutexes(t_data *data, t_mutex *mutexes)
{
	int	i;

	i = 0;
	while (i < data->philos_num)
	{
		if (pthread_mutex_init(&mutexes[i].mutex, NULL))
			return (1);
		i++;
	}
	data->mutex1 = malloc(sizeof(pthread_mutex_t));
	data->mutex2 = malloc(sizeof(pthread_mutex_t));
	data->m_last_time = malloc(sizeof(pthread_mutex_t));
	data->meals_mutex = malloc(sizeof(pthread_mutex_t));
	if (!data->mutex1 || !data->mutex2 || !data->m_last_time
		|| !data->meals_mutex)
		return (1);
	if (pthread_mutex_init(data->mutex1, NULL)
		|| pthread_mutex_init(data->mutex2, NULL)
		|| pthread_mutex_init(data->m_last_time, NULL)
		|| pthread_mutex_init(data->meals_mutex, NULL))
		return (1);
	return (0);
}

void	init_philo(t_data *data, t_philo *philo, t_mutex *mutexes)
{
	int	i;

	i = 0;
	while (i < data->philos_num)
	{
		philo[i].philo_id = i + 1;
		philo[i].meals = 0;
		philo[i].last_time_ate = ft_get_time();
		if (i % 2)
		{
			philo[i].first_fork = &mutexes[i].mutex; 
			philo[i].second_fork = &mutexes[(i + 1) % data->philos_num].mutex;
		}
		else
		{
			philo[i].first_fork = &mutexes[(i + 1) % data->philos_num].mutex;
			philo[i].second_fork = &mutexes[i].mutex;
		}
		philo[i].data = data;
		i++;
	}
}
