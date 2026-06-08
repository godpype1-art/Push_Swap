/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:52:43 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/08 18:07:15 by falves-e         ###   ########.fr       */
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

/*  stack functions */

t_stack	*init_stack(int size);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	reallocate(t_stack *stack, int newsize);
int		get(t_stack	*stack, int indice);
void	reverse_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	swap_first(t_stack *stack);

/*  parser functions */

void	parser(int argc, char const *argv[]);
int		ft_is_valid(char *str);
void	handle_error(void);
int		ft_atoi_safe(char *str, int *res);
void	arrange(t_stack *stack, char *tmp, int *nb);
void	convert(const char **argv, t_stack	*stack);
void	create_stack(int argc, char const **argv, int function, int bench);

/*  adaptive sort functions */

void	adaptive_algorythm(t_stack *stackA);
float	disorder_check(t_stack *stackA);

/*  insertion sort functions */

void	insertion_sort(t_stack *stackA);

/*  bucket sort functions */

void	bucket_sort(t_stack *stackA);
void	normalize(t_stack *stackA);
int		ranking(t_stack *stackA, int i);
int		buckets(t_stack *stackA, t_stack *stackB);
void	push_buckets(t_stack *stackA, t_stack *stackB, int high, int low);
void	sort_stack(t_stack *stackA, t_stack *stackB, int bucket_count);
int		highest_index(t_stack *stackB, int high, int low);
void	push_highest(t_stack *stackA, t_stack *stackB, int limit);

/*  other functions */

void	print_stack(t_stack *tsak);
void	free_mem(char **array);
void	handle_error(void);

#endif