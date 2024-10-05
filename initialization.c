/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:28:01 by yimizare          #+#    #+#             */
/*   Updated: 2024/10/05 19:00:20 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *info, char **av, int flag)
{
	if (ft_atoi(av[1]) == -1 || ft_atoi(av[2]) == -1 || ft_atoi(av[3]) == -1
		|| ft_atoi(av[4]) == -1 || (av[5] && ft_atoi(av[5]) == -1))
		return (1);
	info->philos_num = ft_atoi(av[1]);
	info->tt_die = ft_atoi(av[2]);
	info->tt_eat = ft_atoi(av[3]);
	info->tt_sleep = ft_atoi(av[4]);
	if (flag)
		info->meals_to_eat = ft_atoi(av[5]);
	else
		info->meals_to_eat = -1;
	info->full_philos = 0;
	return (0);
}