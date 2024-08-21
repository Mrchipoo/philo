#include "philo.h"

int checker(char **argv, int argc)
{
    int a;
    int i;

    i = 1;
    while (i < argc)
    {
        a = ft_atoi(argv[i]);
        if (i == 1 && a == 0)
            return(EXIT_FAILURE);
        if (a == -1)
            return (EXIT_FAILURE);
        i++;
    }
    return (EXIT_SUCCESS);
}
