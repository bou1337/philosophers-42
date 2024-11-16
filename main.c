/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:08:14 by iait-bou          #+#    #+#             */
/*   Updated: 2024/10/08 14:25:52 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(int ac, char **av)
{
	int	i;

	if (ac == 6 || ac == 5)
	{
		i = 1;
		while (av[i])
		{
			if (!is_number(av[i]))
			{
				error_in_arg(i);
				return (0);
			}
			i++;
		}
		if (!chek_max_int(av))
			return (0);
		return (1);
	}
	else
	{
		put_str("ERROR: The number of argments must be 5 or 6\n", 2);
		return (0);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	int		j;

	j = 0;
	if (!check_arg(ac, av))
		return (0);
	init_philo(&data, ac, av);
	if (data.time_sleep > data.time_die)
		data.time_sleep = data.time_die;
	if (data.time_eat > data.time_die)
		data.time_eat = data.time_die;
	init_mutex(&data);
	create_thread(&data);
	while (j < data.nb)
	{
		pthread_join(data.philo[j].thread, NULL);
		j++;
	}
	free(data.fork);
	free(data.philo);
	return (0);
}
