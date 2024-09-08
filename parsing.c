/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:08:18 by echoubby          #+#    #+#             */
/*   Updated: 2024/09/04 13:08:19 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checker(char **argv, int argc)
{
	int	a;
	int	i;

	i = 1;
	while (i < argc)
	{
		a = ft_atoi(argv[i]);
		if (i == 1 && a == 0)
			return (EXIT_FAILURE);
		else if (a == -1)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
