/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:13:17 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/09 19:19:25 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void hyper_rotate(t_pushswap *pushswap, int lo, int di)
{
    while (lo-- > 0)
    {
        if (di >= 0)
            ra(pushswap);
        else
            rra(pushswap);
    }
}

void merge(t_pushswap *pushswap, int lo, int mid, int hi)
{
	//printf("lo:%d mid:%d hi:%d\n", lo, mid, hi);
    int vlo;
    int vhi;
    int variance;
    int hi_variance;
    int is_high;

    is_high = 0;
    vlo = get(pushswap->stack_a, lo);
    vhi = get(pushswap->stack_a, mid);
    variance = mid - lo;
    hi_variance = hi - mid;
    hyper_rotate(pushswap, lo, 1);
    while (variance > 0 && hi_variance > 0)
    {
        if (vlo < vhi)
        {
            if (is_high)
                hyper_rotate(pushswap, variance, -1);
            is_high = 0;
            variance--;
			pb(pushswap);
			vlo = get(pushswap->stack_a, 0);
        }
        else
        {
            if (!is_high)
                hyper_rotate(pushswap, variance, 1);
            is_high = 1;
            hi_variance--;
			pb(pushswap);
			vhi = get(pushswap->stack_a, 0);
        }
    }
    if (is_high)
        hyper_rotate(pushswap, variance, -1);
    else
        hyper_rotate(pushswap, variance, 1);
    while (variance-- > 0 || hi_variance-- > 0)
		pb(pushswap);
	while (pushswap->stack_b->size)
		pa(pushswap);
	hyper_rotate(pushswap, lo, -1);
}

static void sort(t_pushswap *pushswap, int lo, int hi)
{
    int mid;

	if (hi - lo <= 1)
        return ;
    mid = lo + ((hi - lo) / 2);
    sort(pushswap, lo, mid);
    sort(pushswap, mid, hi);;
    merge(pushswap, lo, mid, hi);
}

void merge_sorting(t_pushswap *pushswap)
{
	pushswap->algorithm = 3;
	pushswap->stack_b = init_stack(pushswap->stack_a->size);
	sort(pushswap, 0, pushswap->stack_a->size);
}
