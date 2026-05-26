/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:43:41 by falves-e          #+#    #+#             */
/*   Updated: 2026/04/29 14:41:50 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*put_negative(char *str, int n, int len)
{
	str[0] = '-';
	while (n < -9)
	{
		str[len] = (n % 10) * -1 + 48;
		n = n / 10;
		len--;
	}
	str[len] = n * -1 + 48;
	return (str);
}

static char	*put_positive(char *str, int n, int len)
{
	while (n > 9)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	str[len - 1] = n + 48;
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;
	int		temp;

	temp = n;
	sign = 2 * (n >= 0) - 1;
	len = 1;
	while (temp < -9 || temp > 9)
	{
		temp = temp / 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1 + (sign < 0)));
	if (str == NULL)
		return (NULL);
	if (sign < 0)
		put_negative(str, n, len);
	else
		put_positive(str, n, len);
	str[len + (sign < 0)] = '\0';
	return (str);
}
