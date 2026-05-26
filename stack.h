/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:58:32 by afranco-          #+#    #+#             */
/*   Updated: 2026/05/26 17:50:23 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_list
{
	int				value;
	struct s_list	*before;
	struct s_list	*next;
}					t_node;

typedef struct s_stack
{
	int					*size;
	struct s_list		**first;
	struct s_list		**last;
}						t_stack;

void	push(t_stack stack, int value);
int		pop(t_stack stack);
void	pushfirst(t_stack stack, int value);
int		popfirst(t_stack stack);
t_stack	init_stack();
