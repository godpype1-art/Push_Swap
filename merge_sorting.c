/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:13:17 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/08 14:41:29 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void merge(t_stack *stackA, t_stack *stackB, int lo, int mid, int hi)
{
	
}

static void sort(t_stack *stackA, t_stack *stackB, int lo, int hi)
{
    int mid;

	if (lo < hi)
        return ;
    mid = lo + ((hi - lo) / 2);
    sort(stackA, stackB, lo, mid);
    sort(stackA, stackB, mid, hi);
    merge(stackA, stackB, lo, mid, hi);
}
