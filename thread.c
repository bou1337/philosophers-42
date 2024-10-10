/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:10:09 by iait-bou          #+#    #+#             */
/*   Updated: 2024/10/08 14:37:41 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (1)
	{
		if (check_stop(data))
			return (NULL);
		if (printf_status(data, philo) != 1)
			return (NULL);
		usleep(500);
	}
	return (NULL);
}

int	create_thread(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->nb)
	{
		pthread_create(&(data->philo[i].thread), NULL, &routine,
			&(data->philo[i]));
		i++;
	}
	while (chek_death_full(data))
	{
		usleep(10);
	}
	while (j < data->nb)
	{
		pthread_join(data->philo[j].thread, NULL);
		j++;
	}
	return (0);
}

void	ft_usleep(int ms)
{
	long	start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < ms)
		;
}
