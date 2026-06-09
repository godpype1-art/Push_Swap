/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:52:50 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/09 17:52:25 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, const char **argv)
{
	
	/* t_stack	*stackA;
	t_stack	*stackB;
	int bucket_count; */

	/*t_pushswap *pushswap;

	//pushswap = init_pushswap(1);
	print_bench(pushswap);*/
	parser(argc, argv);
/* 	stackA = init_stack(9);
	stackB = init_stack(stackA->allocated_size);
	push(stackA, 8);
	push(stackA, 9);
	push(stackA, 2);
	push(stackA, 1);
	push(stackA, 3);
	push(stackA, 90);
	push(stackA, 24);
	push(stackA, 4);
	printf("\n======= stackA =======\n\n");
	print_stack(stackA);
	normalize(stackA);
	printf("\n======= stackA =======\n\n");
	printf("(after normalize)\n\n");
	print_stack(stackA);
	printf("\n======= stackB =======\n\n");
	print_stack(stackB);
	printf("\n=== sorting in buckets ===\n\n");
	bucket_count = push_buckets(stackA, stackB);
	printf("\n===== bucket sorted ====\n\n");
	print_stack(stackB);
	printf("\n=== sorting & pushing ===\n\n");
	sort_stack(stackA, stackB, bucket_count);
	printf("\n===== stackB empty =====\n\n");
	print_stack(stackB);
	printf("\n===== stackA sorted =====\n\n");
	print_stack(stackA); */
	return (0);
}
