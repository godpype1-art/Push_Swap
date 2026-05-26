/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:52:46 by falves-e          #+#    #+#             */
/*   Updated: 2026/05/26 20:08:43 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_mem(char **array)
{
	int i;
	
	i = ft_strlen(array);
	while (i > 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

int	ft_is_valid(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] != '+' && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			return (0);
		if (str[i] == '-' && str[i + 1] && str[i + 1] == '-')
			return (0);
		if (str[i] == '-' && !(str[i + 1]))
		return (0);
		
	}
	return (1);
}

void	parser(int argc, char const *argv[])
{
	int	i;
	int	function;
	int	bench;
	char **array;
	char **tmp;
	
	i = 1;
	function = 0;
	bench = 0;
	while (argv[i] && ft_strncmp(argv[i], "--", 2) == 0)
	{
		if (ft_strncmp(argv[i], "--simple", 10) == 0)
			function = 1;
		else if (ft_strncmp(argv[i], "--medium", 10) == 0)
			function = 2;
		else if (ft_strncmp(argv[i], "--complex", 10) == 0)
			function = 3;
		else if (ft_strncmp(argv[i], "--adaptive", 10) == 0)
			function = 0;
		else if (ft_strncmp(argv[i], "--bench", 10) == 0)
			bench = 1;
		else
			handle_error();
		i++;
	}
	while (argv[i])
	{
		array = ft_split(argv[i], ' ');
		if (array == NULL)
			return (handle_error());
		tmp = array;
		while (*tmp)
		{
			if (ft_is_valid(*tmp))
				/* pile_name */ = ft_atoi(*tmp);
			else
				return(handle_error());
			tmp++;
		}
		free_mem(array);
		i++;
	}
}

/* #include <stdio.h>

int main(void)
{
	char s1[] = "--bench";
	char s2[] = "--medium";
	printf("Result = %d\n", ft_strcmp("--medium", s2));
	return 0;
} */
