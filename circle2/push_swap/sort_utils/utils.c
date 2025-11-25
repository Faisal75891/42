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

// Find smallest value in A that is bigger than b_val (for insertion point)
int	smallest_bigger_in_a(t_stack *a, int b_val)
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
		if (val > b_val)
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

// Find cheapest element in B to push back to A
int	best_index_to_move_back(t_stack *b, t_stack *a)
{
	int	total;
	int	min_index;
	int	min;
	int	i;
	int	cost_to_rotate_a;
	int	cost_to_rotate_b;
	int	position;

	min = INT_MAX;
	min_index = -1;
	i = 0;
	while (i < b->size)
	{
		// Find largest value in A smaller than b->collection[i]
		int j = 0;
		int largest_smaller = INT_MIN;
		position = -1;
		
		while (j < a->size)
		{
			if (a->collection[j] < b->collection[i] && a->collection[j] > largest_smaller)
			{
				largest_smaller = a->collection[j];
				position = j;
			}
			j++;
		}
		
		// If no smaller value, insert after max
		if (position == -1)
		{
			int max = find_max(a);
			position = find_position(a, max);
		}
		
		cost_to_rotate_a = cost_to_top(a, position);
		cost_to_rotate_b = cost_to_top(b, i);
		
		// Apply synergy: if both same direction, use combined rotation
		if ((cost_to_rotate_a > 0 && cost_to_rotate_b > 0) ||
			(cost_to_rotate_a < 0 && cost_to_rotate_b < 0))
		{
			int abs_a = cost_to_rotate_a < 0 ? -cost_to_rotate_a : cost_to_rotate_a;
			int abs_b = cost_to_rotate_b < 0 ? -cost_to_rotate_b : cost_to_rotate_b;
			total = (abs_a > abs_b ? abs_a : abs_b) + 1;
		}
		else
		{
			int abs_a = cost_to_rotate_a < 0 ? -cost_to_rotate_a : cost_to_rotate_a;
			int abs_b = cost_to_rotate_b < 0 ? -cost_to_rotate_b : cost_to_rotate_b;
			total = abs_a + abs_b + 1;
		}

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

int	best_index_to_move(t_stack *a, t_stack *b)
{
	int	total;
	int	min_index;
	int	min;
	int	i;
	int	cost_to_rotate_b;
	int	cost_to_rotate_a;
	int	position;

	min = INT_MAX;
	min_index = -1;
	i = 0;
	while (i < a->size)
	{
		position = smallest_bigger(b, a->collection[i]);
		cost_to_rotate_b = cost_to_top(b, position);
		cost_to_rotate_a = cost_to_top(a, i);
		
		// Apply synergy: if both same direction, use combined rotation
		if ((cost_to_rotate_a > 0 && cost_to_rotate_b > 0) ||
			(cost_to_rotate_a < 0 && cost_to_rotate_b < 0))
		{
			int abs_a = cost_to_rotate_a < 0 ? -cost_to_rotate_a : cost_to_rotate_a;
			int abs_b = cost_to_rotate_b < 0 ? -cost_to_rotate_b : cost_to_rotate_b;
			total = (abs_a > abs_b ? abs_a : abs_b) + 1;
		}
		else
		{
			int abs_a = cost_to_rotate_a < 0 ? -cost_to_rotate_a : cost_to_rotate_a;
			int abs_b = cost_to_rotate_b < 0 ? -cost_to_rotate_b : cost_to_rotate_b;
			total = abs_a + abs_b + 1;
		}

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

	//[-1, -2, -3, -4, -5, 5, 4, 3, 2, 1, 0]
	rotations = cost_to_top(stack, index);
	if (rotations == 0)
	{
		return ;
	}
	
	if (a == 0)
	{
		if (rotations > 0)
		{
			while (rotations-- > 0)
				ra(stack);
		}
		else
		{
			while (rotations++ < 0)
				rra(stack);
		}
	}
	else
	{
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
	}
}

void	rotate_both_to_top(t_stack *a, t_stack *b, int a_index, int b_index)
{
	int	cost_a;
	int	cost_b;

	cost_a = cost_to_top(a, a_index);
	cost_b = cost_to_top(b, b_index);

	// Both rotate forward
	if (cost_a > 0 && cost_b > 0)
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
	// Both rotate reverse
	else if (cost_a < 0 && cost_b < 0)
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
	// Different directions - rotate separately
	else
	{
		rotate_to_top(a, a_index, 0);
		rotate_to_top(b, b_index, 1);
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

// Helper to get sorted copy of stack values
int	*get_sorted_values(t_stack *stack)
{
	int	*sorted;
	int	i;
	int	j;
	int	temp;

	if (!stack || stack->size == 0)
		return (NULL);
	sorted = malloc(sizeof(int) * stack->size);
	if (!sorted)
		return (NULL);
	
	// Copy values
	i = 0;
	while (i < stack->size)
	{
		sorted[i] = stack->collection[i];
		i++;
	}
	
	// Simple bubble sort
	i = 0;
	while (i < stack->size - 1)
	{
		j = 0;
		while (j < stack->size - 1 - i)
		{
			if (sorted[j] > sorted[j + 1])
			{
				temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (sorted);
}

void	put_to_bot(t_stack *stack, int index, int a)
{
	int	rotations;

	if (index == 0)
		return ;
	// Calculate how many rotations to get index to bottom (index 0)
	// We need to rotate in opposite direction of cost_to_top
	rotations = index;
	if (a == 0)
	{
		while (rotations-- > 0)
			rra(stack);
	}
	else
	{
		while (rotations-- > 0)
			rrb(stack);
	}
}

void	push_into_stack(t_stack *a, t_stack *b, int sb_index)
{
	// Simply push without maintaining order
	// We'll fix the order at the end with put_max_top
	(void)sb_index;
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
