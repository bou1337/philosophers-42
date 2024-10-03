#include "philo.h"

long get_current_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int printf_status(t_data *data, t_philo *philo)
{
  pthread_mutex_lock(&(data->fork[(philo->id-1)% data->nb]));
  pthread_mutex_lock(&data->mutex_printf);
  printf("%ld  %d  %s",get_current_time() - data->start_time,philo->id, "has taken the right fork\n" );
  pthread_mutex_unlock(&data->mutex_printf);
  pthread_mutex_lock(&(data->fork[(philo->id ) % data->nb])) ;
  long time  = get_current_time();
  pthread_mutex_lock(&data->mutex_last_eat) ;
  philo->last_eat = time;
  pthread_mutex_unlock(&data->mutex_last_eat);
    pthread_mutex_lock(&data->mutex_printf);
    printf("%ld  %d  %s", time - data->start_time,philo->id, "has taken the left fork\n" );
    printf("%ld  %d  %s",time - data->start_time,philo->id, "is eating\n" );
    pthread_mutex_unlock(&data->mutex_printf);
    pthread_mutex_lock(&data->mutex_count_meal) ;
    if(data->arg_6)
    data->count_meal ++;
    pthread_mutex_unlock(&data->mutex_count_meal) ;
    ft_usleep(data->time_eat);
    pthread_mutex_unlock(&(data->fork[(philo->id ) % data->nb])) ;
    pthread_mutex_unlock(&(data->fork[(philo->id -1)% data->nb])) ;
    pthread_mutex_lock(&data->mutex_printf);
    printf("%ld  %d  %s",get_current_time() - data->start_time,philo->id, "is sleeping\n" );
    pthread_mutex_unlock(&data->mutex_printf);
    ft_usleep(data->time_sleep);
    pthread_mutex_lock(&data->mutex_printf);
    printf("%ld  %d  %s",get_current_time()- data->start_time,philo->id, "is thinking\n" );
    pthread_mutex_unlock(&data->mutex_printf);
    return 1;
}

int chek_death_full(t_data *data)
{
    int i ;
    i = 0; 
    while(i<data->nb)
    {
        pthread_mutex_lock(&data->mutex_count_meal) ;
        if(data->arg_6)
        if(data->count_meal ==(size_t)data->must_eat*(size_t)data->nb)
        {    

             pthread_mutex_lock(&data->mutex_printf) ;
            // free(data->philo) ;
             //free (data->fork) ;
             printf("all philosophers are full\n") ;
             //data->stop = 0;
            //m pthread_mutex_unlock(&data->mutex_printf) ;
             return 0 ;
        }
        pthread_mutex_unlock(&data->mutex_count_meal) ;
        pthread_mutex_lock(&data->mutex_last_eat);
        if(get_current_time() - data->philo[i].last_eat > data->time_die)
        {
            pthread_mutex_lock(&data->mutex_printf);
            printf("%ld  %d  is die\n",get_current_time() - data->start_time ,data->philo[i].id);
            //free(data->philo) ;
            //free (data->fork) ;
           // pthread_mutex_unlock(&data->mutex_printf);
            return (0);
        }
        pthread_mutex_unlock(&data->mutex_last_eat);
        
        i++;
    }
    return (1) ;
}