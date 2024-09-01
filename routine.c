#include "philo.h"

int	philo_eat(t_philo *philo)
{
	if (ft_print(philo, "is eating", 1) == 1)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return (EXIT_FAILURE);
	}
	pthread_mutex_lock(&philo->data->timer);
	philo->last_meal = get_current_time();
	pthread_mutex_lock(&philo->data->meals);
	philo->nb_of_meals++;
	pthread_mutex_unlock(&philo->data->meals);
	pthread_mutex_unlock(&philo->data->timer);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (EXIT_SUCCESS);
}

int	ft_routine_help(t_philo *philo, int id)
{
	if (philo->data->philo % 2 == 0 && id % 2 == 0)
		ft_usleep(5);
	pthread_mutex_lock(philo->l_fork);
	if (ft_print(philo, "has taken a fork", 1) == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		return (EXIT_FAILURE);
	}
	if (philo->data->philo == 1)
	{
		ft_usleep(philo->data->time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return (EXIT_FAILURE);
	}
	pthread_mutex_lock(philo->r_fork);
	if (ft_print(philo, "has taken a fork", 1) == 1)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (ft_routine_help(philo, philo->id) == 1)
			return (NULL);
		if (philo_eat(philo) == 1)
			return (NULL);
		if (ft_print(philo, "is sleeping", 1) == 1)
			return (NULL);
		ft_usleep(philo->data->time_to_sleep);
		if (ft_print(philo, "is thinking", 1) == 1)
			return (NULL);
	}
	return (NULL);
}
