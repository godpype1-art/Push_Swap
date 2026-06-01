/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:52:46 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/01 16:29:34 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/* standar error issue */
void	handle_error(void)
{
	printf("Error == TU ÉS GAY\n");
}

void print_stack(t_stack *tsak)
{
	int i = 0;
	printf("start:%d, end:%d\n", tsak->start, tsak->end);
	printf("size:%d, allocated_size:%d\n", tsak->size, tsak->allocated_size);
	while (i < tsak->allocated_size)
		printf("%d, ", tsak->array[i++]);
	printf("\n");
	i = 0;
	printf("%s\n", "start");
	while (i < tsak->size)
		printf("%d\n", get(tsak, i++));
	printf("%s\n", "end");
}
/* frees array from split */
static void	free_mem(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
/* version atoi that breaks if overflow/underflow */
int ft_atoi_safe(char *str, int *res)
{
	int	i;
	int sign;

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
		if (sign == 1 && (*res > (INT32_MAX - (str[i] - '0')) / 10))
			return (0);
		if (sign == -1 && (*res < (INT32_MIN - ((str[i] - '0') * sign)) / 10))
			return (0);
		*res = (*res * 10) + ((str[i] - '0') * sign);
		i++;
	}
	return (1);
}


/* Checks if args are in a valid format */
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

static void convert(const char **argv, t_stack	*stack)
{
	int		nb;
	char	**array;
	char	**tmp;
	int i; // iterador do printf
	int ii;
	
	i = 1;
	while (*argv)
	{
		array = ft_split(*argv, ' ');
		if (array == NULL)
			return (handle_error());
		tmp = array;
		while (*tmp)
		{
			if (ft_is_valid(*tmp))
			{
				if (!ft_atoi_safe(*tmp, &nb))
					return (handle_error());
				printf("arg%d = %d\n", i, nb); //printa o arg respetivo
				ii = 0;
				while (ii < stack->size)
				{
					if(get(stack, ii) == nb)
						return (handle_error());
					ii++;
				} 
				push(stack, nb);
				nb = 0;
				i++; //iterador do printf
			}
			else
				return(handle_error());
			tmp++;
		}
		free_mem(array);
		argv++;
	}
}

/* main parser function, detects flags and saves them */
void	parser(int argc, char const *argv[])
{
	int	i;
	int	function;
	int	bench;
	t_stack *stack;

	i = 1;
	function = 0;
	bench = 0;
	while (argv[i] && ft_strncmp(argv[i], "--", 2) == 0)
	{
		/* verify expected behaviour
		this function executes only the last algorythm flag read */
		if (ft_strncmp(argv[i], "--simple", ft_strlen(argv[i])) == 0)
			function = 1;
		else if (ft_strncmp(argv[i], "--medium", ft_strlen(argv[i])) == 0)
			function = 2;
		else if (ft_strncmp(argv[i], "--complex", ft_strlen(argv[i])) == 0)
			function = 3;
		else if (ft_strncmp(argv[i], "--adaptive", ft_strlen(argv[i])) == 0)
			function = 0;
		else if (ft_strncmp(argv[i], "--bench", ft_strlen(argv[i])) == 0)
			bench = 1;
		else
			return (handle_error());
		i++;
	}
	printf("function = %d\n", function);
	printf("bench = %d\n", bench);
	stack = init_stack(argc - i);
	convert(&argv[i], stack);
	print_stack(stack);
	if (function == 0)
		adaptive_algorythm(stack);
	else if (function == 1)
		insertion_sort(stack);
		//simple_algorythm
	else if (function == 2)
		printf("medium\n");
		//medium algorythm
	else if (function == 3)
		printf("complex\n");
		//complex algorythm	
	print_stack(stack);
}


//#include <stdio.h>

/* int main(void)
{
	int nb = 0;
	char s1[] = "2147483648";
	//char s2[] = "--medium";
	parser(s1, &nb);
	printf("Result = %d\n", parser(s1, &nb));
	printf("Converted result = %d\n", nb);
	
	return 0;
} */
