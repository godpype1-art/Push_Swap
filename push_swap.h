/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:52:43 by falves-e          #+#    #+#             */
/*   Updated: 2026/06/16 13:36:26 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
	int	*array;
	int	start;
	int	end;
	int	size;
	int	allocated_size;
}	t_stack;

typedef struct s_pushswap
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		bench;
	float	disorder;
	int		adaptive;
	int		algorithm;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total_ops;
}	t_pushswap;

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

void	parser(int argc, char const *argv[], t_pushswap *bench);
int		ft_is_valid(char *str);
void	handle_error(void);
int		ft_atoi_safe(char *str, int *res);
void	arrange(t_stack *stack, char *tmp, int *nb);
void	convert(const char **argv, t_stack	*stack);
void	create_stack(int argc, char const **argv, t_pushswap *bench);

/*  adaptive sort functions */

void	adaptive_algorithm(t_pushswap *pushswap);
float	disorder_check(t_pushswap *bench);

/*  insertion sort functions */

void	insertion_sort(t_pushswap *pushswap);
void	bubble_sort(t_pushswap *pushswap);
void	radix_sort(t_pushswap *pushswap);
int 	check_sort(t_stack *stack_a);

/*  bucket sort functions */

void	bucket_sort(t_pushswap *bench);
void	normalize(t_pushswap *bench);
int		ranking(t_stack *stackA, int i);
int		buckets(t_pushswap *bench);
void	push_buckets(t_pushswap *bench, int high, int low);
void	sort_stack(t_pushswap *bench);
void	push_highest(t_pushswap *bench, int highest);

/*  merge sort functions */

void 	merge_sorting(t_pushswap *stackA);

/*  other functions */

void	print_bench(t_pushswap *bench);
void	print_stack(t_stack *tsak);
void	free_mem(char **array);
void	handle_error(void);

void pa(t_pushswap *pushswap);
void pb(t_pushswap *pushswap);
void sa(t_pushswap *pushswap);
void sb(t_pushswap *pushswap);
void ra(t_pushswap *pushswap);
void rb(t_pushswap *pushswap);
void rr(t_pushswap *pushswap);
void rra(t_pushswap *pushswap);
void rrb(t_pushswap *pushswap);
void rrr(t_pushswap *pushswap);
t_pushswap	*init_pushswap(int size);

#endif