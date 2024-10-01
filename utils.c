#include "philo.h"
#include <unistd.h>

void put_str(char *str, int fd)
{
    int len = 0;

    while (str[len])
        len++;  

    write(fd, str, len);
}

int is_number(char *str)
{
    int i = 0;
    if(!str[i])
    return (0);
    while(str[i]&&((str[i]>=9&& str[i]<=13)|| str[i]==' '))
    i++;
    if(str[i]=='+')
    i++;
    if(!str[i])
    return (0);
    while(str[i]&&(str[i]<='9'&& str[i]>='0'))
    i++;
    while(str[i]&&((str[i]>=9&& str[i]<=13)|| str[i]==' '))
    i++;
    if(!str[i])
    return 1;
    else return 0;
}

void error_in_arg(int i)
{
    if(i==1)
    put_str("ERROR: mistake in number_of_philosophers\n", 2);
    else if(i==2)
    put_str("ERROR :mistake in  time_to_die\n", 2);
    else if(i==3)
        put_str("ERROR ;mistake in time_to_eat\n", 2);
    else if(i==4)
    put_str("ERROR: mistake in time_to_sleep\n", 2);
    else 
    put_str ("ERROR: mistake in number_of_times_each_philosopher_must_eat\n", 2);
    
}

int check_arg(int ac,char **av)
{
    if(ac==6|| ac ==5)
    {
    int i = 1;
    while(av[i])
    {
        if(!is_number(av[i]))
        {
            error_in_arg(i);
            return (0);
        }
        i++;
    }
    if(!chek_max_int(av))
    return 0;
    return 1;
    }
    else
    {
        put_str("ERROR: The number of argments must be 5 or 6\n", 2);
        return 0 ;
    }

}
long ft_atoil(char *str)
{   
    long result = 0 ; 
    int i ;
    i = 0 ;
    while(str[i]&&((str[i]>=9 &&str[i]<=13)|| str[i]==' '))
    i++;
    if(str[i]=='+')
    i++;
    while(str[i]&&(str[i]>='0'&& str[i]<='9'))
    {
        result = result *10 + (str[i]-'0');
        i++;
    }
    return result ;
}
int  chek_max_int(char **av)
{
    int i ; 
    i = 1 ;
    while(av[i])
    {
        if(ft_atoil(av[i])>INT_MAX)
        {
        put_str("all the value must be  less than INT_MAX\n", 2);
        return 0 ;
        }
        i++;
    }
    i = 1 ; 
    while(av[i])
    {
        if(ft_atoil(av[i])== 0)
        {
        put_str("all value must be more than 0\n", 2) ;
        return 0 ;
        }
    i++ ;
    }
    
    return 1;
}
void ft_usleep(int ms)
{
    long start_time = get_current_time();
    while ((get_current_time() - start_time) < ms);
}