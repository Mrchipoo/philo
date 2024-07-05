#include "philo.h"

void *ft_pid() 
{
    printf("thread pid is = %d\t ad = %p\n",getgid(), (void*)pthread_self());
}

int main (int argc, char **argv)
{
    int nb;
    int i;
    pthread_t *test;

    i = 0;
    if (argc >= 2)
    {
        nb = atoi(argv[1]);
        test = malloc(sizeof(test) * nb);
        while (i < nb)
        {
            if (pthread_create(&test[i], NULL, ft_pid, NULL) != 0)
            {
                write(2, "error with p_create\n", 21);
                return (EXIT_FAILURE);
            }
            i++;
        }
        i = 0;
        while (i < nb)
        {
        if (pthread_join(test[i], NULL) != 0)
            {
                write(2, "error with p_join\n", 21);
                return (EXIT_FAILURE);
            }
            i++;
        }
        printf ("main thread\n");
    }
    else
      write(2, "pls enter a number\n", 20);
    return (0);
}