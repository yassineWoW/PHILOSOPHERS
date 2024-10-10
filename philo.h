/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:33:15 by yimizare          #+#    #+#             */
/*   Updated: 2024/10/09 18:15:35 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct timeval	t_time;

typedef struct s_data
{
	int				philos_num;
	size_t			tt_die;
	size_t			tt_sleep;
	size_t			tt_eat;
	size_t			meals_to_eat;
	bool			deceased;
	pthread_t		monitor;
	pthread_t		*philos;
	int				full_philos;
	size_t			starting;
	size_t			stopping;
	pthread_mutex_t	*mutex1;
	pthread_mutex_t	*mutex2;
	pthread_mutex_t	*m_last_time;
	pthread_mutex_t	*meals_mutex;
}	t_data;

typedef struct s_philo
{
	int				philo_id;
	size_t			last_time_ate;
	size_t			meals;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	t_data			*data;
}	t_philo;

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
}	t_mutex;

void	ft_putstr_fd(char *s, int fd);
size_t	ft_get_time(void);
int		ft_usleep(long time);
int		ft_atoi(char *in);
int		ft_util(int *res, char *in, int	*i);
int		parsing(int ac, char **argv);
int		ft_error(t_data *info);
void	*routine(void *my_philo);
void	init_philo(t_data *data, t_philo *philo, t_mutex *mutexes);
int		init_mutexes(t_data *data, t_mutex *mutexes);
int		init_data(t_data *data, char **av, int flag);
int		one_philo(t_philo *philo);
int		check_meals(t_philo *philo);
int		check_philo_death(t_philo *philo, int i);
void	*ft_monitor(void *philos);
void	ft_print_take_fork(t_philo *philo, int flag);

#endif