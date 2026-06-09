/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:41:01 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/09 19:18:55 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pushes to stackB in bucket order, highest on top */
void	push_buckets(t_pushswap *bench, int high, int low)
{
	int	rotations;

	rotations = 0;
	while (rotations < bench->stack_a->size)
	{
		if (get(bench->stack_a, 0) >= low && get(bench->stack_a, 0) <= high)
		{
			pb(bench);
			rotations = 0;
		}
		else
		{
			ra(bench);
			rotations++;
		}
	}
}

/* organizes the stackA through buckets, highest on the bottom*/
int	buckets(t_pushswap *bench)
{
	int	bucket_count;
	int	current_bucket;
	int	low;
	int	high;

	bucket_count = (int)sqrt((double)bench->stack_a->size);
	while (bucket_count * bucket_count < bench->stack_a->size)
		bucket_count++;
	current_bucket = 0;
	while (current_bucket < bucket_count)
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
	printf("\n==== begin sorting ====\n\n");
	bench->stack_b = init_stack(bench->stack_a->size);
	printf("\n======= StackB =======\n\n");
	print_stack(bench->stack_b);
	printf("\n===== Normalizing =====\n\n");
	normalize(bench);
	print_stack(bench->stack_a);
	printf("\n==== Pushing Buckets ====\n\n");
	bucket_count = buckets(bench);
	print_stack(bench->stack_b);
	printf("\n==== Pushing Sorted ====\n\n");
	sort_stack(bench, bucket_count);
	print_stack(bench->stack_a);
	printf("\n===== End Sorting =====\n\n");
	free(bench->stack_b->array);
	free(bench->stack_b);
}
