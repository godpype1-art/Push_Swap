/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:51:39 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/11 20:29:13 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pushswap *pushswap)
{
	ft_putstr_fd("ra\n", 1);
	rotate(pushswap->stack_a);
	pushswap->ra++;
	pushswap->total_ops++;
}

void	rb(t_pushswap *pushswap)
{
	ft_putstr_fd("rb\n", 1);
	rotate(pushswap->stack_b);
	pushswap->rb++;
	pushswap->total_ops++;
}

void	rr(t_pushswap *pushswap)
{
	ft_putstr_fd("ra\n", 1);
	rotate(pushswap->stack_a);
	rotate(pushswap->stack_b);
	pushswap->rr++;
	pushswap->total_ops++;
}
