/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:52:43 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/04 17:12:03 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

//REMOVE LATER
#include <stdio.h>

typedef struct s_stack
{
	int	*array;
	int	start;
	int	end;
	int	size;
	int	allocated_size;
}	t_stack;

t_stack	*init_stack(int size);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	reallocate(t_stack *stack, int newsize);
int		get(t_stack	*stack, int indice);
void	reverse_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	swap_first(t_stack *stack);
void	parser(int argc, char const *argv[]);
int		ft_is_valid(char *str);
void	handle_error(void);
void	adaptive_algorythm(t_stack *stackA);
float	disorder_check(t_stack *stackA);
void	insertion_sort(t_stack *stackA);
void	print_stack(t_stack *tsak);
void	bucket_sort(t_stack *stackA);
void	normalize(t_stack *stackA);
int		push_buckets(t_stack *stackA, t_stack *stackB);
void	sort_stack(t_stack *stackA, t_stack *stackB, int bucket_count);

#endif