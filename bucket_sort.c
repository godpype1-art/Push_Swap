/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:41:01 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/03 17:09:00 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	buckets(t_stack *stackA, t_stack *stackB)
{
	int	bucket_count;
	int current_bucket;
	int	low;
	int	high;
	int	rotations;

	bucket_count = (int)sqrt((double)stackA->size);
	while (bucket_count * bucket_count < stackA->size)
    	bucket_count++;
	current_bucket = bucket_count - 1;
	while(current_bucket >= 0)
	{
		low = bucket_count * current_bucket;
		high = low + bucket_count - 1;
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
		current_bucket--;
	}
}

void	normalize(t_stack *stackA)
{
	int	*ranks;
	int	rank;
	int	i;
	int	j;
	
	ranks = malloc(sizeof(int) * stackA->size);
	if (ranks == NULL)
		return (handle_error());
	i = 0;
	while (i < stackA->size)
	{
		j = 0;
		rank = 0;
		while (j < stackA->size)
		{
			if (get(stackA, i) > get(stackA, j))
				rank++;
			j++;
		}
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

void	bucket_sort(t_stack *stackA)
{
	t_stack	*stackB;
	
	stackB = init_stack(stackA->size);
	normalize(stackA);
	buckets(stackA, stackB);

	free(stackB->array);
	free(stackB);	
}
