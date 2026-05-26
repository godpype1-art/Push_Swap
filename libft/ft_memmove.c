/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:19:46 by falves-e          #+#    #+#             */
/*   Updated: 2026/04/29 14:07:57 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*origin;
	unsigned char	*final;

	i = 0;
	origin = (unsigned char *) src;
	final = (unsigned char *) dest;
	if (final < origin)
	{
		while (i < n)
		{
			final[i] = origin[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			final[i] = origin[i];
		}
	}
	return (dest);
}
