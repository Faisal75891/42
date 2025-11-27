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
	pb (a, b);
}
*/

void	setUp(void) {}
void	tearDown(void) {}

void	normal_case()
{
	t_stack *a = create_stack(10);
	t_stack *b = create_stack(10);
	int		a_array[] = {1, 3, 5, 4, 7};
	int		b_array[] = {2, 6, 9, 8, 10};
	//   						  ^
	int		expected_a[] = {1, 3, 5, 4, 7, 8};
	int		expected_b[] = {10, 2, 6, 9};
	push_args(a, a_array, 5);
	push_args(b, b_array, 5);

	push_into_stack(a, b, 3);

	TEST_ASSERT_EQUAL_INT_ARRAY(expected_a, a->collection, 6);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_b, b->collection, 4);
	destroy_stack(a);
	destroy_stack(b);
}

// FYI: the best number to move is now the top of stack a.
int main(void) {
	UNITY_BEGIN();
	RUN_TEST(normal_case);
	return UNITY_END();
}
