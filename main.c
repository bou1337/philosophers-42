#include "philo.h"

int  main(int ac, char **av)
{

    t_data data ;
    if(!check_arg(ac, av))
    return (0);
    init_philo(&data, ac,av);
    init_mutex(&data);
    create_thread(&data) ;
    free(data.fork) ;
    free(data.philo);
    return (0) ;
}