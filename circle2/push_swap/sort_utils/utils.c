/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:41:39 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/23 19:41:39 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Moves the cheapest value to move from a to b.

	Cost to push from a to b is:
		distance of the index from the median, + 1 pb()
	Cost to rotate list in b:
		distance from the index of the target(sb) to the median
	Total Cost = cost to push + cost to rotate

	keep track of the lowest cost in the stack and return it.
	stack: [2, 5, 9, 80, 54, ...]
	array: [2, 3, 1, 4 , 5 , ...] <- each element is the cost value.
	               ^
	then get the index of the minimum_value
	this means i will try to push the element at index 2 or value 9.
*/ 
int	best_index_to_move(t_stack *a, t_stack *b)
{
	int	total;
	int	min_index;
	int	min;
	int	i;

	min = INT_MAX;
	min_index = -1;
	i = 0;
	while (i < a->size)
	{
	// 	position = smallest_bigger(b, a->collection[i]);
	// 	cost_to_rotate = cost_to_top(b, position);
	// 	total = cost_to_rotate + cost_to_top(a, a->collection[i]);
		total = cost_to_top(b, smallest_bigger(b, a->collection[i])) + cost_to_top(a, i);
		if (total < min)
		{
			min = total;
			min_index = i;
		}
		i++;
	}
	if (min_index < 0)
		return (-1);
	return (min_index);		
}

void	rotate_to_top(t_stack *stack, int index, int a)
{
	int	rotations;

	rotations = cost_to_top(stack, index);
	if (rotations == 0)
	{
		print_stack(stack, "YA");
		return ;
	}
	ft_printf("rotations needed %d to reach top from index %d\n", rotations, index);
	
	if (a == 0)
	{
		print_stack(stack, "A");
		if (rotations > 0)
		{
			while (rotations-- > 0)
				rra(stack);
		}
		else
		{
			while (rotations++ < 0)
				ra(stack);
		}
		print_stack(stack, "A");
	}
	else
	{
		print_stack(stack, "B");
		if (rotations > 0)
		{
			while (rotations-- > 0)
				rb(stack);
		}
		else
		{
			while (rotations++ < 0)
				rrb(stack);
		}
		print_stack(stack, "B");
	}
}

void	put_max_top(t_stack *stack, int a)
{
	int	pos_max;
	int	max;

	max = find_max(stack);
	pos_max = find_position(stack, max);
	if (pos_max == 0)
		return ;
	rotate_to_top(stack, pos_max, a);
}

void	push_into_stack(t_stack *a, t_stack *b, int sb_index)
{
	int	max;
	//int i;
	// rotate stack b to make sb the top.
	// if sb == 0 -> pb(a, b), sb() then exit 1
	// if sb == stack->size do non
	// if sb == -1. rotate max to top
	// else rra/ra unitl sb == stack->size
	if (sb_index == 0)
		return ;
	else if (sb_index == a->size - 1)
	{
		pb(a, b);
		sb(b);
	}
	else if (sb_index <= -1)
	{
		max = find_position(b, find_max(b));
		rotate_to_top(b, max, 1);
	}
	else
	{
		rotate_to_top(b, sb_index, 1);
		rb(b);
	}
	print_stack(a, "A");
	print_stack(b, "B");
	pb(a, b);
}

int	smallest_bigger(t_stack *a, int b)
{
	int	i;
	int	sb_found;
	int	sb_index;
	int	val;

	if (!a || a->size == 0)
		return (-1);
	i = a->size - 1;
	sb_found = 0;
	val = 0;
	sb_index = -1;

	while (i >= 0)
	{
		val = a->collection[i];
		if (val > b)
		{
			if (!sb_found || val < a->collection[sb_index])
			{
				sb_found = 1;
				sb_index = i;
			}
		}
		i--;
	}
	return (sb_index);
}
