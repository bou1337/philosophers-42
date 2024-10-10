/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:06:58 by iait-bou          #+#    #+#             */
/*   Updated: 2024/10/08 14:07:01 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_stop(t_data *data)
{
	int	stop;

	pthread_mutex_lock(&data->mutex_stop);
	stop = data->stop;
	pthread_mutex_unlock(&data->mutex_stop);
	return (stop);
}

void	mutex_printf(t_data *data, t_philo *philo, char *str)
{
	pthread_mutex_lock(&data->mutex_printf);
	if (!check_stop(data))
	{
		printf("%ld %d %s\n", get_current_time() - data->start_time, philo->id,
			str);
	}
	pthread_mutex_unlock(&data->mutex_printf);
}

int	lock_odd(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->fork[philo->id % data->nb]));
	pthread_mutex_lock(&data->mutex_printf);
	if (!data->stop)
	{
		printf("%ld %d %s", get_current_time() - data->start_time, philo->id,
			"has taken the left fork\n");
	}
	else
	{
		unlock_lock(data, philo);
		return (0);
	}
	pthread_mutex_unlock(&data->mutex_printf);
	pthread_mutex_lock(&(data->fork[(philo->id - 1) % data->nb]));
	pthread_mutex_lock(&data->mutex_printf);
	if (!data->stop)
		printf("%ld %d %s", get_current_time() - data->start_time, philo->id,
			"has taken the right fork\n");
	else
	{
		pthread_mutex_unlock(&data->mutex_printf);
		return (0);
	}
	pthread_mutex_unlock(&data->mutex_printf);
	return (1);
}

int	lock_even(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->fork[(philo->id - 1) % data->nb]));
	pthread_mutex_lock(&data->mutex_printf);
	if (!data->stop)
		printf("%ld %d %s", get_current_time() - data->start_time, philo->id,
			"has taken the right fork\n");
	else
	{
		unlock_lock(data, philo);
		return (0);
	}
	pthread_mutex_unlock(&data->mutex_printf);
	pthread_mutex_lock(&(data->fork[philo->id % data->nb]));
	pthread_mutex_lock(&data->mutex_printf);
	if (!data->stop)
		printf("%ld %d %s", get_current_time() - data->start_time, philo->id,
			"has taken the left fork\n");
	else
	{
		pthread_mutex_unlock(&data->mutex_printf);
		return (0);
	}
	pthread_mutex_unlock(&data->mutex_printf);
	return (1);
}

void	unlock_lock(t_data *data, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&data->mutex_printf);
		pthread_mutex_lock(&(data->fork[(philo->id - 1) % data->nb]));
	}
	else
	{
		pthread_mutex_unlock(&data->mutex_printf);
		pthread_mutex_lock(&(data->fork[philo->id % data->nb]));
	}
}
