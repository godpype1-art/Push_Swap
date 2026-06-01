/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 23:30:12 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/01 12:01:59 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 3 2 6 4 5

void insertion_sort(t_stack *stackA)
{
	int		yy;
	int		where;

	yy = 1;
	while (yy < stackA->size)
	{
		where = yy;
		while (get(stackA, 0) > get(stackA, 1) && where > 0)
		{
			swap_first(stackA);
			rotate(stackA);
			where--;
		}
		while (where < yy)
		{
			reverse_rotate(stackA);
			where++;
		}
		reverse_rotate(stackA);
		yy++;
	}
}
