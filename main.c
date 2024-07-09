#include "philo.h"

int main (int argc, char **argv)
{
    t_time data;
    t_philo *philo;


    if (argc >= 6)
    {
        ft_data(argv, &data);
        philo = malloc(sizeof(t_philo) * data.philo);
        if (philo == NULL)
            return (ft_print("malloc"), EXIT_FAILURE);
        if (ft_mutex_init(data.philo, &data) == 1)
            return (ft_print("mutex_init"), EXIT_FAILURE);
        if (ft_init(philo, &data, data.philo) == 1)
            return (ft_print("philo_init"), EXIT_FAILURE);
        free(data.fork);
        free(philo);
    }
    else
      write(2, "pls enter a number\nexample ./a.out 10 10 10 10 10\n", 51);
    return (0);
}