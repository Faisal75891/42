/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate_to_top.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:26:38 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/23 21:26:38 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "unity.h"

/*
void	rotate_to_top(t_stack *stack, int index, int a)
{
	int	rotations;

	[-1, -2, -3, -4, -5, 5, 4, 3, 2, 1, 0]
	rotations = cost_to_top(stack, index);
	if (rotations == 0)
	{
		print_stack(stack, "YA");
		return ;
	}
	ft_printf("rotations needed %d to reach top from index %d\n", rotations, index);
	
	if (a == 0)
	{
		print_stack(stack, "A");
		if (rotations > 0)
		{
			while (rotations-- > 0)
				rra(stack);
		}
		else
		{
			while (rotations++ < 0)
				ra(stack);
		}
		print_stack(stack, "A");
	}
	else
	{
		print_stack(stack, "B");
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
		print_stack(stack, "B");
	}
}
*/
 
void	setUp(void) {}
void	tearDown(void) {}

void	rotate_b_rrb()
{
	t_stack *b = create_stack(10);
	int		b_array[] = {1, 3, 5, 4, 7};

	int		expected_1[] = {3, 5, 4, 7, 1};
	int		expected_2[] = {4, 7, 1, 3, 5};
	push_args(b, b_array, 5);

	rotate_to_top(b, 0,  1);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_1, b->collection, 5);
	rotate_to_top(b, 1, 1);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_2, b->collection, 5);

	destroy_stack(b);
}

void	rotate_a_rra()
{
	t_stack *a = create_stack(10);
	int		a_array[] = {1, 3, 5, 4, 7};
	
	int		expected_1[] = {3, 5, 4, 7, 1};
	int		expected_2[] = {4, 7, 1, 3, 5};
	push_args(a, a_array, 5);

	rotate_to_top(a, 0, 0);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_1, a->collection, 5);
	rotate_to_top(a, 1, 0);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_2, a->collection, 5);

	destroy_stack(a);
}

void	rotate_b_rb()
{
	t_stack *b = create_stack(10);
	int		b_array[] = {1, 3, 5, 4, 7};

	int		expected_1[] = {7, 1, 3, 5, 4};
	int		expected_2[] = {5, 4, 7, 1, 3};
	int		expected_3[] = {1, 3, 5, 4, 7};
	int		expected_4[] = {1, 3, 5, 4, 7};
	push_args(b, b_array, 5);

	rotate_to_top(b, 3,  1);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_1, b->collection, 5);
	rotate_to_top(b, 2, 1);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_2, b->collection, 5);
	rotate_to_top(b, 2, 1);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_3, b->collection, 5);
	rotate_to_top(b, 4, 1);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_4, b->collection, 5);

	destroy_stack(b);
}

void	rotate_a_ra()
{
	t_stack *a = create_stack(10);
	int		a_array[] = {1, 3, 5, 4, 7};

	int		expected_1[] = {7, 1, 3, 5, 4};
	int		expected_2[] = {5, 4, 7, 1, 3};
	int		expected_3[] = {1, 3, 5, 4, 7};
	int		expected_4[] = {1, 3, 5, 4, 7};
	push_args(a, a_array, 5);

	rotate_to_top(a, 3, 0);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_1, a->collection, 5);
	rotate_to_top(a, 2, 0);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_2, a->collection, 5);
	rotate_to_top(a, 2, 0);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_3, a->collection, 5);
	rotate_to_top(a, 4, 0);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_4, a->collection, 5);

	destroy_stack(a);
}

// FYI: the best number to move is now the top of stack a.
int main(void) {
	UNITY_BEGIN();
	RUN_TEST(rotate_a_ra);
	RUN_TEST(rotate_a_rra);
	RUN_TEST(rotate_b_rb);
	RUN_TEST(rotate_b_rrb);
	return UNITY_END();
}

