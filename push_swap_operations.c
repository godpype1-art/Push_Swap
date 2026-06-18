/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:44:40 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/18 13:31:08 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pushswap *pushswap)
{
	ft_putstr_fd("pa\n", 1);
	push(pushswap->stack_a, pop(pushswap->stack_b));
	pushswap->pa++;
	pushswap->total_ops++;
}

void	pb(t_pushswap *pushswap)
{
	ft_putstr_fd("pb\n", 1);
	push(pushswap->stack_b, pop(pushswap->stack_a));
	pushswap->pb++;
	pushswap->total_ops++;
}

void	sa(t_pushswap *pushswap)
{
	ft_putstr_fd("sa\n", 1);
	swap_first(pushswap->stack_a);
	pushswap->sa++;
	pushswap->total_ops++;
}

void	sb(t_pushswap *pushswap)
{
	ft_putstr_fd("sb\n", 1);
	swap_first(pushswap->stack_b);
	pushswap->sa++;
	pushswap->total_ops++;
}
