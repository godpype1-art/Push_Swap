/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:03:26 by falves-e          #+#    #+#             */
/*   Updated: 2026/04/29 14:03:05 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*orig;

	i = 0;
	temp = (unsigned char *)dest;
	orig = (unsigned char *)src;
	while (i < n)
	{
		temp[i] = orig[i];
		i++;
	}
	return (dest);
}
