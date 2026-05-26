/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:40:56 by falves-e          #+#    #+#             */
/*   Updated: 2026/04/29 14:29:46 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			word_count++;
		while (*s != c && *s)
			s++;
	}
	return (word_count);
}

static char	*fill_word(char const *s, char c)
{
	size_t	word_len;
	char	*str;

	word_len = 0;
	while (s[word_len] != c && s[word_len])
		word_len++;
	str = malloc(sizeof(char) * (word_len + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s, word_len);
	str[word_len] = '\0';
	return (str);
}

static void	free_all(char **array, size_t i)
{
	while (i > 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = count_words(s, c);
	array = malloc(sizeof(char *) * (word_count + 1));
	if (array == NULL)
		return (NULL);
	while (i < word_count)
	{
		while (*s == c)
			s++;
		array[i] = fill_word(s, c);
		if (array[i] == NULL)
		{
			free_all(array, i);
			return (NULL);
		}
		s = ft_strchr(s, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}
