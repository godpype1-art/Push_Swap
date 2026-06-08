/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:13:17 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/08 19:31:11 by afranco-         ###   ########.fr       */
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

void merge(t_stack *stackA, t_stack *stackB, int lo, int mid, int hi)
{
	//printf("lo:%d mid:%d hi:%d\n", lo, mid, hi);
    int vlo;
    int vhi;
    int variance;
    int hi_variance;
    int is_high;

    is_high = 0;
    vlo = get(stackA, lo);
    vhi = get(stackA, mid);
    variance = mid - lo;
    hi_variance = hi - mid;
    hyper_rotate(stackA, lo, 1);
    while (variance > 0 && hi_variance > 0)
    {
		printf("variance:%d hi_variance:%d vlo:%d vhi:%d\n", variance, hi_variance, vlo, vhi);
        if (vlo < vhi)
        {
			printf("%s\n", "low");
            if (is_high)
                hyper_rotate(stackA, variance, -1);
            is_high = 0;
            variance--;
			push(stackB, pop(stackA));
			vlo = get(stackA, 0);
        }
        else
        {
			printf("%s\n", "high");
            if (!is_high)
                hyper_rotate(stackA, variance, 1);
            is_high = 1;
            hi_variance--;
			push(stackB, pop(stackA));
			vhi = get(stackA, 0);
        }
		printf("%s\n", "stackB");
		print_stack(stackB);
    }
    if (is_high)
        hyper_rotate(stackA, variance, -1);
    else
        hyper_rotate(stackA, variance, 1);
    while (variance-- > 0 || hi_variance-- > 0)
		push(stackB, pop(stackA));
	printf("%s\n", "stackB");
	print_stack(stackB);
	while (stackB->size)
		push(stackA, pop(stackB));
	hyper_rotate(stackA, lo, -1);
}

static void sort(t_stack *stackA, t_stack *stackB, int lo, int hi)
{
    int mid;

	if (hi - lo <= 1)
        return ;
    mid = lo + ((hi - lo) / 2);
    sort(stackA, stackB, lo, mid);
    sort(stackA, stackB, mid, hi);
	print_stack(stackA);
    merge(stackA, stackB, lo, mid, hi);
	printf("lo:%d mid:%d hi:%d\n", lo, mid, hi);
	print_stack(stackA);
}

void merge_sorting(t_stack *stackA)
{
	t_stack *stackB;

	stackB = init_stack(stackA->size);
	sort(stackA, stackB, 0, stackA->size);
}
