/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:41:01 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/16 13:47:40 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pushes to stackB in bucket order, highest on top */
void	push_buckets(t_pushswap *bench, int high, int low)
{
	int	rotations;
	int	size;

	size = bench->stack_a->size;
	rotations = 0;
	while (bench->stack_a->size && rotations < size)
	{
		if (get(bench->stack_a, 0) >= low && get(bench->stack_a, 0) <= high)
			pb(bench);
		else
		{
			ra(bench);
			rotations++;
		}
	}
}
/* calculates the square root of stack size */
int	square_root(t_pushswap *bench)
{
	int nb;
	
	nb = 1;
	while (nb * nb < bench->stack_a->size)
		nb++;
	return (nb);
}

/* organizes the stackA through buckets, highest on the bottom*/
int	buckets(t_pushswap *bench)
{
	int	bucket_count;
	int	current_bucket;
	int	low;
	int	high;

	bucket_count = square_root(bench);
	current_bucket = 0;
	while (bench->stack_a->size && current_bucket < bucket_count)
	{
		low = bucket_count * current_bucket;
		high = low + bucket_count - 1;
		push_buckets(bench, high, low);
		current_bucket++;
	}
	return (bucket_count);
}

/* finds each value its rank */
int	ranking(t_stack *stackA, int i)
{
	int	j;
	int	rank;

	rank = 0;
	j = 0;
	while (j < stackA->size)
	{
		if (get(stackA, i) > get(stackA, j))
			rank++;
		j++;
	}
	return (rank);
}

/* This function set the stack values to 0,...,n-1 */
void	normalize(t_pushswap *bench)
{
	int	*ranks;
	int	rank;
	int	i;

	ranks = malloc(sizeof(int) * bench->stack_a->size);
	if (ranks == NULL)
		return (handle_error());
	i = 0;
	while (i < bench->stack_a->size)
	{
		rank = ranking(bench->stack_a, i);
		ranks[i] = rank;
		i++;
	}
	i = 0;
	while (i < bench->stack_a->size)
	{
		bench->stack_a->array[(bench->stack_a->start + i)
			% bench->stack_a->allocated_size] = ranks[i];
		i++;
	}
	free(ranks);
}

/* main unction of the sorting algorithm */
void	bucket_sort(t_pushswap *bench)
{
	int		bucket_count;

	bench->algorithm = 2;
	bench->stack_b = init_stack(bench->stack_a->size);
	normalize(bench);
	bucket_count = buckets(bench);
	sort_stack(bench);
}
