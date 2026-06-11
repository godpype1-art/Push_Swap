/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:48:41 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/11 20:28:00 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop(t_stack *stack)
{
	int	value;

	value = get(stack, 0);
	stack->start = moduler_remainder(stack->start + 1, stack->allocated_size);
	stack->size--;
	return (value);
}

void	reverse_rotate(t_stack *stack)
{
	int	value;

	value = get(stack, stack->size - 1);
	stack->start = moduler_remainder(stack->start - 1, stack->allocated_size);
	stack->array[stack->start] = value;
	stack->end = moduler_remainder(stack->end - 1, stack->allocated_size);
}

void	rotate(t_stack *stack)
{
	int	value;

	value = get(stack, 0);
	stack->end = moduler_remainder(stack->end + 1, stack->allocated_size);
	stack->array[stack->end] = value;
	stack->start = moduler_remainder(stack->start + 1, stack->allocated_size);
}

void	swap_first(t_stack *stack)
{
	int	value1;
	int	value2;

	value1 = pop(stack);
	value2 = pop(stack);
	push(stack, value1);
	push(stack, value2);
}

void	free_stack(t_stack *stack)
{
	if (stack->array)
		free(stack->array);
	free(stack);
}
