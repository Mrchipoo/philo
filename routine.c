#include "philo.h"

int ft_routine_help(t_philo *philo, int id)
{
    if(philo->full_check == 1 || philo->data->dead == 1)
        return (1);
    pthread_mutex_lock(philo->l_fork);
    pthread_mutex_lock(&philo->data->print);
    if (philo->data->dead == 0)
        printf("%zu philo number = %d took a l_fork\n", philo->data->time, id);
    pthread_mutex_unlock(&philo->data->print);
    if (philo->data->philo > 1)
    {
        pthread_mutex_lock(&philo->data->lock);
        philo->last_meal = get_current_time();
        pthread_mutex_unlock(&philo->data->lock);
        pthread_mutex_lock(philo->r_fork);
        pthread_mutex_lock(&philo->data->print);
        if (philo->data->dead == 0)
            printf("%zu philo number = %d took a r_fork\n", philo->data->time, id);
        pthread_mutex_unlock(&philo->data->print);
        return (0);
    }
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
    return (1);
}

void *ft_routine(void *arg) 
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while(1)
    {
        if (ft_routine_help(philo, philo->id) == 1)
            return (NULL);
        ft_usleep(philo->data->time_to_eat);
        pthread_mutex_lock(&philo->data->print);
        if (philo->data->dead == 0)
            ft_print(philo, "eating", 1, philo->data->time_to_eat);
        pthread_mutex_unlock(&philo->data->print);
        pthread_mutex_unlock(philo->l_fork);
        pthread_mutex_unlock(philo->r_fork);
        pthread_mutex_lock(&philo->data->meals);
        philo->nb_of_meals++;
        pthread_mutex_unlock(&philo->data->meals);
        if (philo->data->dead == 0)
            ft_print(philo, "slepping", 1, philo->data->time_to_sleep);
        ft_usleep(philo->data->time_to_sleep);
        // if (philo->full_check == 0)
        // {
        //     ft_usleep(200);
        //     ft_print(philo, "thinking", 1, 200);
        // }
    }
    return (NULL);
}