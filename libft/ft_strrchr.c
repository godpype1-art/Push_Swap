/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:47:26 by falves-e          #+#    #+#             */
/*   Updated: 2026/04/23 21:54:52 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = (char *)s;
	while (str && len > 0)
	{
		if (str[len] == (char)c)
			return (str + len);
		len--;
	}
	if (str[len] == (char)c)
		return (str);
	return (NULL);
}
