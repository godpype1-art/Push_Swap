/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:07:15 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/18 21:09:18 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < stack_a->size)
	{
		if (get(stack_a, i - 1) > get(stack_a, i))
			return (1);
		i++;
	}
	return (0);
}

int	check_sort_dim(t_stack *stack_a, int dim)
{
	int	i;

	i = 1;
	while (i < stack_a->size)
	{
		if ((get(stack_a, i - 1) >> dim) % 2 > (get(stack_a, i) >> dim) % 2)
			return (0);
		i++;
	}
	return (1);
}

void	radix_sort_dim(t_pushswap *pushswap, int dim)
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
}

void	radix_sort(t_pushswap *pushswap)
{
	int	dim;

	dim = 0;
	pushswap->algorithm = 3;
	while (check_sort(pushswap->stack_a))
	{
		if (pushswap->stack_a->size <= 5)
			return (sort_five(pushswap));
		if (check_sort_dim(pushswap->stack_a, dim))
		{
			dim++;
			continue ;
		}
		radix_sort_dim(pushswap, dim);
		dim++;
	}
}
