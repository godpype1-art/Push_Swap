/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:31:33 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/11 18:27:09 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* calculates disorder */
float	disorder_check(t_pushswap *bench)
{
	int	total_pairs;
	int	mistakes;
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (bench->stack_a->size < 2)
		return (0.0f);
	mistakes = 0;
	total_pairs = 0;
	while (i < bench->stack_a->size)
	{
		j = i + 1;
		while (j < bench->stack_a->size)
		{
			total_pairs += 1;
			if (get(bench->stack_a, i) > get(bench->stack_a, j))
				mistakes += 1;
			j++;
		}
		i++;
	}
	return ((float)mistakes / total_pairs);
}

/* checks disorder and guides to algorythm */
void	adaptive_algorithm(t_pushswap *bench)
{
	float	medium;
	float	high;

	medium = 0.2f;
	high = 0.5f;
	if (bench->disorder < 0.0001f)
	{
		printf("sorted\n");
		return ;
	}
	else if (bench->disorder < medium)
		insertion_sort(bench);
	else if (bench->disorder < high)
		bucket_sort(bench);
	else
		radix_sort(bench);
}
