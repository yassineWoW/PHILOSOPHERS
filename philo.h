/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:33:15 by yimizare          #+#    #+#             */
/*   Updated: 2024/10/05 19:17:36 by yimizare         ###   ########.fr       */
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


typedef	struct timeval	t_time;


typedef struct s_data
{
	int				philos_num;
	size_t			tt_die;
	size_t			tt_sleep;
	size_t			tt_eat;
	size_t			meals_to_eat;
	bool			deceased;
	pthread_t		monitor;
	pthread_t		philos;
	int				full_philos;
}	t_data;


typedef struct s_philo
{
	int				philo_id;
	size_t			last_time_ate;
	size_t			meals_ate;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	
}	t_philo;

void	ft_putstr_fd(char *s, int fd);
size_t	ft_get_time(void);
int		ft_usleep(long time);
int		ft_atoi(char *in);
int		ft_util(int *res, char *in, int	*i);
int		parsing(int ac, char **argv);
int		ft_error(t_data *info);

#endif