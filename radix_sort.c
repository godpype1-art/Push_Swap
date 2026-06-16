/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:07:15 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/11 16:14:54 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sort_dim(t_stack *stack_a, int dim)
{
	int	i;

	i = 1;
	while (i < stack_a->size)
	{
		if((get(stack_a, i - 1) >> dim) % 2 > (get(stack_a, i) >> dim) % 2)
			return 0;
		i++;
	}
	return 1;
}

void radix_sort_dim(t_pushswap *pushswap, int dim)
{
	int	yy;
	int	size;

	size = pushswap->stack_a->size;
	yy = 0;
	while (yy < size)
	{
		if ((get(pushswap->stack_a, 0) >> dim) % 2 == 0)
			pb(pushswap);
		else
			ra(pushswap);
		yy++;
	}
	while (pushswap->stack_b->size)
		pa(pushswap);
	//print_stack(pushswap->stack_a);
}

void radix_sort(t_pushswap *pushswap)
{
	int dim;

	dim = 0;
	pushswap->algorithm = 3;
	pushswap->stack_b = init_stack(pushswap->stack_a->allocated_size);
	while (check_sort(pushswap->stack_a))
	{
		if (check_sort_dim(pushswap->stack_a, dim))
		{
			dim++;
			continue;
		}
		radix_sort_dim(pushswap, dim);
		dim++;
	}
}
