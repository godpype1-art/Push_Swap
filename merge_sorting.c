/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:13:17 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/08 15:17:24 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void hyper_rotate(t_stack *stackA, int lo, int di)
{
    while (lo-- > 0)
    {
        if (di >= 0)
            rotate(stackA);
        else
            reverse_rotate(stackA);
    }
}

static void merge(t_stack *stackA, t_stack *stackB, int lo, int mid, int hi)
{
    int vlo;
    int vhi;
    int variance;
    int hi_variance;
    int is_high;

    is_high = 0;
    vlo = get(stackA, lo);
    vhi = get(stackA, mid + 1);
    variance = mid - lo + 1;
    hi_variance = hi - mid + 1;
    hyper_rotate(stackA, variance, 1);
    while (variance > 0 && hi_variance > 0)
    {
        if (vlo < vhi)
        {
            if (is_high)
                hyper_rotate(stackA, variance, -1);
            is_high = 0;
            variance--;
        }
        else
        {
            if (!is_high)
                hyper_rotate(stackA, variance, 1);~
            is_high = 1;
            hi_variance--;
        }
        push(stackB, pop(stackA));
    }
    if (is_high)
        hyper_rotate(stackA, variance, -1);
    else
        hyper_rotate(stackA, variance, 1);
    while (variance-- > 0 && hi_variance-- > 0)
        push(stackB, pop(stackA));
}

static void sort(t_stack *stackA, t_stack *stackB, int lo, int hi)
{
    int mid;

	if (lo < hi)
        return ;
    mid = lo + ((hi - lo) / 2);
    sort(stackA, stackB, lo, mid);
    sort(stackA, stackB, mid + 1, hi);
    merge(stackA, stackB, lo, mid, hi);
}
