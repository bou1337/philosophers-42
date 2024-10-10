/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 05:46:08 by iait-bou          #+#    #+#             */
/*   Updated: 2024/10/10 05:46:12 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unlock(t_data *data, t_philo *philo)
{
	pthread_mutex_unlock(&(data->fork[philo->id % data->nb]));
	pthread_mutex_unlock(&(data->fork[(philo->id - 1) % data->nb]));
}
