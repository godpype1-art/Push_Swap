/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 23:30:12 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/08 16:54:10 by falves-e         ###   ########.fr       */
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
