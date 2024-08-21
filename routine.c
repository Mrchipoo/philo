#include "philo.h"

int not_dead(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->dead_lock);
    if (philo->data->dead == 1 || philo->dead_check == 1)
    {
        pthread_mutex_unlock(&philo->data->dead_lock);
        return (1);
    }
    pthread_mutex_unlock(&philo->data->dead_lock);
    return (0);
}

int ft_routine_help(t_philo *philo, int id)
{
    pthread_mutex_lock(philo->l_fork);
    if (!not_dead(philo))
        printf("%zu philo number = %d took a l_fork\n", get_current_time(), id);
    if (philo->data->philo == 1)
    {
        ft_usleep(philo->data->time_to_die);
        pthread_mutex_unlock(philo->l_fork);
        return (1);
    }
    pthread_mutex_lock(philo->r_fork);
    if (!not_dead(philo))
        printf("%zu philo number = %d took a r_fork\n", get_current_time(), id);
    return (0);
}

void *ft_routine(void *arg) 
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (!not_dead(philo))
    {
        if (ft_routine_help(philo, philo->id) == 1)
            return (NULL);
        if (!not_dead(philo))
            ft_print(philo, "eating", 1);
        pthread_mutex_lock(&philo->data->timer);
        philo->last_meal = get_current_time();
        pthread_mutex_lock(&philo->data->meals);
        philo->nb_of_meals++;
        pthread_mutex_unlock(&philo->data->meals);
        pthread_mutex_unlock(&philo->data->timer);
        ft_usleep(philo->data->time_to_eat);
        pthread_mutex_unlock(philo->r_fork);
        pthread_mutex_unlock(philo->l_fork);
        if (!not_dead(philo))
            ft_print(philo, "slepping", 1);
        ft_usleep(philo->data->time_to_sleep);
        if (!not_dead(philo))
            ft_print(philo, "Thinking", 1);
        ft_usleep(10);
    }
    return (NULL);
}