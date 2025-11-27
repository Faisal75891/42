/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_positioning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:02:03 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 21:02:03 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	put_to_bot(t_stack *stack, int index, int a)
{
	int	rotations;

	if (index == 0)
		return ;
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
