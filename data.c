#include "philo.h"

void ft_data(char **argv, t_time *data)
{
    data->philo = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    data->max_meals = ft_atoi(argv[5]);
}

void ft_data_philo(int i, t_philo *philo, t_time *data)
{
    philo[i].id = i;
    philo[i].data = data;
    philo[i].n_eat = 0;
    ft_check(i, philo);
    philo[i].dead = 0;
}