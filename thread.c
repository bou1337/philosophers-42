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

    while (1)
    {
      printf_status(data, philo) ;
      
      usleep(500) ;
      
    }

    return NULL;
}
int create_thread(t_data *data)
{
    int i = 0 ;
    while(i<data->nb)
    {
        pthread_create(&(data->philo[i].thread), NULL, &routine,&(data->philo[i]));
        i++;
    }

   while(chek_death_full(data))
   {
    usleep(500);
   }
    int j = 0 ;

  while(j<data->nb)
    {
        pthread_detach(data->philo[j].thread) ;
        j++;
    }
    usleep(500000);
    return 0 ;
}