#include "philo.h"

void    ft_check(int i, t_philo *philo)
{
    int k;
    int j;

    k = ft_min(i, (i + 1) % philo->data->philo);
    j = ft_max(i, (i + 1) % philo->data->philo);
    philo[i].l_fork = &philo->data->fork[k];
    philo[i].r_fork = &philo->data->fork[j];
}

void    ft_print(t_philo *philo, char *s, int i, size_t time_to)
{
    if (i == 0)
        printf("Error with %s\n",s);
    else if (i == 1)
    {
        printf("%zu philo number = %d is %s\n",philo->data->time,philo->id,s);
        philo->data->time += time_to;
    }
}

int ft_min(int i, int j)
{
    if (i <= j)
        return (i);
    return (j);
}

int ft_max(int i, int j)
{
    if (i >= j)
        return (i);
    return (j);
}

size_t  get_current_time(void)
{
	static struct timeval	time;
     struct timeval	now;
    static int flag;
    if (flag == 0)
    {
       if (gettimeofday(&time, NULL) == -1)
		    write(2, "gettimeofday() error\n", 22);
        flag = 1;
    }
	if (gettimeofday(&now, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return ((now.tv_sec - time.tv_sec)* 1000 + (now.tv_usec - time.tv_usec) / 1000);
}

void    ft_usleep(size_t time)
{
    usleep(time * 1000);
}