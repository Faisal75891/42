/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:43:02 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/15 16:14:30 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_stack(int capacity)
{
	t_stack *stack;

	if (capacity <= 0)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
 		return (NULL);
	stack->collection = malloc(sizeof(int) * capacity);
	if (!stack->collection)
	{
		free(stack);
		return (NULL);
	}
	stack->capacity = capacity;
	stack->size = 0;
	return (stack);
}

void	destroy_stack(t_stack *stack)
{
	free(stack->collection);
	free(stack);
}

int	is_full(t_stack *stack)
{
	return (stack->size == stack->capacity);
}

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

int	pop(t_stack *stack, int *item)
{
	if (is_empty(stack))
		return (1);
	*item = stack->collection[stack->size - 1];
	stack->size--;
	return (*item);
}

int	push(t_stack *stack, int *item)
{
	if (is_full(stack))
		return (1);
	stack->collection[stack->size] = *item;
	stack->size++;
	return (0);
}

int	peek(t_stack *stack, int *item)
{
	if (is_empty(stack))
		return (1);
	*item = stack->collection[stack->size - 1];
	return (0);
}

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
