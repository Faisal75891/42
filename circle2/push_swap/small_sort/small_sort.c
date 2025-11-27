/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:45:52 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 22:45:52 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->collection[0] > a->collection[1])
		sa(a);
}

int	sort_three(t_stack *a)
{
	int	top;
	int	middle;
	int	min;
	int	last;

	min = find_min(a);
	top = a->collection[2];
	middle = a->collection[1];
	if (top == min)
		ra(a);
	else if (middle == min)
		rra(a);
	top = a->collection[2];
	middle = a->collection[1];
	if (top < middle)
		sa(a);
	last = a->collection[2];
	return (last);
}

int	sort_three_b(t_stack *b)
{
	int	top;
	int	middle;
	int	min;

	min = find_min(b);
	top = b->collection[2];
	middle = b->collection[1];
	if (top == min)
		rb(b);
	else if (middle == min)
		rrb(b);
	top = b->collection[2];
	middle = b->collection[1];
	if (top < middle)
		sb(b);
	top = b->collection[2];
	return (top);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	if (!a || a->size != 4)
		return ;
	min = find_min(a);
	pos = find_position(a, min);
	rotate_to_top(a, pos, 0);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	if (!a || a->size != 5)
		return ;
	min = find_min(a);
	pos = find_position(a, min);
	rotate_to_top(a, pos, 0);
	pb(a, b);
	min = find_min(a);
	pos = find_position(a, min);
	rotate_to_top(a, pos, 0);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
