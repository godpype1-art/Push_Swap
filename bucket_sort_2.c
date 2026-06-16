/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:06:32 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/11 14:59:19 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_highest(t_pushswap *bench, int highest)
{
	if (highest <= bench->stack_b->size / 2)
	{
		while (highest > 0)
		{
			rb(bench);
			highest--;
		}
	}
	else
	{
		while (highest < bench->stack_b->size)
		{
			rrb(bench);
			highest++;
		}
	}
	pa(bench);
}

void sort_stack(t_pushswap *bench)
{
	int	i;
	int	highest;

	i = 0;
	highest = 0;
	if (bench->stack_b->size == 0)
		return;
	while (bench->stack_b->size && i < bench->stack_b->size)
	{
		if (get(bench->stack_b, i) >= get(bench->stack_b, highest))
			highest = i;
		i++;
	}
	push_highest(bench, highest);
	sort_stack(bench);
}
