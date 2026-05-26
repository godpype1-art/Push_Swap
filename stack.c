/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:02:49 by afranco-          #+#    #+#             */
/*   Updated: 2026/05/26 17:52:31 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*newnode(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = content;
	node->before = NULL;
	node->next = NULL;
	return (node);
}

void	delnode(t_node *lst)
{
	if (lst == NULL)
		return ;
	free(lst);
}

void  push(t_stack	stack, int value)
{
	t_node	*new;

	new = newnode(value);
	new->before = *(stack.last);
	*(stack.last) = new;
	if (*(stack.size) == 0)
		*(stack.first) = new;
	*(stack.size) += 1;
}

int  pop(t_stack stack)
{
	int		result;
	t_node	*last;

	last = (*(stack.last))->before;
	result = (*(stack.last))->value;
	delnode(*(stack.last));
	*(stack.last) = last;
	if (*(stack.size) == 1)
		*(stack.first) = NULL;
	*(stack.size) -= 1;
	return (result);
}

t_stack	init_stack()
{
	t_stack	stack;

	stack.size = malloc(sizeof(int));
	stack.size[0] = 0;
	stack.first = malloc(sizeof(t_node *));
	stack.first[0] = NULL;
	stack.last = malloc(sizeof(t_node *));
	stack.last[0] = NULL;
	return stack;
}
