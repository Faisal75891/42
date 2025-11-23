/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_into_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 23:50:34 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/23 23:50:34 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "unity.h"

/*

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
*/

void	setUp(void) {}
void	tearDown(void) {}

void	()
{

}

int main(void) {
	UNITY_BEGIN();
	return UNITY_END();
}
