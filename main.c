#include "philo.h"

int  main(int ac, char **av)
{
    t_data data ;
    if(!check_arg(ac, av))
    return (0);
    init_philo(&data, ac,av);
    init_mutex(&data);
    //printf("HOLA\n");
    if(!create_thread(&data))
    return 0 ;
    //while(chek_death_full(&data));
    return (0) ;
}