/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user007 <user007@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:48:39 by yimizare          #+#    #+#             */
/*   Updated: 2024/10/03 23:22:09 by user007          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_time(void)
{
	t_time	time;
	
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 100) + (time.tv_usec / 1000));	
}

int	ft_usleep(long time)
{
	long	start;

	start = ft_get_time();
	while ((ft_get_time - start) < (size_t)time)
		usleep(500);
	return (0);
}

int	ft_atoi(char *in)
{
	int		res;
	int		i;

	i = 0;
	res = 0;
	while (in[i] == 32 || (in[i] >= 9 && in[i] <= 13))
		i++;
	if (in[i] == '+' || in[i] == '-')
	{
		if (in[i] == '-')
		{
			ft_putstr("[ERROR] give me positive numbers ...\n");
			return (-1);
		}
		i++;
	}
	while (in[i])
	{
		if (ft_util(&res, in, &i) == -1)
			return (-1);
		i++;
	}
	return (res);
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
