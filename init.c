#include "philo.h"

int ft_init(t_philo *philo, t_time *data, int num)
{
    int i;

    i = 0;
    while (i < num)
    {
        ft_data_philo(i, philo, data);
        if (pthread_create(&philo[i].thread, NULL, ft_pid, &philo[i]) != 0)
            return(ft_print("p_create"), EXIT_FAILURE);
        i++;
    }
    i = 0;
    while (i < num)
    {
        if (pthread_join(philo[i].thread, NULL) != 0)
        return(ft_print("p_join"), EXIT_FAILURE);
        i++;
    }
    return (0);
}

int ft_mutex_init(int num, t_time *data)
{
    int i;

    i = 0;
    data->fork = malloc(sizeof(pthread_mutex_t) * num);
    if (data->fork == NULL)
        return(ft_print("malloc"), EXIT_FAILURE);
    if (pthread_mutex_init(&data->print, NULL) != 0)
        return(ft_print("mutex_init"), EXIT_FAILURE);
    if (pthread_mutex_init(&data->n_eat_mutex, NULL) != 0)
        return(ft_print("mutex_init"), EXIT_FAILURE);
    if (pthread_mutex_init(&data->lock, NULL) != 0)
        return(ft_print("mutex_init"), EXIT_FAILURE); 
    while (i < num)
    {
        if (pthread_mutex_init(&data->fork[i], NULL) != 0)
            return(ft_print("mutex_init"), EXIT_FAILURE);
        i++;
    }  
    return (0);
}