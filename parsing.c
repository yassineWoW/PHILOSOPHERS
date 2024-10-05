/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:23:01 by yimizare          #+#    #+#             */
/*   Updated: 2024/10/05 16:35:35 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_util(int *res, char *in, int	*i)
{
	if (in[*i] >= '0' && in[*i] <= '9')
		*res = *res * 10 + (in[*i] - '0');
	else
	{
		ft_putstr_fd("[ERROR] Not a number ...\n", 1);
		return (-1);
	}
	if (*res > 2147483647)
	{
		ft_putstr_fd("[ERROR] Number to big ...\n", 1);
		return (-1);
	}
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
			ft_putstr_fd("[ERROR] give me positive numbers ...\n", 1);
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

int	parsing(int ac, char **argv)
{
	int i;

	i = 1;
	(void)ac;
	while (argv[i] != NULL)
	{
		if (ft_atoi(argv[i]) == -1)
			return (1);
		else
			i++;
	}
	return (0);
}
