/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:07:46 by echoubby          #+#    #+#             */
/*   Updated: 2024/09/04 13:07:48 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_print(t_philo *philo, char *s, int i)
{
	if (i == 0)
		printf("Error with %s\n", s);
	else if (i == 1 || i == 2)
	{
		pthread_mutex_lock(&philo->data->dead_lock);
		if (philo->data->dead == 1 || philo->dead_check == 1)
		{
			pthread_mutex_unlock(&philo->data->dead_lock);
			return (1);
		}
		pthread_mutex_unlock(&philo->data->dead_lock);
		i = philo->id;
		pthread_mutex_lock(&philo->data->print);
		printf("%zu %d %s\n", get_current_time(), philo->id, s);
		pthread_mutex_unlock(&philo->data->print);
	}
	return (0);
}

void	ft_error(void)
{
	write(2, "pls enter valid arg\n", 21);
	write(2, "example ./philo 5 800 200 200 10\n", 34);
}
