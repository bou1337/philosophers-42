/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:16:29 by iait-bou          #+#    #+#             */
/*   Updated: 2024/10/12 02:08:05 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	printf_status(t_data *data, t_philo *philo)
{
	if (philo->id % 2 == 0)
		lock_odd(data, philo);
	else
	{
		usleep(500);
		lock_even(data, philo);
	}
	pthread_mutex_lock(&data->mutex_last_eat);
	philo->last_eat = get_current_time();
	pthread_mutex_unlock(&data->mutex_last_eat);
	if (!check_stop(data))
		mutex_printf(data, philo, "is eating");
	pthread_mutex_lock(&data->mutex_count_meal);
	if (data->arg_6)
		data->count_meal++;
	pthread_mutex_unlock(&data->mutex_count_meal);
	ft_usleep(data->time_eat);
	unlock(data, philo);
	if (!check_stop(data))
		mutex_printf(data, philo, "is sleeping");
	ft_usleep(data->time_sleep);
	if (!check_stop(data))
		mutex_printf(data, philo, "is thinking");
	return (1);
}

int	chek_death_full(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		if (!check_death(data, i))
		{
			return (0);
		}
		if (!check_full(data))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_full(t_data *data)
{
	pthread_mutex_lock(&data->mutex_count_meal);
	if (data->arg_6)
	{
		if (data->count_meal >= (size_t)data->must_eat * (size_t)data->nb)
		{
			pthread_mutex_lock(&data->mutex_printf);
			pthread_mutex_lock(&data->mutex_stop);
			data->stop = 1;
			pthread_mutex_unlock(&data->mutex_stop);
			ft_usleep(data->time_eat);
			pthread_mutex_unlock(&data->mutex_printf);
			pthread_mutex_unlock(&data->mutex_count_meal);
			return (0);
		}
	}
	pthread_mutex_unlock(&data->mutex_count_meal);
	return (1);
}

int	check_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->mutex_last_eat);
	if (get_current_time() - data->philo[i].last_eat > data->time_die)
	{
		pthread_mutex_lock(&data->mutex_printf);
		pthread_mutex_lock(&data->mutex_stop);
		data->stop = 1;
		pthread_mutex_unlock(&data->mutex_stop);
		printf("%ld %d died\n", get_current_time() - data->start_time,
			data->philo[i].id);
		pthread_mutex_unlock(&data->mutex_printf);
		pthread_mutex_unlock(&data->mutex_last_eat);
		return (0);
	}
	pthread_mutex_unlock(&data->mutex_last_eat);
	return (1);
}
