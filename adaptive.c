/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:31:33 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/08 19:29:51 by afranco-         ###   ########.fr       */
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
void	adaptive_algorythm(t_stack *stackA)
{
	float	disorder;
	float	medium;
	float	high;

	disorder = disorder_check(stackA);
	printf("disorder = %f\n", disorder);
	medium = 0.2f;
	high = 0.5f;
	if (disorder < 0.0001f)
	{
		printf("sorted\n");
		return ;
	}
	else if (disorder < medium)
		insertion_sort(stackA);
	else if (disorder < high)
		bucket_sort(stackA);
	else
		merge_sorting(stackA);
}
