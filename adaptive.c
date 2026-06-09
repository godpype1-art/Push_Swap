/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:31:33 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/09 15:48:25 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* calculates disorder */
float	disorder_check(t_stack *stackA)
{
	int	total_pairs;
	int	mistakes;
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (stackA->size < 2)
		return (0.0f);
	mistakes = 0;
	total_pairs = 0;
	while (i < stackA->size)
	{
		j = i + 1;
		while (j < stackA->size)
		{
			total_pairs += 1;
			if (get(stackA, i) > get(stackA, j))
				mistakes += 1;
			j++;
		}
		i++;
	}
	return ((float)mistakes / total_pairs);
}

/* checks disorder and guides to algorythm */
void	adaptive_algorithm(t_stack *stackA, t_bench *bench)
{
	float	medium;
	float	high;

	printf("disorder = %f\n", bench->disorder);
	medium = 0.2f;
	high = 0.5f;
	if (bench->disorder < 0.0001f)
	{
		printf("sorted\n");
		return ;
	}
	else if (bench->disorder < medium)
		insertion_sort(stackA, bench);
	else if (bench->disorder < high)
		bucket_sort(stackA, bench);
	else
		merge_sorting(stackA);
}
