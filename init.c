#include "philo.h"

int ft_init(t_philo *philo, t_time *data, int num)
{
    int i;

    i = 0;
    while (i < num)
    {
        ft_data_philo(i, philo, data);
        if (pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]) != 0)
            return(ft_print(NULL,"p_create",0,0), EXIT_FAILURE);
        usleep(10);
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
        return(ft_print(NULL,"malloc",0,0), EXIT_FAILURE);
    if (pthread_mutex_init(&data->print, NULL) != 0)
        return(ft_print(NULL,"mutex_init",0,0), EXIT_FAILURE);
    if (pthread_mutex_init(&data->meals, NULL) != 0)
        return(ft_print(NULL,"mutex_init",0,0), EXIT_FAILURE);
    if (pthread_mutex_init(&data->lock, NULL) != 0)
        return(ft_print(NULL,"mutex_init",0,0), EXIT_FAILURE);
    if (pthread_mutex_init(&data->dead_lock, NULL) != 0)
        return(ft_print(NULL,"mutex_init",0,0), EXIT_FAILURE);
    if (pthread_mutex_init(&data->monitor, NULL) != 0)
        return(ft_print(NULL,"mutex_init",0,0), EXIT_FAILURE);
    if (pthread_mutex_init(&data->checker, NULL) != 0)
        return(ft_print(NULL,"mutex_init",0,0), EXIT_FAILURE);
    while (i < num)
    {
        if (pthread_mutex_init(&data->fork[i], NULL) != 0)
            return(ft_print(NULL,"mutex_init",0,0), EXIT_FAILURE);
        i++;
    }  
    return (0);
}

int ft_mutex_join(t_time data, t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->data->philo)
    {
        if (pthread_join(philo[i].thread, NULL) != 0)
            return(ft_print(NULL, "p_join",0,0), EXIT_FAILURE);
        i++;
    }
    pthread_mutex_destroy(&data.print);
    pthread_mutex_destroy(&data.meals);
    pthread_mutex_destroy(&data.lock);
    pthread_mutex_destroy(&data.dead_lock);
    pthread_mutex_destroy(&data.monitor);
    pthread_mutex_destroy(&data.checker);
    free(data.fork);
    free(philo);
    return (0);
}