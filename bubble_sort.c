/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:36:45 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/11 16:13:00 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sort(t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < stack_a->size)
	{
		if(get(stack_a, i - 1) > get(stack_a, i))
			return 1;
		i++;
	}
	return 0;
}

void bubble_sort(t_pushswap *pushswap)
{
	int	yy;
	
	pushswap->algorithm = 1;
	while (check_sort(pushswap->stack_a))
	{
		yy = 0;
		while (yy < pushswap->stack_a->size)
		{
			while (yy != pushswap->stack_a->size - 1 && yy >= 0 && get(pushswap->stack_a, 0) > get(pushswap->stack_a, 1))
			{
				sa(pushswap);
				if (get(pushswap->stack_a, 1) > get(pushswap->stack_a, pushswap->stack_a->size - 1))
				{
					rra(pushswap);
					yy--;
				}
			}
			yy++;
			ra(pushswap);
		}
	}
	//print_stack(pushswap->stack_a);	
}
