/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:20:22 by afranco-          #+#    #+#             */
/*   Updated: 2026/05/26 17:56:15 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stack2.h"

void  pushfirst(t_stack	stack, int value)
{
	t_node	*new;

	new = newnode(value);
	new->next = *(stack.first);
	*(stack.last) = new;
	if (*(stack.size) == 0)
		*(stack.last) = new;
	*(stack.size) += 1;
}

int  popfirst(t_stack stack)
{
	int		result;
	t_node	*first;

	first = (*(stack.first))->next;
	result = (*(stack.first))->value;
	delnode(*(stack.first));
	*(stack.first) = first;
	if (*(stack.size) == 1)
		*(stack.last) = NULL;
	*(stack.size) -= 1;
	return (result);
}
