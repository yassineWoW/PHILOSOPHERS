/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:48:39 by yimizare          #+#    #+#             */
/*   Updated: 2024/10/05 19:16:11 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_time(void)
{
	t_time	time;
	
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));	
}

int	ft_usleep(long time)
{
	long	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < (size_t)time)
		usleep(500);
	return (0);
}

int		ft_error(t_data *info)
{
	if (info->philos_num < 1 || info->philos_num > 200
		|| info->tt_die< 60 || info->tt_eat < 60
		|| info->tt_sleep < 60 || info->meals_to_eat == 0)
	{
		ft_putstr_fd("makes no sense try again please ...\n", 1);
		return (1);
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}
