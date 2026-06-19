/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 23:30:12 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/19 20:35:27 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_on_indice(t_pushswap *pushswap, int indice)
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

void	put_number(t_pushswap *pushswap)
{
	int	a;
	int	i;

	a = get(pushswap->stack_a, 0);
	i = 0;
	while (i < pushswap->stack_b->size)
	{
		if (a < get(pushswap->stack_b, i))
			i++;
		else
			break ;
	}
	put_on_indice(pushswap, i);
}

void	selection_sort(t_pushswap *pushswap)
{
	int	yy;

	pushswap->algorithm = 1;
	if (pushswap->disorder < 0.0001f)
		return ;
	if (pushswap->stack_a->size <= 5)
		return (sort_five(pushswap));
	yy = 1;
	while (pushswap->stack_a->size)
		put_number(pushswap);
	while (pushswap->stack_b->size)
		pa(pushswap);
}
