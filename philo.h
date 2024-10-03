/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:33:15 by yimizare          #+#    #+#             */
/*   Updated: 2024/09/24 16:27:48 by yimizare         ###   ########.fr       */
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

typedef struct s_info
{
	int				philos_num;
	size_t			tt_die;
	size_t			tt_sleep;
	size_t			tt_eat;
	bool			deceased;
	pthread_mutex_t	forks;
	
	
	

	
}	t_info;



typedef struct s_philo
{
	

	
}	t_philo;

void	ft_putstr_fd(char *s, int fd);

#endif