#include "philo.h"

int ft_init(t_philo *philo, t_time *data, int num)
{
    int i;

    i = 0;
    while (i < num)
    {
        ft_data_philo(i, philo, data);
        if (pthread_create(&philo[i].thread, NULL, ft_pid, &philo[i]) != 0)
        {
            write(2, "Error with p_create\n", 21);
            return (EXIT_FAILURE);
        }
        i++;
    }
    i = 0;
    while (i < num)
    {
        if (pthread_join(philo[i].thread, NULL) != 0)
        {
            write(2, "Error with p_join\n", 19);
            return (EXIT_FAILURE);
        }
        i++;
    }
    return (0);
}

int ft_mutex_init(t_philo *philo, int num)
{
    
}