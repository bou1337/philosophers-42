/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:05:58 by iait-bou          #+#    #+#             */
/*   Updated: 2024/10/12 01:59:05 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data, int ac, char **av)
{
	int	i;

	data->nb = ft_atoil(av[1]);
	data->time_die = ft_atoil(av[2]);
	data->time_eat = ft_atoil(av[3]);
	data->time_sleep = ft_atoil(av[4]);
	data->philo = malloc(sizeof(t_philo) * data->nb);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb);
	data->count_meal = 0;
	data->arg_6 = 0;
	data->stop = 0;
	if (ac == 6)
	{
		data->arg_6 = 1;
		data->must_eat = ft_atoil(av[5]);
	}
	i = 0;
	data->start_time = get_current_time();
	while (i < data->nb)
	{
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		data->philo[i].last_eat = get_current_time();
		i++;
	}
}

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&(data->mutex_printf), NULL);
	pthread_mutex_init(&(data->mutex_count_meal), NULL);
	pthread_mutex_init(&(data->mutex_last_eat), NULL);
	pthread_mutex_init(&(data->mutex_stop), NULL);
	pthread_mutex_init(&(data->mutex_start), NULL);
	while (i < data->nb)
	{
		pthread_mutex_init(&(data->fork[i]), NULL);
		i++;
	}
}
