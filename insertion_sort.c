/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 23:30:12 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/10 15:28:09 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void insertion_sort(t_pushswap *pushswap)
{
	int	yy;
	int	where;
	
	pushswap->algorithm = 1;
	yy = 1;
	while (yy < pushswap->stack_a->size)
	{
		where = yy;
		while (get(pushswap->stack_a, 0) > get(pushswap->stack_a, 1) && where > 0)
		{
			sa(pushswap);
			rra(pushswap);
			where--;
		}
		while (where < yy)
		{
			ra(pushswap);
			where++;
		}
		yy++;
		ra(pushswap);
	}
	ra(pushswap);
}
