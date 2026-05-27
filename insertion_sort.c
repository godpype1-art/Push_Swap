/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 23:30:12 by afranco-          #+#    #+#             */
/*   Updated: 2026/05/28 00:03:04 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 3 2 6 4 5

void insertion_sort(t_stack *stackA)
{
	t_stack *stackB;
	int		yy;
	int		where;

	stackB = init_stack(stackA->allocated_size);
	reverse_rotate(stackA);
	yy = 1;
	while (yy < stackB->size)
	{
		push(stackB, pop(stackA));
		yy++;
	}
}
