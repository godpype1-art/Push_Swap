/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 23:30:12 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/11 19:32:45 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_pushswap *pushswap)
{
	if (get(pushswap->stack_a, 0) < get(pushswap->stack_a, 1) && get(pushswap->stack_a, 1) < get(pushswap->stack_a, 2))
		return;
	if (get(pushswap->stack_a, 0) > get(pushswap->stack_a, 1))
		sa(pushswap);
	if (get(pushswap->stack_a, 0) < get(pushswap->stack_a, 1) && get(pushswap->stack_a, 1) < get(pushswap->stack_a, 2))
		return;
	if (get(pushswap->stack_a, 0) > get(pushswap->stack_a, 2))
		ra(pushswap);
	else
		rra(pushswap);
	sort_three(pushswap);
}

void put_on_indice(t_pushswap *pushswap, int indice)
{
	int	ss;

	if (indice <= pushswap->stack_b->size / 2)
	{
		ss = indice + 1;
		while (--ss > 0)
			rb(pushswap);
		pb(pushswap);
		ss--;
		while (++ss < indice)
			rrb(pushswap);
	}
	else
	{
		ss = indice - 1;
		while (++ss < pushswap->stack_b->size)
			rrb(pushswap);
		pb(pushswap);
		ss++;
		while (--ss >= indice)
			rb(pushswap);
	}
}

void put_number(t_pushswap *pushswap)
{
	int a;
	int	i;

	a = get(pushswap->stack_a, 0);
	i = 0;
	while (i < pushswap->stack_b->size)
	{
		if (a < get(pushswap->stack_b, i))
			i++;
		else
			break;
	}
	put_on_indice(pushswap, i);
}

void insertion_sort(t_pushswap *pushswap)
{
	int	yy;
	
	if (pushswap->stack_a->size == 3)
	{
		sort_three(pushswap);
		return;
	}
	pushswap->algorithm = 1;
	yy = 1;
	pushswap->stack_b = init_stack(pushswap->stack_a->allocated_size);
	while (pushswap->stack_a->size)
		put_number(pushswap);
	while (pushswap->stack_b->size)
		pa(pushswap);
}
