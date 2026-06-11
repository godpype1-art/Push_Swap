/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:22:32 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/11 20:46:40 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_algorithm(t_pushswap *bench, int fd)
{
	if (bench->adaptive == 1)
	{
		if (bench->algorithm == 1)
			ft_putstr_fd("Adaptive / O(n*n)\n", fd);
		else if (bench->algorithm == 2)
			ft_putstr_fd("Adaptive / O(n√n)\n", fd);
		else if (bench->algorithm == 3)
			ft_putstr_fd("Adaptive / O(nlogn)\n", fd);
	}
	else
	{
		if (bench->algorithm == 1)
			ft_putstr_fd("Simple / O(n*n)\n", fd);
		if (bench->algorithm == 2)
			ft_putstr_fd("Medium / O(n√n)\n", fd);
		if (bench->algorithm == 3)
			ft_putstr_fd("Complex / O(nlogn)\n", fd);
	}
}

static void	print_ops(t_pushswap *bench, int fd)
{
	ft_putstr_fd("[bench] total_ops: ", fd);
	ft_putnbr_fd(bench->total_ops, fd);
	ft_putstr_fd("\n[bench] sa: ", fd);
	ft_putnbr_fd(bench->sa, fd);
	ft_putstr_fd(" sb: ", fd);
	ft_putnbr_fd(bench->sb, fd);
	ft_putstr_fd(" ss: ", fd);
	ft_putnbr_fd(bench->ss, fd);
	ft_putstr_fd(" pa: ", fd);
	ft_putnbr_fd(bench->pa, fd);
	ft_putstr_fd(" pb: ", fd);
	ft_putnbr_fd(bench->pb, fd);
	ft_putstr_fd("\n[bench] ra: ", fd);
	ft_putnbr_fd(bench->ra, fd);
	ft_putstr_fd(" rb: ", fd);
	ft_putnbr_fd(bench->rb, fd);
	ft_putstr_fd(" rr: ", fd);
	ft_putnbr_fd(bench->rr, fd);
	ft_putstr_fd(" rra: ", fd);
	ft_putnbr_fd(bench->rra, fd);
	ft_putstr_fd(" rrb: ", fd);
	ft_putnbr_fd(bench->rrb, fd);
	ft_putstr_fd(" rrr: ", fd);
	ft_putnbr_fd(bench->rrr, fd);
	ft_putchar_fd('\n', fd);
}

void	print_bench(t_pushswap *bench)
{
	int	fd;
	int	whole;
	int	decimal;

	fd = 2;
	whole = (int)(bench->disorder * 100);
	decimal = (int)(bench->disorder * 10000) % 100;
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_putnbr_fd(whole, fd);
	ft_putchar_fd('.', fd);
	ft_putnbr_fd(decimal, fd);
	ft_putstr_fd("%\n[bench] strategy: ", fd);
	print_algorithm(bench, fd);
	print_ops(bench, fd);
}
