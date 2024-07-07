#include "philo.h"

void ft_data_philo(int i, t_philo *philo, t_time *data)
{
    philo[i].id = i;
    philo[i].data = data;
    philo[i].n_eat = 0;
    philo[i].fork = ft_check(i);
}




void *ft_pid(void *philo) 
{
    t_philo *g;

    g = (t_philo *)philo;
    pthread_mutex_lock(&lock);
    ft_philo(g);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int ft_philo(t_philo *g)
{
    //create function that set at true or false for each philo in the array,done.
    // if true take fork and eat
    //if false sleep or think
    //create function that change true to false and the opposite so other philo can eat
    //
    // 
    printf("philo number %d your fork is %d\n",g->id,g->fork);
    return (EXIT_SUCCESS);
}

void ft_data(char **argv, t_time *data)
{
    data->philo = ft_atoi(argv[1]);
    data->die = ft_atoi(argv[2]);
    data->eat = ft_atoi(argv[3]);
    data->sleep = ft_atoi(argv[4]);
    data->die_eat = ft_atoi(argv[5]);
    data->fork = data->philo;
}


int main (int argc, char **argv)
{
    t_time data;
    t_philo *philo;


    if (argc >= 6)
    {
        ft_data(argv, &data);
        philo = malloc(sizeof(t_philo) * data.philo);
        if (philo == NULL)
            return (EXIT_FAILURE);
        //create mutex init
        if (ft_init(philo, &data, data.philo) == 1)
            return(EXIT_FAILURE);
        free(philo);
    }
    else
      write(2, "pls enter a number\nexample ./a.out 10 10 10 10 10\n", 51);
    return (0);
}