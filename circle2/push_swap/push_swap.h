/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:40:37 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/15 11:05:41 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <fcntl.h>

typedef struct s_stack
{
	int *collection;
	int capacity;
	int size;
} t_stack;

t_stack	*create_stack(int capacity);
void	destroy_stack(t_stack *stack);
int		is_full(t_stack *stack);
int		is_empty(t_stack *stack);
int		pop(t_stack *stack, int *item);
int		push(t_stack *stack, int *item);
int		peek(t_stack *stack, int *item);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a, t_stack *b);
void	rb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, t_stack *b);
void	rrb(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif