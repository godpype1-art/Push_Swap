/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:18:58 by falves-e          #+#    #+#             */
/*   Updated: 2026/04/21 14:19:43 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len_s1;
	size_t	i;

	i = 0;
	len_s1 = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	if (i - 1 == len_s1)
	{
		str = malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	while (len_s1 > 0 && ft_strchr(set, s1[len_s1]) != NULL)
		len_s1--;
	str = ft_substr(s1, i, len_s1 + 1 - i);
	return (str);
}
