/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:19:14 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 22:19:14 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	peek_at_index(t_stack *stack, int index, int *item)
{
	if (!stack || index < 0 || index >= stack->size)
		return (1);
	*item = stack->collection[index];
	return (0);
}

int	find_min(t_stack *stack)
{
	int	min;
	int	i;

	if (is_empty(stack))
		return (0);
	min = stack->collection[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->collection[i] < min)
			min = stack->collection[i];
		i++;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	max;
	int	i;

	if (is_empty(stack))
		return (-1);
	max = stack->collection[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->collection[i] > max)
			max = stack->collection[i];
		i++;
	}
	return (max);
}

int	cost_to_top(t_stack *stack, int position)
{
	int	rotate_cost;
	int	reverse_rotate_cost;

	if (position < 0)
		position = find_position(stack, find_max(stack));
	if (position == stack->size - 1)
		return (0);
	rotate_cost = stack->size - 1 - position;
	reverse_rotate_cost = position + 1;
	if (rotate_cost <= reverse_rotate_cost)
		return (rotate_cost);
	else
		return (-reverse_rotate_cost);
}

int	find_position(t_stack *a, int b)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->collection[i] == b)
			return (i);
		i++;
	}
	return (-1);
}
