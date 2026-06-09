/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:22:32 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/09 15:44:05 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench(t_bench *bench)
{
		printf("[bench] disorder: %f%%\n", bench->disorder);
		if (bench->adaptive == 1)
		{
			if (bench->algorithm == 1)
				printf("[bench] strategy: Adaptive / O(n*n)(n\n");
			if (bench->algorithm == 2)
				printf("[bench] strategy: Adaptive / O(n√n)\n");
			if (bench->algorithm == 3)
				printf("[bench] strategy: Adaptive / O(nlogn)\n");
		}
		printf("[bench] total_ops: %d\n", bench->total_ops);
		printf("[bench] sa: %d sb: %d ss: ", bench->sa, bench->sb);
		printf("%d pa: %d pb: %d\n",bench->ss, bench->pa, bench->pb);
		printf("[bench] ra: %d rb: %d", bench->ra, bench->rb);
		printf(" rr: %d rra: %d ", bench->rr, bench->rrr);
		printf("rrb: %d rrr: %d\n", bench->rrb, bench->rrr);
}
