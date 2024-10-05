/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:27:57 by yimizare          #+#    #+#             */
/*   Updated: 2024/10/05 19:18:49 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char *argv[])
{
	t_philo	*philo;
	t_data	info;
	int		flag;
	
	flag = 0;
	philo = NULL;
	(void)philo;
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
		if (init_data(&info , argv, flag))
			return (1);
		if (ft_error(&info))
			return (1);
		info.philos = malloc(sizeof(pthread_t) * info.philos_num);
		info.
	}
	//philo = init_philos(philo, argv);
	return (0);
}