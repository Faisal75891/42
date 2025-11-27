/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_put_max_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:09:51 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 15:09:51 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "unity.h"

void	setUp(void) {}
void	tearDown(void) {}

/*
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
*/

void	max_is_top(void)
{
	t_stack	*a = create_stack(10);
	int		array_a[] = {1, 2, 3, 4, 5};
	push_args(a, array_a, 5);
	int		expected[] = {1, 2, 3, 4, 5};

	put_max_top(a, 0);

	TEST_ASSERT_EQUAL_INT_ARRAY(expected, a->collection, 5);
	destroy_stack(a);
}

void	test_ra(void)
{
	t_stack	*a = create_stack(10);
	int		array_a[] = {1, 2, 3, 10, 5};
	push_args(a, array_a, 5);
	int		expected[] = {5, 1, 2, 3, 10};

	put_max_top(a, 0);

	TEST_ASSERT_EQUAL_INT_ARRAY(expected, a->collection, 5);
	destroy_stack(a);
}

void	test_rra(void)
{
	t_stack	*a = create_stack(10);
	int		array_a[] = {1, 10, 3, 4, 5};
	push_args(a, array_a, 5);
	int		expected[] = {3, 4, 5, 1, 10};

	put_max_top(a, 0);

	TEST_ASSERT_EQUAL_INT_ARRAY(expected, a->collection, 5);
	destroy_stack(a);
}

void	test_max_in_middle(void)
{
	t_stack	*a = create_stack(10);
	int		array_a[] = {1, 2, 10, 4, 5};
	push_args(a, array_a, 5);
	int		expected[] = {4, 5, 1, 2, 10};

	put_max_top(a, 0);

	TEST_ASSERT_EQUAL_INT_ARRAY(expected, a->collection, 5);
	destroy_stack(a);
}

void	test_rrb(void)
{
	t_stack	*b = create_stack(10);
	int		array_b[] = {1, 10, 3, 4, 5};
	push_args(b, array_b, 5);
	int		expected[] = {3, 4, 5, 1, 10};

	put_max_top(b, 1);

	TEST_ASSERT_EQUAL_INT_ARRAY(expected, b->collection, 5);
	destroy_stack(b);
}

void	test_rb(void)
{
	t_stack	*b = create_stack(10);
	int		array_b[] = {1, 2, 3, 10, 5};
	push_args(b, array_b, 5);
	int		expected[] = {5, 1, 2, 3, 10};

	put_max_top(b, 1);

	TEST_ASSERT_EQUAL_INT_ARRAY(expected, b->collection, 5);
	destroy_stack(b);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(max_is_top);
	RUN_TEST(test_ra);
	RUN_TEST(test_rra);
	RUN_TEST(test_max_in_middle);
	RUN_TEST(test_rrb);
	RUN_TEST(test_rb);
	return UNITY_END();
}
