#include "philo.h"

int  main(int ac, char **av)
{
    t_data data ;
    if(!check_arg(ac, av))
    return (0);
    init_philo(&data, ac,av);
    init_mutex(&data);
    if(!create_thread(&data))
    return 0 ;
    return (0) ;
}