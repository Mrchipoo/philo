#include "philo.h"

void	ft_print(t_philo *philo, char *s, int i, size_t time_to)
{
	if (i == 0)
		printf("Error with %s\n", s);
	else if (i == 1)
	{
		i = philo->id;
		pthread_mutex_lock(&philo->data->print);
		printf("%zu philo number = %d is %s\n", philo->data->time, i, s);
		philo->data->time += time_to;
		pthread_mutex_unlock(&philo->data->print);
	}
}

