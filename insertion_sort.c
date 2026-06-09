/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 23:30:12 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/09 17:43:22 by afranco-         ###   ########.fr       */
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
