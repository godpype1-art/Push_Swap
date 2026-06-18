/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:50:41 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/18 19:54:51 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_pushswap *pushswap)
{
	ft_putstr_fd("rra\n", 1);
	reverse_rotate(pushswap->stack_a);
	pushswap->rra++;
	pushswap->total_ops++;
}

void	rrb(t_pushswap *pushswap)
{
	ft_putstr_fd("rrb\n", 1);
	reverse_rotate(pushswap->stack_b);
	pushswap->rrb++;
	pushswap->total_ops++;
}

void	rrr(t_pushswap *pushswap)
{
	ft_putstr_fd("rrr\n", 1);
	reverse_rotate(pushswap->stack_a);
	reverse_rotate(pushswap->stack_b);
	pushswap->rrr++;
	pushswap->total_ops++;
}

t_pushswap	*init_pushswap(int size)
{
	t_pushswap	*bench;

	bench = malloc(sizeof(t_pushswap));
	if (bench == NULL)
		return (NULL);
	bench->stack_a = init_stack(size);
	bench->stack_b = NULL;
	bench->bench = 0;
	bench->disorder = 0.0f;
	bench->adaptive = 0;
	bench->algorithm = 0;
	bench->total_ops = 0;
	bench->error = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	return (bench);
}

void	free_pushswap(t_pushswap *pushswap)
{
	free_stack(pushswap->stack_a);
	if (pushswap->stack_b)
		free_stack(pushswap->stack_b);
	free(pushswap);
}
