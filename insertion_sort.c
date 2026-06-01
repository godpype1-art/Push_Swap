/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 23:30:12 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/01 17:40:34 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void insertion_sort(t_stack *stackA)
{
	int	yy;
	int	where;
	
	yy = 1;
	while (yy < stackA->size)
	{
		where = yy;
		while (get(stackA, 0) > get(stackA, 1) && where > 0)
		{
			swap_first(stackA);
			ft_putstr_fd("sa\n", 1);
			rotate(stackA);
			ft_putstr_fd("ra\n", 1);
			where--;
		}
		while (where < yy)
		{
			reverse_rotate(stackA);
			ft_putstr_fd("rra\n", 1);
			where++;
		}
		yy++;
		reverse_rotate(stackA);
		ft_putstr_fd("rra\n", 1);
	}
	reverse_rotate(stackA);
	ft_putstr_fd("rra\n", 1);
}
