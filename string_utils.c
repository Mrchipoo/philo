#include "philo.h"

void	ft_print(t_philo *philo, char *s, int i)
{
	if (i == 0)
		printf("Error with %s\n", s);
	else if (i == 1)
	{
		i = philo->id;
		pthread_mutex_lock(&philo->data->print);
		printf("%zu philo number = %d is %s\n", get_current_time(), i, s);
		pthread_mutex_unlock(&philo->data->print);
	}
}

