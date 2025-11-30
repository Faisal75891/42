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
	if (a->collection[0] < a->collection[1])
		sa(a);
}

int	sort_three(t_stack *a)
{
	int	top;
	int	middle;
	int	max;
	int	last;

	max = find_max(a);
	top = a->collection[2];
	middle = a->collection[1];
	if (top == max)
		ra(a);
	else if (middle == max)
		rra(a);
	top = a->collection[2];
	middle = a->collection[1];
	if (top > middle)
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
	if (!a || a->size != 4)
		return ;
	rotate_to_top(a, find_position(a, find_min(a)), 1);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	if (!a || a->size != 5)
		return ;
	rotate_to_top(a, find_position(a, find_min(a)), 1);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
