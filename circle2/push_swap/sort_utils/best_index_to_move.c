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

static int	max_two(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

static int	calulate_cost(t_stack *a, t_stack *b, int i)
{
	int	total;
	int	cost_to_rotate_b;
	int	cost_to_rotate_a;
	int	position;

	total = 0;
	position = largest_smaller(b, a->collection[i]);
	if (position == -1)
		position = find_position(b, find_min(b));
	cost_to_rotate_b = cost_to_top(b, position);
	cost_to_rotate_a = cost_to_top(a, i);
	if (cost_to_rotate_a > 0 && cost_to_rotate_b > 0)
		total = max_two(cost_to_rotate_a, cost_to_rotate_b) + 1;
	else if ((cost_to_rotate_a < 0 && cost_to_rotate_b < 0))
		total = max_two(-cost_to_rotate_a, -cost_to_rotate_b) + 1;
	else
	{
		if (cost_to_rotate_a < 0)
			cost_to_rotate_a = -cost_to_rotate_a;
		if (cost_to_rotate_b < 0)
			cost_to_rotate_b = -cost_to_rotate_b;
		total = cost_to_rotate_a + cost_to_rotate_b + 1;
	}
	return (total);
}

static int	calulate_cost_back(t_stack *a, t_stack *b, int b_index)
{
	int	value;
	int	position;
	int	cost_to_rotate_a;
	int	cost_to_rotate_b;
	int	total;

	value = b->collection[b_index];
	position = smallest_bigger(a, value);
	if (position == -1)
		position = find_position(a, find_min(a));
	cost_to_rotate_a = cost_to_top(a, position);
	cost_to_rotate_b = cost_to_top(b, b_index);
	if (cost_to_rotate_a > 0 && cost_to_rotate_b > 0)
		total = max_two(cost_to_rotate_a, cost_to_rotate_b) + 1;
	else if ((cost_to_rotate_a < 0 && cost_to_rotate_b < 0))
		total = max_two(-cost_to_rotate_a, -cost_to_rotate_b) + 1;
	else
	{
		if (cost_to_rotate_a < 0)
			cost_to_rotate_a = -cost_to_rotate_a;
		if (cost_to_rotate_b < 0)
			cost_to_rotate_b = -cost_to_rotate_b;
		total = cost_to_rotate_a + cost_to_rotate_b + 1;
	}
	return (total);
}

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

// Find cheapest element in B to push back to A
int	best_index_to_move_back(t_stack *b, t_stack *a)
{
	int	total;
	int	min_index;
	int	min;
	int	i;

	min = INT_MAX;
	min_index = -1;
	i = 0;
	while (i < b->size)
	{
		total = calulate_cost_back(a, b, i);
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

	min = INT_MAX;
	min_index = -1;
	i = 0;
	while (i < a->size)
	{
		total = calulate_cost(a, b, i);
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
