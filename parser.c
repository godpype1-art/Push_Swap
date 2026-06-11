/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:52:46 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/11 20:19:15 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	print_stack(t_stack *tsak)
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
		if (get(stack, i) == num)
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
				return (handle_error());
			tmp++;
		}
		free_mem(array);
		argv++;
	}
}

/* creates the stack, reads redirects to algs depending on flags */
void	create_stack(int argc, char const **argv, t_pushswap *bench)
{
	t_stack	*tmp;

	tmp = init_stack(argc);
	convert(argv, tmp);
	while (tmp->size)
		push(bench->stack_a, pop(tmp));
	bench->disorder = disorder_check(bench);
	if (bench->disorder < 0.0001f)
		print_bench(bench);
	else
	{
		if (bench->adaptive == 1)
			adaptive_algorithm(bench);
		else if (bench->algorithm == 1)
			selection_sort(bench);
		else if (bench->algorithm == 2)
			bucket_sort(bench);
		else if (bench->algorithm == 3)
			radix_sort(bench);
		if (bench->bench == 1)
			print_bench(bench);
	}
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
			bench->algorithm = 4 * bench->algorithm +  3;
		else if (ft_strncmp(argv[*i], "--adaptive", ft_strlen(argv[*i])) == 0
			&& bench->algorithm == 0)
			bench->adaptive = 1;
		else if (ft_strncmp(argv[*i], "--bench", ft_strlen(argv[*i])) == 0
			&& bench->bench == 0)
			bench->bench = 1;
		else
			return (handle_error());
		(*i)++;
	}
}
/* receives the input, reads flags and stores integers */
void	parser(int argc, char const *argv[], t_pushswap *bench)
{
	int	i;

	i = 1;
	read_flags(argv, bench, &i);
	/*while (argv[i] && ft_strncmp(argv[i], "--", 2) == 0 && i <= 2)
	{
		if (ft_strncmp(argv[i], "--simple", ft_strlen(argv[i])) == 0 && bench->adaptive == 0)
			bench->algorithm = 4 * bench->algorithm + 1;
		else if (ft_strncmp(argv[i], "--medium", ft_strlen(argv[i])) == 0 && bench->adaptive == 0)
			bench->algorithm = 4 * bench->algorithm + 2;
		else if (ft_strncmp(argv[i], "--complex", ft_strlen(argv[i])) == 0 && bench->adaptive == 0)
			bench->algorithm = 4 * bench->algorithm +  3;
		else if (ft_strncmp(argv[i], "--adaptive", ft_strlen(argv[i])) == 0 && bench->algorithm == 0)
			bench->adaptive = 1;
		else if (ft_strncmp(argv[i], "--bench", ft_strlen(argv[i])) == 0 && bench->bench == 0)
			bench->bench = 1;
		else
			return (handle_error());
		i++;
	}*/
	if (bench->algorithm >= 4)
		return (handle_error());
	if (bench->algorithm == 0)
		bench->adaptive = 1;
	create_stack(argc - i, &argv[i], bench);
}
