/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:07:12 by echoubby          #+#    #+#             */
/*   Updated: 2024/09/04 13:07:14 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philo *philo, t_time *data)
{
	pthread_mutex_lock(&data->timer);
	if (get_current_time() - philo->last_meal > data->time_to_die)
	{
		pthread_mutex_unlock(&data->timer);
		return (1);
	}
	pthread_mutex_unlock(&data->timer);
	return (0);
}

int	ft_dead(t_philo *philo, t_time *data)
{
	int	i;

	i = 0;
	while (i < philo->data->philo)
	{
		pthread_mutex_lock(&data->monitor);
		if (check_dead(&philo[i], data) == 1)
		{
			ft_print(&philo[i], "died", 1);
			pthread_mutex_lock(&data->dead_lock);
			philo[i].dead_check = 1;
			philo->data->dead = 1;
			pthread_mutex_unlock(&data->dead_lock);
			pthread_mutex_unlock(&data->monitor);
			return (1);
		}
		pthread_mutex_unlock(&data->monitor);
		i++;
	}
	return (0);
}

int	ft_full(t_philo *philo)
{
	int	i;
	int	finished;

	i = 0;
	finished = 0;
	while (i < philo->data->philo)
	{
		pthread_mutex_lock(&philo[i].data->meals);
		if (philo[i].nb_of_meals >= philo->data->max_meals)
		{
			philo[i].full_check = 1;
			finished++;
		}
		pthread_mutex_unlock(&philo[i].data->meals);
		i++;
	}
	if (finished >= philo->data->philo)
	{
		pthread_mutex_lock(&philo->data->dead_lock);
		philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (1);
	}
	return (0);
}

void	ft_log(t_philo *philo, t_time *data)
{
	int		i;
	size_t	time;
	size_t	on;
	size_t	in;

	i = 0;
	on = data->time_to_eat + data->time_to_sleep;
	in = (data->time_to_die - on) / 2;
	on += in;
	while (i < philo->data->philo)
	{
		pthread_mutex_lock(&philo->data->timer);
		time = get_current_time() - philo[i].last_meal;
		pthread_mutex_unlock(&philo->data->timer);
		pthread_mutex_lock(&philo[i].data->meals);
		if (philo[i].eat_log == 1 && time > on)
			philo[i].eat_log = 0;
		pthread_mutex_unlock(&philo[i].data->meals);
		i++;
	}
}

void	ft_monitor(t_philo *philo, t_time *data)
{
	if (data->max_meals != -1)
	{
		while (1)
		{
			ft_log(philo, data);
			if (ft_dead(philo, data) == 1 || ft_full(philo) == 1)
				break ;
		}
	}
	else if (data->max_meals == -1)
	{
		while (1)
		{
			ft_log(philo, data);
			if (ft_dead(philo, data) == 1)
				break ;
		}
	}
	return ;
}
