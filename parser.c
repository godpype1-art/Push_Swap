/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:52:46 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/08 18:13:23 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//REMOVE LATER
void	print_stack(t_stack *tsak)
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

/* arrange every arg through atoi */
void	arrange(t_stack *stack, char *tmp, int *nb)
{
	int	i;
	int	num;

	num = *nb;
	if (!ft_atoi_safe(tmp, &num))
		return (handle_error());
	i = 0;
	while (i < stack->size)
	{
		if(get(stack, i) == num)
			return (handle_error());
		i++;
	} 
	push(stack, num);
	nb = 0;
}

/* iterates args, separates if needed */
void	convert(const char **argv, t_stack	*stack)
{
	char	**array;
	char	**tmp;
	int		nb;
	
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
				arrange(stack, *tmp, &nb);
				nb = 0;
			}
			else
				return(handle_error());
			tmp++;
		}
		free_mem(array);
		argv++;
	}
}

/* creates the stack, reads redirects to algs depending on flags */
void	create_stack(int argc, char const **argv, int function, int bench)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		i;
	
	i = 0;
	tmp = init_stack(argc);
	stack = init_stack(argc);
	convert(argv, tmp);
	while (get(tmp, 0) && i < tmp->allocated_size)
	{
		push(stack, pop(tmp));
		i++;
	}
	printf("\n==== stack ====\n\n");
	print_stack(stack);
	printf("\n==== bucket ====\n\n");
	if (function == 0)
		adaptive_algorythm(stack);
	else if (function == 1)
		insertion_sort(stack);
	else if (function == 2)
		bucket_sort(stack);
	else if (function == 3)
		printf("complex\n");
	if (bench == 1)
		printf("bench = 1\n");
}
/* receives the imput, reads flags and stores integers */
void	parser(int argc, char const *argv[])
{
	int	i;
	int	function;
	int	bench;

	i = 1;
	function = 0;
	bench = 0;
	while (argv[i] && ft_strncmp(argv[i], "--", 2) == 0)
	{
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
	create_stack(argc - i, &argv[i], function, bench);
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
