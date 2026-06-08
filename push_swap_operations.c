/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:44:40 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/08 19:55:05 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(PushSwap *pushswap)
{
	ft_putstr_fd("pa\n", 1);
	push(pushswap->stackA, pop(pushswap->stackB));
	push_swap->pa++;
	push_swap->total++;
}

void pb(PushSwap *pushswap)
{
	ft_putstr_fd("pb\n", 1);
	push(pushswap->stackB, pop(pushswap->stackA));
	push_swap->pb++;
	push_swap->total++;
}

void ra(PushSwap *pushswap)
{
	ft_putstr_fd("ra\n", 1);
	rotate(pushswap->stackA);
	push_swap->ra++;
	push_swap->total++;
}

void rb(PushSwap *pushswap)
{
	ft_putstr_fd("ra\n", 1);
	rotate(pushswap->stackB);
	push_swap->rb++;
	push_swap->total++;
}
void rr(PushSwap *pushswap)
{
	ft_putstr_fd("ra\n", 1);
	rotate(pushswap->stackA);
	rotate(pushswap->stackB);
	push_swap->rr++;
	push_swap->total++;
}