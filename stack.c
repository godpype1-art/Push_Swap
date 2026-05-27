/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:02:49 by afranco-          #+#    #+#             */
/*   Updated: 2026/05/27 18:18:02 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get(t_stack	*stack, int indice)
{
	return stack->array[stack->start + (indice % stack->size)];
}

void reallocate(t_stack *stack, int newsize)
{
	int	*new;
	int	indice;

	indice = 0;
	stack->allocated_size = newsize;
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
	stack->end = stack->allocated_size - 1;
}

t_stack	*init_stack(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->size = 0;
	reallocate(stack, size);
	return (stack);
}

void push(t_stack *stack, int value)
{
	stack->end++;
	stack->end = stack->end % stack->allocated_size;
	stack->array[stack->end] = value;
	stack->size++;
	if (stack->size == stack->allocated_size)
		reallocate(stack, stack->allocated_size * 2);
}

int pop(t_stack *stack)
{
	int value;

	value = get(stack, stack->end);
	stack->end--;
	stack->end = stack->end % stack->allocated_size;
	stack->size--;
	return (value);
}

void rotate(t_stack *stack)
{
	int value;

	value = get(stack, stack->size - 1);
	stack->start--;
	stack->start = stack->start % stack->allocated_size;
	stack->array[stack->start] = value;
	stack->end--;
	stack->end = stack->end % stack->allocated_size;
}

void reverse_rotate(t_stack *stack)
{
	int value;

	value = get(stack, 0);
	stack->end++;
	stack->end = stack->end % stack->allocated_size;
	stack->array[stack->end] = value;
	stack->start++;
	stack->start = stack->start % stack->allocated_size;
}

void swap_first(t_stack *stack)
{
	int value1;
	int	value2;

	value1 = pop(stack);
	value2 = pop(stack);
	push(stack, value1);
	push(stack, value2);
}
