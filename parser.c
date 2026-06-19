/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:52:46 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/19 20:30:07 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*#include <stdio.h>

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
}*/

/* arrange every arg through atoi */
void	arrange(t_pushswap *bench, char *tmp, int *nb)
{
	int	i;
	int	num;

	num = *nb;
	if (!ft_atoi_safe(tmp, &num))
		return (handle_error(bench));
	i = 0;
	while (i < bench->stack_b->size)
	{
		if (get(bench->stack_b, i) == num)
			return (handle_error(bench));
		i++;
	}
	push(bench->stack_b, num);
	nb = 0;
}

/* iterates args, separates if needed */
void	convert(const char **argv, t_pushswap *bench)
{
	char	**array;
	char	**tmp;
	int		nb;

	nb = 0;
	while (*(argv++))
	{
		array = ft_split(*(argv - 1), ' ');
		if (array == NULL || *array == NULL)
			return (free_mem(array), handle_error(bench));
		tmp = array;
		while (*(tmp++))
		{
			if (ft_is_valid(*(tmp - 1)))
			{
				arrange(bench, *(tmp - 1), &nb);
				if (bench->error)
					return (free_mem(array));
				nb = 0;
			}
			else
				return (free_mem(array), handle_error(bench));
		}
		free_mem(array);
	}
}

/* creates the stack, reads redirects to algs depending on flags */
void	create_stack(int argc, char const **argv, t_pushswap *bench)
{
	bench->stack_b = init_stack(argc);
	convert(argv, bench);
	while (bench->stack_b->size)
		push(bench->stack_a, pop(bench->stack_b));
	bench->disorder = disorder_check(bench);
	if (bench->error == 1)
		return ;
	if (bench->adaptive == 1)
		adaptive_algorithm(bench);
	else if (bench->algorithm == 1)
		selection_sort(bench);
	else if (bench->algorithm == 2)
		bucket_sort(bench);
	else if (bench->algorithm == 3)
		radix_sort(bench);
	if (bench->bench == 1 && bench->error == 0)
		print_bench(bench);
}

void	read_flags(char const *argv[], t_pushswap *bench, int *i)
{
	while (argv[*i] && ft_strncmp(argv[*i], "--", 2) == 0 && *i <= 2)
	{
		if (ft_strncmp(argv[*i], "--simple", ft_strlen(argv[*i])) == 0
			&& bench->adaptive == 0)
			bench->algorithm = 4 * bench->algorithm + 1;
		else if (ft_strncmp(argv[*i], "--medium", ft_strlen(argv[*i])) == 0
			&& bench->adaptive == 0)
			bench->algorithm = 4 * bench->algorithm + 2;
		else if (ft_strncmp(argv[*i], "--complex", ft_strlen(argv[*i])) == 0
			&& bench->adaptive == 0)
			bench->algorithm = 4 * bench->algorithm + 3;
		else if (ft_strncmp(argv[*i], "--adaptive", ft_strlen(argv[*i])) == 0
			&& bench->algorithm == 0)
			bench->adaptive = 1;
		else if (ft_strncmp(argv[*i], "--bench", ft_strlen(argv[*i])) == 0
			&& bench->bench == 0)
			bench->bench = 1;
		else
			return (handle_error(bench));
		(*i)++;
	}
}

/* receives the input, reads flags and stores integers */
void	parser(int argc, char const *argv[], t_pushswap *bench)
{
	int	i;

	i = 1;
	read_flags(argv, bench, &i);
	if (bench->algorithm >= 4)
		return (handle_error(bench));
	if (bench->algorithm == 0)
		bench->adaptive = 1;
	if (bench->error == 1)
		return ;
	create_stack(argc - i, &argv[i], bench);
}
