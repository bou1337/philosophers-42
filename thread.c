#include "philo.h"

void *routine(void *arg)
{
    long time  ;
    t_philo *philo = (t_philo *)arg;
    t_data *data = philo->data; 

    if (philo->id % 2 == 0)
    {
        time = get_current_time();
        printf("%ld  %d  is thinking\n",time -data->start_time, philo->id);
         usleep(1000);
    }

    while (1)
    {
      if(!printf_status(data, philo))
      {
      put_str("EROOR:pthread_mutex", 2);
      return NULL;
      }
      if(data->stop == 0)
      return NULL ;
      //usleep(200);
    }

    return NULL;
}int create_thread(t_data *data)
{
    int i = 0;

    // Create all the threads (philosophers)
   while (i < data->nb)
    {
        // Create a new thread for each philosopher
        pthread_create(&(data->philo[i].thread), NULL, &routine, &(data->philo[i]));
        i++;
    }

 while(i<data->nb)
    {
        pthread_join(data->philo[i].thread, NULL) ;
        i++ ;
    }

    //Check for death/fullness conditions
   while (chek_death_full(data))
    {
        //usleep(500);
    }

    // Join all the threads (wait for each philosopher's thread to complete)


    return 0;
}
