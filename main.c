/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:52:50 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/11 20:29:37 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **argv)
{
	t_pushswap	*bench;

	if (argc < 2)
		return (0);
	bench = init_pushswap(argc);
	if (bench == NULL)
		handle_error();
	else
		parser(argc, argv, bench);
	free_pushswap(bench);
	return (0);
}
