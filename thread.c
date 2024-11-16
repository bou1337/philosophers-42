/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:10:09 by iait-bou          #+#    #+#             */
/*   Updated: 2024/10/12 02:06:26 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	pthread_mutex_lock(&data->mutex_start);
	pthread_mutex_unlock(&data->mutex_start);
	if (data->nb == 1)
	{
		pthread_mutex_lock(&(data->fork[(philo->id - 1) % data->nb]));
		printf("%ld %d %s", get_current_time() - data->start_time, philo->id,
			"has taken a fork\n");
		return (NULL);
	}
	while (1)
	{
		if (check_stop(data))
			return (NULL);
		if (printf_status(data, philo) != 1)
			return (NULL);
	}
	return (NULL);
}

int	create_thread(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->mutex_start);
	while (i < data->nb)
	{
		pthread_create(&(data->philo[i].thread), NULL, &routine,
			&(data->philo[i]));
		i++;
	}
	while (i < data->nb)
	{
		data->philo[i].last_eat = get_current_time();
		i++;
	}
	pthread_mutex_unlock(&data->mutex_start);
	while (chek_death_full(data))
	{
		usleep(100);
	}
	return (0);
}

void	ft_usleep(int ms)
{
	long	start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < ms)
	{
		usleep(100);
	}
}
