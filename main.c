/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:07:19 by echoubby          #+#    #+#             */
/*   Updated: 2024/09/04 13:07:21 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_time	data;
	t_philo	*philo;

	if (argc == 6 || argc == 5)
	{
		if (checker(argv, argc) == 1)
		{
			ft_error();
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
		ft_error();
	return (0);
}
