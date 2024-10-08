
#include "philo.h"

int  check_stop(t_data *data )
{

    int stop  ;

    pthread_mutex_lock(&data->mutex_stop) ;
    stop  = data->stop ;
    pthread_mutex_unlock(&data->mutex_stop) ;
    return stop ;
}

void mutex_printf(t_data *data,t_philo *philo,  char *str)
{
    pthread_mutex_lock(&data->mutex_printf) ;
     printf("%ld %d %s\n", get_current_time() - data->start_time, philo->id,str);
    pthread_mutex_unlock(&data->mutex_printf) ;
}

void lock_odd(t_data *data ,t_philo *philo)
{
    pthread_mutex_lock(&(data->fork[philo->id % data->nb])); 
        if (check_stop(data))
        mutex_printf(data,philo,  "has taken the left fork");
        pthread_mutex_lock(&(data->fork[(philo->id - 1) % data->nb]));
        if (!check_stop(data))
        mutex_printf(data,philo,  "has taken the right fork");
}

int lock_even(t_data *data , t_philo *philo)
{
    
     pthread_mutex_lock(&(data->fork[(philo->id - 1) % data->nb]));
        if (!check_stop(data))
        mutex_printf(data,philo,  "has taken the right fork") ;
    if(data->nb==1)
    {
      return 0;
    }
        pthread_mutex_lock(&(data->fork[philo->id % data->nb])); 
        if (!check_stop(data))
        mutex_printf(data,philo,  "has taken the left fork") ;
    return 1 ;

}

