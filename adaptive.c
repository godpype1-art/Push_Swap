/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:31:33 by falves-e          #+#    #+#             */
/*   Updated: 2026/05/28 15:01:10 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder_check(t_stack *stackA)
{
	int	total_pairs;
	int	mistakes;
	int	i;
	int	j;
	
	i = 0;
	j = 1;
	mistakes = 0;
	total_pairs = 0;
	while (i < stackA->size)
	{
		j = i + 1;
		while (j < stackA->size)
		{
			total_pairs += 1;
			if (stackA[i] < stackA[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}

void	adaptive_algorythm(t_stack *stackA)
{
	float	disorder;
	float	medium;
	float	complex;

	disorder = disorder_check(stackA);
	medium = 0.2;
	complex = 0.5;
	if (disorder == 0)
		return (handle_error("sorted"));
	else if (disorder < medium)
		simple_alg(stackA);
	else if (medium <= disorder && disorder < complex)
		medium_alg(stackA);
	else if (complex <= disorder)
		complex_alg(stackA);	
}

