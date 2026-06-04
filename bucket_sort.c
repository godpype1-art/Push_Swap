/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:41:01 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/04 17:28:39 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void insertion_sort_mini(t_stack *stackB, int limit)
{
	int	yy;
	int	where;
	
	limit = 0;
	yy = 1;
	while (yy < stackB->size)
	{
		where = yy;
		while (get(stackB, 0) > get(stackB, 1) && where > 0)
		{
			swap_first(stackB);
			ft_putstr_fd("sa\n", 1);
			rotate(stackB);
			ft_putstr_fd("ra\n", 1);
			where--;
		}
		while (where < yy)
		{
			printf("1");
			reverse_rotate(stackB);
			ft_putstr_fd("rra\n", 1);
			where++;
		}
		yy++;
		reverse_rotate(stackB);
		printf("1");
		ft_putstr_fd("rra\n", 1);
	}
	reverse_rotate(stackB);
	ft_putstr_fd("rra\n", 1);
}

void	sort_stack(t_stack *stackA, t_stack *stackB, int bucket_count)
{
	int	current_bucket;
	int	high;
	int low;
	int	i;
	
	current_bucket = bucket_count - 1;
	while (current_bucket >= 0)
	{
		low  = current_bucket * bucket_count;
    	high = low + bucket_count - 1;
   		insertion_sort_mini(stackB, bucket_count);
	}
    i = 0;
    while (i < bucket_count && stackB->size > 0)
	{
		push(stackA, get(stackB, i));
        i++;
    	current_bucket--;
	}
}

int	push_buckets(t_stack *stackA, t_stack *stackB)
{
	int	bucket_count;
	int current_bucket;
	int	low;
	int	high;
	int	rotations;

	bucket_count = (int)sqrt((double)stackA->size);
	while (bucket_count * bucket_count < stackA->size)
    	bucket_count++;
	printf("buckets = %i\n", bucket_count);
	current_bucket = 0;
	while(current_bucket < bucket_count)
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
		current_bucket++;
	}
	return (bucket_count);
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
	int		bucket_count;
	
	stackB = init_stack(stackA->size);
	normalize(stackA);
	bucket_count = push_buckets(stackA, stackB);
	sort_stack(stackA, stackB, bucket_count);
	
	free(stackB->array);
	free(stackB);	
}
