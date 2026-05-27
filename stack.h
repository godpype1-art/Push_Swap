/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:58:32 by afranco-          #+#    #+#             */
/*   Updated: 2026/05/27 18:04:13 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int	*array;
	int	start;
	int	end;
	int	size;
	int	allocated_size;
}	t_stack;

t_stack	*init_stack(int size);
void push(t_stack *stack, int value);
int pop(t_stack *stack);
void reallocate(t_stack *stack, int newsize);
int	get(t_stack	*stack, int indice);
void reverse_rotate(t_stack *stack);
void rotate(t_stack *stack);
void swap_first(t_stack *stack);
