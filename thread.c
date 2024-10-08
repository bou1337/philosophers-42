#include "philo.h"

void *routine(void *arg)
{
  //  long time  ;
    t_philo *philo = (t_philo *)arg;
    t_data *data = philo->data; 
    
while(1)
{
       if(check_stop(data)) 
       return NULL  ;
      
        if(!printf_status(data, philo))
        return NULL ;
        usleep(500) ;
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
    return 0 ;
    }




