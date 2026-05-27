/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:23:05 by falves-e          #+#    #+#             */
/*   Updated: 2026/04/23 20:42:23 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_sign_putnbr_fd(int n, int fd)
{
	char	c;
	int		sign;

	sign = 2 * (n >= 0) - 1;
	if (n >= -9 && n <= 9)
	{
		c = '0' + (sign * n);
		write(fd, &c, 1);
	}
	else
	{
		ft_sign_putnbr_fd(n / 10, fd);
		ft_sign_putnbr_fd(n % 10, fd);
	}
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_sign_putnbr_fd(n, fd);
	return ;
}
