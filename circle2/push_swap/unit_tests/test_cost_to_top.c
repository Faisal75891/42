/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cost_to_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:27:36 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/24 19:27:36 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "unity.h"

void	setUp(void) {}
void	tearDown(void) {}

/*

int	cost_to_top(t_stack *stack, int position)
{
	int	rotate_cost;
	int	reverse_rotate_cost;

	//if (position < 0)
	//	position = find_position(stack, find_max(stack));
	if (position == stack->size - 1)
		return (0);
	rotate_cost = stack->size - 1 - position;
	reverse_rotate_cost = position + 1;
	if (rotate_cost <= reverse_rotate_cost)
		return (rotate_cost);
	else
		return (-reverse_rotate_cost);
}

*/

void	test_size_11_all_positions(void)
{
	t_stack *a = create_stack(11);
	int array[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	push_args(a, array, 11);

	TEST_ASSERT_EQUAL_INT(-1, cost_to_top(a, 0));
	TEST_ASSERT_EQUAL_INT(-2, cost_to_top(a, 1));
	TEST_ASSERT_EQUAL_INT(-3, cost_to_top(a, 2));
	TEST_ASSERT_EQUAL_INT(-4, cost_to_top(a, 3));
	TEST_ASSERT_EQUAL_INT(-5, cost_to_top(a, 4));
	TEST_ASSERT_EQUAL_INT(5, cost_to_top(a, 5));
	TEST_ASSERT_EQUAL_INT(4, cost_to_top(a, 6));
	TEST_ASSERT_EQUAL_INT(3, cost_to_top(a, 7));
	TEST_ASSERT_EQUAL_INT(2, cost_to_top(a, 8));
	TEST_ASSERT_EQUAL_INT(1, cost_to_top(a, 9));
	TEST_ASSERT_EQUAL_INT(0, cost_to_top(a, 10));
	
	destroy_stack(a);
}

void	test_size_2(void)
{
	t_stack *a = create_stack(5);
	int array[2] = {1, 2};
	push_args(a, array, 2);
	
	// Stack: [1, 2] where 2 is top (index 1)
	TEST_ASSERT_EQUAL_INT(1, cost_to_top(a, 0));
	TEST_ASSERT_EQUAL_INT(0, cost_to_top(a, 1));  // top needs 0
	
	destroy_stack(a);
}

void	test_size_3(void)
{
	t_stack *a = create_stack(5);
	int array[3] = {1, 2, 3};
	push_args(a, array, 3);
	
	// Stack: [1, 2, 3] where 3 is top (index 2)
	TEST_ASSERT_EQUAL_INT(-1, cost_to_top(a, 0)); // 2 ra vs 1 rra -> choose rra
	TEST_ASSERT_EQUAL_INT(1, cost_to_top(a, 1));  // 1 ra vs 2 rra -> choose ra
	TEST_ASSERT_EQUAL_INT(0, cost_to_top(a, 2));  // already top
	
	destroy_stack(a);
}

void	test_single_element(void)
{
	t_stack *a = create_stack(5);
	int array[1] = {42};
	push_args(a, array, 1);
	
	// Single element is always at top
	TEST_ASSERT_EQUAL_INT(0, cost_to_top(a, 0));
	
	destroy_stack(a);
}

void	test_size_10_even(void)
{
	t_stack *a = create_stack(10);
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	push_args(a, array, 10);
	
	// Even size: positions 0-4 should use rra, 5-9 should use ra
	TEST_ASSERT_EQUAL_INT(-1, cost_to_top(a, 0));
	TEST_ASSERT_EQUAL_INT(5, cost_to_top(a, 4));
	TEST_ASSERT_EQUAL_INT(4, cost_to_top(a, 5));  // 4 ra vs 6 rra -> choose ra
	TEST_ASSERT_EQUAL_INT(0, cost_to_top(a, 9));
	
	destroy_stack(a);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_size_11_all_positions);
	RUN_TEST(test_size_2);
	RUN_TEST(test_size_3);
	RUN_TEST(test_single_element);
	RUN_TEST(test_size_10_even);
	return UNITY_END();
}
