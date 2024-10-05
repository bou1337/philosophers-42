#include "philo.h"

void *routine(void *arg)
{
    long time  ;
    t_philo *philo = (t_philo *)arg;
    t_data *data = philo->data; 

    if (philo->id % 2 != 0)
    {
        time = get_current_time();
        printf("%ld  %d  is thinking\n",time -data->start_time, philo->id);
         usleep(1000);
    }
while(1)
{
        pthread_mutex_lock(&data->mutex_stop);
        if(data->stop == 1)
        {
        printf("HOOOOOO\n") ;
         pthread_mutex_unlock(&data->mutex_stop) ;

        return NULL ;
        }
        pthread_mutex_unlock(&data->mutex_stop) ;
        printf_status(data, philo) ;
        pthread_mutex_lock(&data->mutex_stop);
         pthread_mutex_unlock(&data->mutex_stop) ;
}
    return NULL;
}
int create_thread(t_data *data)
{
    int i = 0 ;
        i = 0;
    while(i<data->nb)
    {
        pthread_create(&(data->philo[i].thread), NULL, &routine,&(data->philo[i]));
        i++;
    }

   while(chek_death_full(data)) 
   {

   }

    int j = 0 ;

  while(j<data->nb)
    {
        pthread_join(data->philo[j].thread, NULL) ;
        j++;
    }
    //usleep(500000);
    return 0 ;
    }
