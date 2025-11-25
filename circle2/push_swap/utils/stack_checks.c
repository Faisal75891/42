/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:20:23 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 22:20:23 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_full(t_stack *stack)
{
	return (stack->size == stack->capacity);
}

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}
