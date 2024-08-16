#include "philo.h"

int	ft_is_digit(char a)
{
	if (a < '0' || a > '9')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int cheking_int(char *str, int i)
{
	while (str[i])
	{
		if (ft_is_digit(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
        if (str[i] == '-')
		    sign *= -1;
		i++;
	}
	if (cheking_int(str, i) == 1)
		return (-1);
	while (str[i])
	{
		res = res * 10 +(str[i] - 48);
		if ((res * sign) > 2147483647 || (res * sign) <= 0)
			return(-1);
		i++;
	}
	return (res);
}