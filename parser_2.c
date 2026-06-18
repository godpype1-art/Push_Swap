/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:22:42 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/18 19:23:32 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* standar error issue */
void	handle_error(t_pushswap *bench)
{
	ft_putstr_fd("Error\n", 2);
	bench->error = 1;
}

void	free_mem(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_atoi_safe(char *str, int *res)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str == NULL)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (sign == 1 && (*res > (INT_MAX - (str[i] - '0')) / 10))
			return (0);
		if (sign == -1 && (*res < (INT_MIN - ((str[i] - '0') * sign)) / 10))
			return (0);
		*res = (*res * 10) + ((str[i] - '0') * sign);
		i++;
	}
	return (1);
}

int	ft_is_valid(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
