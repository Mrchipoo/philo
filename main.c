#include "philo.h"

bool ft_check(int i)
{
    if (i % 2 == 0)
        return (false);
    return (true);
}

int ft_philo(t_philo *g)
{
    //create function that set at true or false for each philo in the array,done.
    // if true take fork and eat
    //if false sleep or think
    //create function that change true to false and the opposite so other philo can eat
    //
    // 
    g->fork = ft_check(g->id);
    printf("philo number %d your fork is %d\n",g->id,g->fork);
    return (EXIT_SUCCESS);
}

void ft_data(char **argv, t_time *data)
{
    data->philo = atoi(argv[1]);
    data->die = atoi(argv[2]);
    data->eat = atoi(argv[3]);
    data->sleep = atoi(argv[4]);
    data->die_eat = atoi(argv[5]);
    data->fork = data->philo;
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

int main (int argc, char **argv)
{
    t_time data;
    t_philo philo;
    int i;
    pthread_t *test;

    i = 0;
    if (argc >= 6)
    {
        ft_data(argv, &data);
        test = malloc(sizeof(test) * data.philo);
        philo.id = i;
        while (i < data.philo)
        {
            if (pthread_create(&test[i], NULL, ft_pid, (void*)&philo) != 0)
            {
                write(2, "error with p_create\n", 21);
                return (EXIT_FAILURE);
            }
            i++;
            philo.id = i;
            printf("id = %d\n",philo.id);
        }
        i = 0;
        while (i < data.philo)
        {
            if (pthread_join(test[i], NULL) != 0)
            {
                write(2, "error with p_join\n", 19);
                return (EXIT_FAILURE);
            }
            i++;
        }
        printf ("main\n");
    }
    else
      write(2, "pls enter a number\nexample ./a.out 10 10 10 10 10\n", 51);
    return (0);
}