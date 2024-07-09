#include "philo.h"

void *ft_routine(void *arg) 
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while(1)
    {
        if(philo->dead == 1)
            return(NULL);
        if (philo->n_eat >= philo->data->max_meals)
        {
            pthread_mutex_lock(&philo->data->lock);
            printf("philo number %d is full\n",philo->id);
            pthread_mutex_unlock(&philo->data->lock);
            return(NULL);
        }
        pthread_mutex_lock(philo->l_fork);
        pthread_mutex_lock(philo->r_fork);
        pthread_mutex_lock(&philo->data->print);
        printf("philo number %d is eating\n",philo->id);
        usleep(philo->data->time_to_eat * 1000);
        philo->n_eat++;
        pthread_mutex_unlock(&philo->data->print);
        pthread_mutex_unlock(philo->l_fork);
        pthread_mutex_unlock(philo->r_fork);
        printf("philo number %d is sleeping\n",philo->id);
        usleep(philo->data->time_to_sleep * 1000);
        printf("philo number %d is thinking\n",philo->id);
        usleep(500);
    }
    return (NULL);
}

