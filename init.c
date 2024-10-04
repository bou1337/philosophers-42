#include "philo.h"

void init_philo(t_data *data,int ac ,char **av)
{
    data->nb = ft_atoil(av[1]);
    data->time_die = ft_atoil(av[2]);
    data->time_eat = ft_atoil(av[3]);
    data->time_sleep = ft_atoil(av[4]);
    data->start_time = get_current_time();
    data->philo = malloc(sizeof(t_philo)*data->nb);
    data->fork = malloc(sizeof(pthread_mutex_t)*data->nb);
    data->count_meal = 0 ;
    data->arg_6 = 0;
   
    if(ac == 6)
    {
        data->arg_6 =1;
        data->must_eat = ft_atoil(av[5]);
    }
    int i = 0 ;
    while(i<data->nb)
    {
        data->philo[i].id= i+1;
        data->philo[i].data = data ;
        data->philo[i].last_eat =get_current_time();
        i++;
    }
}

void init_mutex(t_data *data)
{
    int  i = 0; 
     pthread_mutex_init(&(data->mutex_printf), NULL) ;
    pthread_mutex_init(&(data->mutex_count_meal),NULL) ;
    pthread_mutex_init(&(data->mutex_last_eat), NULL) ;
    while(i<data->nb)
    {
        pthread_mutex_init(&(data->fork[i]),NULL) ;
        i++;
    }

}

