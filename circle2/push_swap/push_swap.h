/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:40:37 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/15 17:12:34 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_stack
{
	int *collection;
	int capacity;
	int size;
} t_stack;

t_stack	*create_stack(int capacity);
void	destroy_stack(t_stack *stack);
void	rotate_to_top(t_stack *stack, int index, int a);
int		is_full(t_stack *stack);
int		is_empty(t_stack *stack);
int		pop(t_stack *stack, int *item);
int		push(t_stack *stack, int *item);
int		peek(t_stack *stack, int *item);
int		is_sorted(t_stack *a);
void	ft_sort(t_stack *stack_a, t_stack *stack_b);
void	free_split(char **arr);
int		parse_arguments(int argc, char **argv, int *int_array);
void	push_args(t_stack *a, int *args, int size);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		smallest_bigger(t_stack *a, int b);
int		cost_to_top(t_stack *stack, int position);
int		find_position(t_stack *a, int b);
void	print_stack(t_stack *stack, char *name);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif