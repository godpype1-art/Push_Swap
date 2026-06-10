/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:06:32 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/10 17:52:09 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pushes the hightest value and return the stack to original state */
void	push_highest(t_pushswap *bench, int limit)
{
	int	i;

	i = limit;
	while (limit > 0)
	{
		rb(bench);
		limit--;
	}
	pa(bench);
	while (limit < i)
	{
		rrb(bench);
		limit++;
	}
}

/* calculates the index inside the bucket of the highest value */
int	highest_index(t_stack *stackB, int high, int low)
{
	int	i;
	int	limit;

	limit = 0;
	i = 0;
	while (i <= high - low && get(stackB, i) >= low)
	{
		if (get(stackB, i) >= get(stackB, limit))
			limit = i;
		i++;
	}
	return (limit);
}

/* sorts and pushes to stackA */
void	sort_stack(t_pushswap *bench, int bucket_count)
{
	int	current_bucket;
	int	high;
	int	low;
	int	limit;

	current_bucket = bucket_count - 1;
	while (current_bucket-- >= 0)
	{
		limit = 0;
		low = current_bucket * bucket_count;
		high = low + bucket_count - 1;
		while (bench->stack_b->size && get(bench->stack_b, 0) >= low)
		{
			limit = highest_index(bench->stack_b, high, low);
			push_highest(bench, limit);
		}
	}
}
