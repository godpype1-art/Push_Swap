/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:44:40 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/11 19:31:30 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_pushswap *pushswap)
{
	ft_putstr_fd("pa\n", 1);
	push(pushswap->stack_a, pop(pushswap->stack_b));
	pushswap->pa++;
	pushswap->total_ops++;
}

void pb(t_pushswap *pushswap)
{
	ft_putstr_fd("pb\n", 1);
	push(pushswap->stack_b, pop(pushswap->stack_a));
	pushswap->pb++;
	pushswap->total_ops++;
}

void sa(t_pushswap *pushswap)
{
	ft_putstr_fd("sa\n", 1);
	swap_first(pushswap->stack_a);
	pushswap->sa++;
	pushswap->total_ops++;
}

void sb(t_pushswap *pushswap)
{
	ft_putstr_fd("sb\n", 1);
	swap_first(pushswap->stack_b);
	pushswap->sa++;
	pushswap->total_ops++;
}

void ra(t_pushswap *pushswap)
{
	ft_putstr_fd("ra\n", 1);
	rotate(pushswap->stack_a);
	pushswap->ra++;
	pushswap->total_ops++;
}

void rb(t_pushswap *pushswap)
{
	ft_putstr_fd("rb\n", 1);
	rotate(pushswap->stack_b);
	pushswap->rb++;
	pushswap->total_ops++;
}
void rr(t_pushswap *pushswap)
{
	ft_putstr_fd("ra\n", 1);
	rotate(pushswap->stack_a);
	rotate(pushswap->stack_b);
	pushswap->rr++;
	pushswap->total_ops++;
}

void rra(t_pushswap *pushswap)
{
	ft_putstr_fd("rra\n", 1);
	reverse_rotate(pushswap->stack_a);
	pushswap->rra++;
	pushswap->total_ops++;
}

void rrb(t_pushswap *pushswap)
{
	ft_putstr_fd("rrb\n", 1);
	reverse_rotate(pushswap->stack_b);
	pushswap->rrb++;
	pushswap->total_ops++;
}
void rrr(t_pushswap *pushswap)
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

void free_pushswap(t_pushswap *pushswap)
{
	free_stack(pushswap->stack_a);
	if (pushswap->stack_b)
		free_stack(pushswap->stack_b);
	free(pushswap);
}
