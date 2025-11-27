/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:20:43 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 22:20:43 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_stack(int capacity)
{
	t_stack	*stack;

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
