/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user007 <user007@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:33:15 by yimizare          #+#    #+#             */
/*   Updated: 2024/10/03 23:25:09 by user007          ###   ########.fr       */
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


typedef struct s_info
{
	int				philos_num;
	size_t			tt_die;
	size_t			tt_sleep;
	size_t			tt_eat;
	bool			deceased;
	pthread_t		monitor;
	
	
	
	
	

-	
}	t_info;



typedef struct s_philo
{
	int				philo_id;
	size_t			last_time_ate;
	size_t			meals_ate;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	
}	t_philo;

void	ft_putstr_fd(char *s, int fd);
size_t	ft_gettime(void);
int		ft_usleep(long time);
int		ft_atoi(char *in);

#endif