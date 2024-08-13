#include "philo.h"

int check_dead(t_philo *philo, size_t time)
{
    pthread_mutex_lock(&philo->data->lock);
    if (get_current_time() - philo->last_meal >= time)
    {
        pthread_mutex_unlock(&philo->data->lock);
        return (1);
    }
    pthread_mutex_unlock(&philo->data->lock);
    return (0);
}

int ft_dead(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->data->philo)
    {
        if (check_dead(&philo[i], philo->data->time_to_die) == 1)
        {
            printf("philo n = %d is dead\n", philo[i].id);
            pthread_mutex_lock(&philo[i].data->lock);
            philo[i].dead_check = 1;
            pthread_mutex_unlock(&philo[i].data->lock);
            return 1;
        }
        i++;
    }
    return 0;
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
        return  1;
    }
    return 0;
}

void ft_monitor(t_philo *philo)
{
    while (1)
    {
        if (ft_dead(philo) == 1 || ft_full(philo) == 1)
            break ;
    }
    //printf()
    return ;
}