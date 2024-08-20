#include "philo.h"

int check_dead(t_philo *philo, t_time *data)
{
    pthread_mutex_lock(&data->timer);
    if (get_current_time() - philo->last_meal >= data->time_to_die)
    {
        pthread_mutex_unlock(&data->timer);
        return (1);
    }
    pthread_mutex_unlock(&data->timer);
    return (0);
}

int ft_dead(t_philo *philo, t_time *data)
{
    int     i;

    i = 0;
    while (i < philo->data->philo)
    {
        pthread_mutex_lock(&data->monitor);
        if (check_dead(&philo[i], data) == 1)
        {
            if (data->philo == 1)
                printf("%zu philo number = %d is dead\n", get_current_time() + data->time_to_die, philo[i].id);
            else
                printf("%zu philo number = %d is dead\n", get_current_time(), philo[i].id);
            pthread_mutex_lock(&data->dead_lock);
            philo[i].dead_check = 1;
            philo->data->dead = 1;
            pthread_mutex_unlock(&data->dead_lock);
            pthread_mutex_unlock(&data->monitor);
            return (1);
        }
        pthread_mutex_unlock(&data->monitor);
        i++;
    }
    return (0);
}

int ft_full(t_philo *philo)
{
    int i;
    int finished;

    i = 0;
    finished = 0;
    while (i < philo->data->philo)
    {
        pthread_mutex_lock(&philo[i].data->monitor);
        if (philo[i].nb_of_meals >= philo->data->max_meals)
        {
            philo[i].full_check = 1;
            finished++;
        }
        pthread_mutex_unlock(&philo[i].data->monitor);
        i++;
    }
    if (finished >= philo->data->philo)
    {
        pthread_mutex_lock(&philo->data->dead_lock);
        philo->data->dead = 1;
        pthread_mutex_unlock(&philo->data->dead_lock);
        return  (1);
    }
    return (0);
}

void ft_monitor(t_philo *philo, t_time *data)
{
    if (data->max_meals != -1)
    {
        while (1)
        {
            if (ft_dead(philo,data) == 1 || ft_full(philo) == 1)
                break ;
        }
    }
    else if (data->max_meals == -1)
    {
        while (1)
        {
            if (ft_dead(philo,data) == 1)
                break ;
        }
    }
    return ;
}