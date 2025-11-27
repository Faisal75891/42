/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:44:20 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 20:44:20 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	do_rotations(t_stack *stack, int rotations, int is_a)
{
	if (rotations > 0)
	{
		while (rotations-- > 0)
		{
			if (is_a)
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		while (rotations++ < 0)
		{
			if (is_a)
				rra(stack);
			else
				rrb(stack);
		}
	}
}

void	rotate_to_top(t_stack *stack, int index, int is_a)
{
	int	rotations;

	rotations = cost_to_top(stack, index);
	if (rotations == 0)
		return ;
	do_rotations(stack, rotations, is_a);
}

static void	rotate_both_a(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a-- > 0)
		ra(a);
	while (cost_b-- > 0)
		rb(b);
}

static void	rotate_both_b(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	while (cost_a++ < 0)
		rra(a);
	while (cost_b++ < 0)
		rrb(b);
}

void	rotate_both_to_top(t_stack *a, t_stack *b, int a_index, int b_index)
{
	int	cost_a;
	int	cost_b;

	cost_a = cost_to_top(a, a_index);
	cost_b = cost_to_top(b, b_index);
	if (cost_a > 0 && cost_b > 0)
		rotate_both_a(a, b, cost_a, cost_b);
	else if (cost_a < 0 && cost_b < 0)
		rotate_both_b(a, b, cost_a, cost_b);
	else
	{
		rotate_to_top(a, a_index, 0);
		rotate_to_top(b, b_index, 1);
	}
}
