/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:52:50 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/10 15:23:49 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, const char **argv)
{
	
	t_pushswap	*bench;

	if (argc < 2)
		return (0);
	bench = init_pushswap(argc);
	if (bench == NULL)
		handle_error();
	else
		parser(argc, argv, bench);
	return (0);
}
