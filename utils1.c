#include "philo.h"

long get_current_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int printf_status(t_data *data, t_philo *philo)
{
    if (pthread_mutex_lock(&(data->fork[philo->id % data->nb])) != 0)
        return 0;
  pthread_mutex_lock(&data->mutex);
  printf("%ld  %d  %s",get_current_time() - data->start_time,philo->id, "has taken the right fork\n" );
  pthread_mutex_unlock(&data->mutex);

    if (pthread_mutex_lock(&(data->fork[(philo->id - 1) % data->nb])) != 0)
        return 0;
     pthread_mutex_lock(&data->chek_time);
    long time  = get_current_time();
    philo->last_eat = time;
    pthread_mutex_unlock(&data->chek_time);
    pthread_mutex_lock(&data->mutex);
    printf("%ld  %d  %s", time - data->start_time,philo->id, "has taken the left fork\n" );
    printf("%ld  %d  %s",time - data->start_time,philo->id, "is eating\n" );
    pthread_mutex_unlock(&data->mutex);
    if(data->arg_6)
    data->count_meal ++ ;
   ft_usleep(data->time_eat);
    if (pthread_mutex_unlock(&(data->fork[philo->id % data->nb])) != 0)
        return 0;
    if (pthread_mutex_unlock(&(data->fork[(philo->id - 1) % data->nb])) != 0)
        return 0;
     pthread_mutex_lock(&data->mutex);
      printf("%ld  %d  %s",get_current_time() - data->start_time,philo->id, "is sleeping\n" );
      pthread_mutex_unlock(&data->mutex);
    ft_usleep(data->time_sleep);
     pthread_mutex_lock(&data->mutex);
    printf("%ld  %d  %s",get_current_time()- data->start_time,philo->id, "is thinking\n" );
    pthread_mutex_unlock(&data->mutex);
    return 1;
}

int chek_death_full(t_data *data)
{
    int i ;
    i = 0; 
    while(i<data->nb)
    {
        if(data->arg_6)
        if(data->count_meal ==(size_t)data->must_eat*(size_t)data->nb)
        {    

             pthread_mutex_lock(&data->mutex) ;
             printf("all philosophers are full\n") ;
             return 0 ;
        }
        pthread_mutex_lock(&data->chek_time);
        if(get_current_time() - data->philo[i].last_eat > data->time_die)
        {
            pthread_mutex_lock(&data->mutex);
            printf("%ld  %d  is die\n",get_current_time() - data->start_time ,data->philo[i].id);
            return (0);

        }
        pthread_mutex_unlock(&data->chek_time);
        
        i++;
    }
    return (1) ;
}