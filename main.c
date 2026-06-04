/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:52:50 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/04 17:27:40 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
	//int argc, char const *argv[]
	t_stack	*stackA;
	t_stack	*stackB;
	int bucket_count;

	stackA = init_stack(9);
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
	bucket_count = push_buckets(stackA, stackB);
	printf("\n===== bucket sorted ====\n\n");
	print_stack(stackB);
	printf("\n==== reverse sorted ====\n\n");
	sort_stack(stackA, stackB, bucket_count);
	print_stack(stackB);
	return (0);
}
