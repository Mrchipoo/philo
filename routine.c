/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:07:40 by echoubby          #+#    #+#             */
/*   Updated: 20p4/09/04 13:07:42 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meals);
	if (philo->eat_log == 1)
	{
		pthread_mutex_unlock(&philo->data->meals);
		ft_usleep(philo, 10);
	}
	else
		pthread_mutex_unlock(&philo->data->meals);
}

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
	pthread_mutex_unlock(&philo->data->timer);
	pthread_mutex_lock(&philo->data->meals);
	philo->nb_of_meals++;
	philo->eat_log = 1;
	pthread_mutex_unlock(&philo->data->meals);
	ft_usleep(philo, philo->data->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (EXIT_SUCCESS);
}

int	ft_routine_help(t_philo *philo)
{
	if ((philo->data->philo % 2) == 1)
		philo_check(philo);
	pthread_mutex_lock(philo->l_fork);
	if (ft_print(philo, "has taken a fork", 1) == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		return (EXIT_FAILURE);
	}
	if (philo->data->philo == 1)
	{
		ft_usleep(philo, philo->data->time_to_die);
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
	if ((philo->id % 2) == 1)
		ft_usleep(philo, 30);
	while (1)
	{
		if (ft_routine_help(philo) == 1)
			return (NULL);
		if (philo_eat(philo) == 1)
			return (NULL);
		if (ft_print(philo, "is sleeping", 1) == 1)
			return (NULL);
		ft_usleep(philo, philo->data->time_to_sleep);
		if (ft_print(philo, "is thinking", 1) == 1)
			return (NULL);
	}
	return (NULL);
}
