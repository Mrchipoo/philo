#include "philo.h"

int check_dead(t_philo *philo, size_t time, t_time *data)
{
    size_t start;
    
    start = get_current_time();
    pthread_mutex_lock(&data->lock);
    // printf("start = %lu\n", start);
    // printf("last_meal = %lu\n", philo->last_meal);
    // printf("start - last_meal = %lu\n", start - philo->last_meal);
    if (start - philo->last_meal > time)//todo
    {
        pthread_mutex_unlock(&data->lock);
        return (1);
    }
    pthread_mutex_unlock(&data->lock);
    return (0);
}

int ft_dead(t_philo *philo, t_time *data)
{
    int i;

    i = 0;
    while (i < philo->data->philo)
    {
        pthread_mutex_lock(&data->meals);
        if (check_dead(&philo[i], data->time_to_die, data) == 1)
        {
            printf("philo n = %d is dead\n", philo[i].id);
            pthread_mutex_lock(&data->lock);
            philo[i].dead_check = 1;
            pthread_mutex_unlock(&data->lock);
            pthread_mutex_unlock(&data->meals);
            return (1);
        }
        pthread_mutex_unlock(&data->meals);
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
        pthread_mutex_lock(&philo[i].data->lock);
        if (philo[i].nb_of_meals >= philo->data->max_meals)
            finished++;
        pthread_mutex_unlock(&philo[i].data->lock);
        i++;
    }
    if (finished >= philo->data->philo)
    {
        pthread_mutex_lock(&philo->data->lock);
        philo->data->dead = 1;
        pthread_mutex_unlock(&philo->data->lock);
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