#include "philo.h"

int ft_routine_help(t_philo *philo, int id)
{
    if(philo->dead_check == 1 || philo->data->dead == 1)
        return(1);
    pthread_mutex_lock(philo->l_fork);
    pthread_mutex_lock(&philo->data->print);
    printf("philo n = %d took a l_fork\n", id);
    pthread_mutex_unlock(&philo->data->print);
    // if (philo->data->philo == 1)
    // {
    //     pthread_mutex_unlock(philo->l_fork);
    //     return (1);
    // }
    pthread_mutex_lock(philo->r_fork);
    pthread_mutex_lock(&philo->data->print);
    printf("philo n = %d took a r_fork\n", id);
    pthread_mutex_unlock(&philo->data->print);
    return (0);
}

void *ft_routine(void *arg) 
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while(1)
    {
        if (ft_routine_help(philo, philo->id) == 1)
            return (NULL);
        pthread_mutex_lock(&philo->data->lock);
        philo->last_meal = get_current_time();
        pthread_mutex_unlock(&philo->data->lock);
        usleep(philo->data->time_to_eat);
        pthread_mutex_lock(&philo->data->print);
        ft_print(philo, "eating", 1,philo->data->time_to_eat);
        pthread_mutex_unlock(&philo->data->print);
        pthread_mutex_lock(&philo->data->meals);
        philo->nb_of_meals++;
        pthread_mutex_unlock(&philo->data->meals);
        pthread_mutex_unlock(philo->l_fork);
        pthread_mutex_unlock(philo->r_fork);
        ft_print(philo, "slepping", 1,philo->data->time_to_sleep);
        usleep(philo->data->time_to_sleep);
        printf("philo number %d is thinking\n",philo->id);
        usleep(5000);
    }
    return (NULL);
}

