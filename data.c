#include "philo.h"

void ft_data(int argc, char **argv, t_time *data)
{
    data->philo = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);// in microseconds
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        data->max_meals = ft_atoi(argv[5]);
    else if (argc == 5)
        data->max_meals = -1;
    data->dead = 0;
    data->time = 0;
}

void ft_data_philo(int i, t_philo *philo, t_time *data)
{
    philo[i].id = i;
    philo[i].data = data;
    philo[i].nb_of_meals = 0;
    ft_check(i, philo);
    philo[i].dead_check = 0;
    philo[i].last_meal = get_current_time();
}