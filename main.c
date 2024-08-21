#include "philo.h"

int	main(int argc, char **argv)
{
	t_time	data;
	t_philo	*philo;

	if (argc == 6 || argc == 5)
	{
		if (checker(argv, argc) == 1)
		{
			write(2, "pls enter arg\nexample ./philo 5 800 200 200 10\n", 51);
			return (0);
		}
		ft_data(argc, argv, &data);
		philo = malloc(sizeof(t_philo) * data.philo);
		if (philo == NULL)
			return (ft_print(NULL, "malloc", 0), EXIT_FAILURE);
		if (ft_mutex_init(data.philo, &data) == 1)
			return (ft_print(NULL, "mutex_init", 0), EXIT_FAILURE);
		if (ft_init(philo, &data, data.philo) == 1)
			return (ft_print(NULL, "philo_init", 0), EXIT_FAILURE);
		ft_monitor(philo, &data);
		ft_mutex_join(data, philo);
	}
	else
		write(2, "pls enter arg\nexample ./philo 5 800 200 200 10\n", 51);
	return (0);
}
