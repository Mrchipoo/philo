#include "philo.h"

void	ft_check(int i, t_philo *philo)
{
	int	k;
	int	j;

	k = ft_min(i, (i + 1) % philo->data->philo);
	j = ft_max(i, (i + 1) % philo->data->philo);
	philo[i].l_fork = &philo->data->fork[k];
	philo[i].r_fork = &philo->data->fork[j];
}

int	ft_min(int i, int j)
{
	if (i <= j)
		return (i);
	return (j);
}

int	ft_max(int i, int j)
{
	if (i >= j)
		return (i);
	return (j);
}

size_t	get_current_time(void)
{
	static int		flag;
	static struct timeval	time;
	struct timeval	now;
	size_t		a;

	if (flag == 0)
	{
		if (gettimeofday(&time, NULL) == -1)
			write(2, "gettimeofday() error\n", 22);
		flag = 1;
	}
	if (gettimeofday(&now, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	a = (now.tv_sec - time.tv_sec) * 1000;
	return (a + (now.tv_usec - time.tv_usec) / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
