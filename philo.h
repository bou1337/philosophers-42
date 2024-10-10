/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:08:54 by iait-bou          #+#    #+#             */
/*   Updated: 2024/10/08 14:27:54 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_t		chek_death;
	long			last_eat;
	struct s_data	*data;

}					t_philo;

typedef struct s_data
{
	int				nb;
	size_t			count_meal;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	long			start_time;
	int				arg_6;
	int				must_eat;
	int				stop;
	pthread_mutex_t	*fork;
	pthread_mutex_t	mutex_printf;
	pthread_mutex_t	mutex_count_meal;
	pthread_mutex_t	mutex_last_eat;
	pthread_mutex_t	mutex_stop;
	t_philo			*philo;
}					t_data;

int					is_number(char *str);
// int					check_arg(int ac, char **av);
void				put_str(char *str, int fd);
void				error_in_arg(int i);
long				ft_atoil(char *str);
int					chek_max_int(char *av[]);
void				init_philo(t_data *data, int ac, char **av);
void				init_mutex(t_data *data);
void				*routine(void *arg);
int					create_thread(t_data *data);
int					printf_status(t_data *data, t_philo *philo);
long				get_current_time(void);
/// int check_death( t_data *data);
void				ft_usleep(int ms);
void				print_status(long time, char *message, long id);
int					chek_death_full(t_data *data);
int					check_stop(t_data *data);
void				mutex_printf(t_data *data, t_philo *philo, char *str);
// void mutex_printf(t_data **data, t_philo **philo, char *str) ;
int					lock_odd(t_data *data, t_philo *philo);
int					lock_even(t_data *data, t_philo *philo);
int					check_full(t_data *data);
int					check_death(t_data *data, int i);
void				unlock(t_data *data, t_philo *philo);
void				unlock_lock(t_data *data, t_philo *philo);

#endif
