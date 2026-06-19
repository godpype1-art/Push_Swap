/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 20:45:03 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/19 20:31:58 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_lowest(t_pushswap *bench, int lowest)
{
	if (lowest <= bench->stack_a->size / 2)
	{
		while (lowest > 0)
		{
			ra(bench);
			lowest--;
		}
	}
	else
	{
		while (lowest < bench->stack_a->size)
		{
			rra(bench);
			lowest++;
		}
	}
	pb(bench);
}

void	sort_stack_lo(t_pushswap *bench)
{
	int	i;
	int	lowest;

	i = 0;
	lowest = 0;
	while (bench->stack_a->size && i < bench->stack_a->size)
	{
		if (get(bench->stack_a, i) < get(bench->stack_a, lowest))
			lowest = i;
		i++;
	}
	push_lowest(bench, lowest);
}

void	sort_three(t_pushswap *pushswap)
{
	if (pushswap->stack_a->size == 2)
	{
		sa(pushswap);
		return ;
	}
	if (get(pushswap->stack_a, 0) < get(pushswap->stack_a, 1)
		&& get(pushswap->stack_a, 1) < get(pushswap->stack_a, 2))
		return ;
	if (get(pushswap->stack_a, 0) > get(pushswap->stack_a, 1))
		sa(pushswap);
	if (get(pushswap->stack_a, 0) < get(pushswap->stack_a, 1)
		&& get(pushswap->stack_a, 1) < get(pushswap->stack_a, 2))
		return ;
	if (get(pushswap->stack_a, 0) > get(pushswap->stack_a, 2))
		ra(pushswap);
	else
		rra(pushswap);
	sort_three(pushswap);
}

void	sort_five(t_pushswap *bench)
{
	if (bench->stack_a->size <= 3)
		return (sort_three(bench));
	sort_stack_lo(bench);
	sort_stack_lo(bench);
	sort_three(bench);
	pa(bench);
	pa(bench);
}
