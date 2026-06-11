/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:02:49 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/11 14:16:58 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get(t_stack	*stack, int indice)
{
	//printf("indice:%d, get:%d, start:%d, end:%d\n", indice, (stack->start + indice) % stack->allocated_size, stack->start, stack->end);
	return (stack->array[(stack->start + indice) % stack->allocated_size]);
}

int moduler_remainder(int a, int b)
{
	return (((a % b) + b) % b);
}

void reallocate(t_stack *stack, int newsize)
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

void push(t_stack *stack, int value)
{
	stack->start = moduler_remainder(stack->start - 1, stack->allocated_size);
	stack->array[stack->start] = value;
	stack->size++;
	if (stack->size == stack->allocated_size)
		reallocate(stack, stack->allocated_size * 2);
}

int pop(t_stack *stack)
{
	int value;

	value = get(stack, 0);
	stack->start = moduler_remainder(stack->start + 1, stack->allocated_size);
	stack->size--;
	return (value);
}

void reverse_rotate(t_stack *stack)
{
	int value;

	value = get(stack, stack->size - 1);
	stack->start = moduler_remainder(stack->start - 1, stack->allocated_size);
	stack->array[stack->start] = value;
	stack->end = moduler_remainder(stack->end - 1, stack->allocated_size);
}

void rotate(t_stack *stack)
{
	int value;

	value = get(stack, 0);
	stack->end = moduler_remainder(stack->end + 1, stack->allocated_size);
	stack->array[stack->end] = value;
	stack->start = moduler_remainder(stack->start + 1, stack->allocated_size);
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
