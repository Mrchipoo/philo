#include "philo.h"

void ft_check(int i, t_philo *philo)
{
    int k;
    int j;

    k = ft_min(i, (i + 1) % philo->data->philo);
    j = ft_max(i, (i + 1) % philo->data->philo);
    philo[i].l_fork = &philo->data->fork[k];
    philo[i].r_fork = &philo->data->fork[j];
}

void ft_print(char *s)
{
    printf("Error with %s\n",s);
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