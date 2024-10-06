/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:27:57 by yimizare          #+#    #+#             */
/*   Updated: 2024/10/06 18:45:15 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meals(t_philo *philo)
{
	size_t		nb_of_meals;

	pthread_mutex_lock(philo->data->meals_mutex);
	pthread_mutex_lock(philo->data->m_last_time);
	nb_of_meals = philo->data->meals_to_eat;
	pthread_mutex_unlock(philo->data->m_last_time);
	if (philo->meals == nb_of_meals)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(philo->data->m_last_time);
		philo->data->full_philos++;
		pthread_mutex_unlock(philo->data->m_last_time);
		pthread_mutex_unlock(philo->data->meals_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->data->meals_mutex);
	return (0);
}

void	ft_join(t_data *data, t_mutex *mutexes, t_philo *philo)
{
	int		i;

	i = -1;
	while (++i < data->philos_num)
		pthread_join(data->philos[i], NULL);
	pthread_join(data->monitor, NULL);
	i = -1;
	while (++i < data->philos_num)
		pthread_mutex_destroy(&mutexes[i].mutex);
	pthread_mutex_destroy(data->mutex1);
	pthread_mutex_destroy(data->mutex2);
	pthread_mutex_destroy(data->m_last_time);
	free(data->mutex1);
	free(data->mutex2);
	free(data->m_last_time);
	free(data->philos);
	free(data->meals_mutex);
	free(philo);
	free(mutexes);
}

int	one_philo(t_philo *philo)
{
	int		end;

	if (philo->data->philos_num == 1)
	{
		pthread_mutex_lock(philo->data->mutex1);
		end = philo->data->stopping;
		pthread_mutex_unlock(philo->data->mutex1);
		while (end == 0)
		{
			pthread_mutex_lock(philo->data->mutex1);
			end = philo->data->stopping;
			pthread_mutex_unlock(philo->data->mutex1);
		}
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	return (0);
}


int main(int ac, char *argv[])
{
	t_philo	*philo;
	t_mutex	*mutexes;
	t_data	data;
	int		flag;
	int		i;
	
	flag = 0;
	philo = NULL;
	i = -1;
	if (ac == 6)
		flag = 1;
	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd("not enough or too much philosophers\n" ,2);
		return (1);
	}
	if (parsing(ac, argv))
		return (1);
	else
	{
		printf("correct parsing\n");
		if (init_data(&data , argv, flag))
			return (1);
		if (ft_error(&data))
			return (1);
		data.philos = malloc(sizeof(pthread_t) * data.philos_num);
		mutexes = malloc(sizeof(t_mutex) * data.philos_num);
		philo = malloc(sizeof(t_philo) * data.philos_num);
		if (!data.philos || !mutexes || !philo || init_mutexes(&data, mutexes))
			return (1);
		init_philo(&data, philo, mutexes);
		data.starting = ft_get_time();
		while (data.philos_num > ++i)
			pthread_create(&data.philos[i], NULL, &routine, (void *)&philo[i]);
		pthread_create(&data.monitor, NULL, &ft_monitor, (void *)philo);
		ft_join(&data, mutexes, philo);
	}
	return (0);
}

