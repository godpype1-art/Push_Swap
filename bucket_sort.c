/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:41:01 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/08 18:08:13 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pushes to stackB in bucket order, highest on top */
void	push_buckets(t_stack *stackA, t_stack *stackB, int high, int low)
{
	int	rotations;

	rotations = 0;
	while (rotations < stackA->size)
	{
		if (get(stackA, 0) >= low && get(stackA, 0) <= high)
		{
			push(stackB, pop(stackA));
			rotations = 0;
			printf("pb\n");
		}
		else
		{
			rotate(stackA);
			printf("ra\n");
			rotations++;
		}
	}
}

/* organizes the stackA through buckets, highest on the bottom*/
int	buckets(t_stack *stackA, t_stack *stackB)
{
	int	bucket_count;
	int	current_bucket;
	int	low;
	int	high;
	int	rotations;

	bucket_count = (int)sqrt((double)stackA->size);
	while (bucket_count * bucket_count < stackA->size)
		bucket_count++;
	current_bucket = 0;
	while (current_bucket < bucket_count)
	{
		low = bucket_count * current_bucket;
		high = low + bucket_count - 1;
		rotations = 0;
		push_buckets(stackA, stackB, high, low);
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
void	normalize(t_stack *stackA)
{
	int	*ranks;
	int	rank;
	int	i;

	ranks = malloc(sizeof(int) * stackA->size);
	if (ranks == NULL)
		return (handle_error());
	i = 0;
	while (i < stackA->size)
	{
		rank = ranking(stackA, i);
		ranks[i] = rank;
		i++;
	}
	i = 0;
	while (i < stackA->size)
	{
		stackA->array[(stackA->start + i) % stackA->allocated_size] = ranks[i];
		i++;
	}
	free(ranks);
}

/* main unction of the sorting algorithm */
void	bucket_sort(t_stack *stackA)
{
	t_stack	*stackb;
	int		bucket_count;

	printf("\n==== begin sorting ====\n\n");
	stackb = init_stack(stackA->size);
	printf("\n======= StackB =======\n\n");
	print_stack(stackb);
	printf("\n===== Normalizing =====\n\n");
	normalize(stackA);
	print_stack(stackA);
	printf("\n==== Pushing Buckets ====\n\n");
	bucket_count = buckets(stackA, stackb);
	print_stack(stackb);
	printf("\n==== Pushing Sorted ====\n\n");
	sort_stack(stackA, stackb, bucket_count);
	print_stack(stackA);
	printf("\n===== End Sorting =====\n\n");
	free(stackb->array);
	free(stackb);
}
