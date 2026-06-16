/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:02:49 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/11 20:25:46 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get(t_stack	*stack, int index)
{
	return (stack->array[(stack->start + index) % stack->allocated_size]);
}

int	moduler_remainder(int a, int b)
{
	return (((a % b) + b) % b);
}

void	reallocate(t_stack *stack, int newsize)
{
	int	*new;
	int	indice;

	indice = 0;
	new = malloc(sizeof(int) * (newsize));
	if (!new)
		return ;
	while (indice < stack->size)
	{
		new[indice] = get(stack, indice);
		indice++;
	}
	if (stack->array != NULL)
		free(stack->array);
	stack->array = new;
	stack->start = 0;
	stack->allocated_size = newsize;
	stack->end = stack->size - 1;
}

t_stack	*init_stack(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->size = 0;
	stack->array = NULL;
	reallocate(stack, size);
	return (stack);
}

void	push(t_stack *stack, int value)
{
	stack->start = moduler_remainder(stack->start - 1, stack->allocated_size);
	stack->array[stack->start] = value;
	stack->size++;
	if (stack->size == stack->allocated_size)
		reallocate(stack, stack->allocated_size * 2);
}
