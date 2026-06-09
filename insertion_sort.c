/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 23:30:12 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/09 15:47:03 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void insertion_sort(t_stack *stackA, t_bench *bench)
{
	int	yy;
	int	where;
	
	bench->algorithm = 1;
	yy = 1;
	while (yy < stackA->size)
	{
		where = yy;
		while (get(stackA, 0) > get(stackA, 1) && where > 0)
		{
			swap_first(stackA);
			ft_putstr_fd("sa\n", 1);
			reverse_rotate(stackA);
			ft_putstr_fd("rra\n", 1);
			where--;
		}
		while (where < yy)
		{
			rotate(stackA);
			ft_putstr_fd("rra\n", 1);
			where++;
		}
		yy++;
		rotate(stackA);
		ft_putstr_fd("rra\n", 1);
	}
	rotate(stackA);
	ft_putstr_fd("rra\n", 1);
}
