#include "philo.h"

int  main(int ac, char **av)
{
    t_data data ;
    //int i = 0;
    if(!check_arg(ac, av))
    return (0);
    if(!init_philo(&data, ac,av))
    {
        put_str("ERORR: init error", 2);
        return 0;
    }
    if(!init_mutex(&data))
    {
        put_str("EROOR: error with init mutex", 2) ;
    }

    if(!create_thread(&data))
    return (0) ;
    return 1 ;
}