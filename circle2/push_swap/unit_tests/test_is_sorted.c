/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:10:12 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 15:10:12 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "unity.h"

void	setUp(void) {}
void	tearDown(void) {}

/*
int	is_sorted(t_stack *a)
{
	int i;

	if (!a || a->size <= 1)
		return (1);

	i = 1;
	while (i < a->size)
	{
		if (a->collection[i - 1] < a->collection[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted_descending(t_stack *a)
{
	int i;

	if (!a || a->size <= 1)
		return (1);

	i = 1;
	while (i < a->size)
	{
		if (a->collection[i - 1] > a->collection[i])
			return (0);
		i++;
	}
	return (1);
}

*/

void	test_is_sorted_ascending(void)
{
	t_stack *a = create_stack(10);
	int		array[] = {1, 2, 3, 4, 5};
	push_args(a, array, 5);
	// Stack: [1, 2, 3, 4, 5] - ascending order
	TEST_ASSERT_EQUAL_INT(0, is_sorted(a));
	destroy_stack(a);
}

void	test_is_sorted_descending(void)
{
	t_stack *a = create_stack(10);
	int		array[] = {5, 4, 3, 2, 1};
	push_args(a, array, 5);
	// Stack: [5, 4, 3, 2, 1] - descending order (sorted for our purpose)
	TEST_ASSERT_EQUAL_INT(1, is_sorted(a));
	destroy_stack(a);
}

void	test_is_sorted_unsorted(void)
{
	t_stack *a = create_stack(10);
	int		array[] = {3, 1, 4, 2, 5};
	push_args(a, array, 5);
	// Stack: [3, 1, 4, 2, 5] - unsorted
	TEST_ASSERT_EQUAL_INT(0, is_sorted(a));
	destroy_stack(a);
}

void	test_is_sorted_single_element(void)
{
	t_stack *a = create_stack(10);
	int		array[] = {42};
	push_args(a, array, 1);
	// Single element is always sorted
	TEST_ASSERT_EQUAL_INT(1, is_sorted(a));
	destroy_stack(a);
}

void	test_is_sorted_empty(void)
{
	t_stack *a = create_stack(10);
	// Empty stack is considered sorted
	TEST_ASSERT_EQUAL_INT(1, is_sorted(a));
	destroy_stack(a);
}

void	test_is_sorted_two_elements_sorted(void)
{
	t_stack *a = create_stack(10);
	int		array[] = {2, 1};
	push_args(a, array, 2);
	// Stack: [2, 1] - descending (sorted)
	TEST_ASSERT_EQUAL_INT(1, is_sorted(a));
	destroy_stack(a);
}

void	test_is_sorted_two_elements_unsorted(void)
{
	t_stack *a = create_stack(10);
	int		array[] = {1, 2};
	push_args(a, array, 2);
	// Stack: [1, 2] - ascending (not sorted for us)
	TEST_ASSERT_EQUAL_INT(0, is_sorted(a));
	destroy_stack(a);
}

void	test_is_sorted_descending_func_ascending(void)
{
	t_stack *a = create_stack(10);
	int		array[] = {1, 2, 3, 4, 5};
	push_args(a, array, 5);
	// Stack: [1, 2, 3, 4, 5] - ascending order
	TEST_ASSERT_EQUAL_INT(1, is_sorted_descending(a));
	destroy_stack(a);
}

void	test_is_sorted_descending_func_descending(void)
{
	t_stack *a = create_stack(10);
	int		array[] = {5, 4, 3, 2, 1};
	push_args(a, array, 5);
	// Stack: [5, 4, 3, 2, 1] - descending order
	TEST_ASSERT_EQUAL_INT(0, is_sorted_descending(a));
	destroy_stack(a);
}

void	test_is_sorted_descending_func_unsorted(void)
{
	t_stack *a = create_stack(10);
	int		array[] = {3, 1, 4, 2, 5};
	push_args(a, array, 5);
	// Stack: [3, 1, 4, 2, 5] - unsorted
	TEST_ASSERT_EQUAL_INT(0, is_sorted_descending(a));
	destroy_stack(a);
}

void	test_is_sorted_with_duplicates(void)
{
	t_stack *a = create_stack(10);
	int		array[] = {5, 5, 3, 2, 1};
	push_args(a, array, 5);
	// Stack: [5, 5, 3, 2, 1] - has duplicates but descending
	// Note: push_swap typically doesn't allow duplicates, but test the function
	TEST_ASSERT_EQUAL_INT(0, is_sorted(a));
	destroy_stack(a);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_is_sorted_ascending);
	RUN_TEST(test_is_sorted_descending);
	RUN_TEST(test_is_sorted_unsorted);
	RUN_TEST(test_is_sorted_single_element);
	RUN_TEST(test_is_sorted_empty);
	RUN_TEST(test_is_sorted_two_elements_sorted);
	RUN_TEST(test_is_sorted_two_elements_unsorted);
	RUN_TEST(test_is_sorted_descending_func_ascending);
	RUN_TEST(test_is_sorted_descending_func_descending);
	RUN_TEST(test_is_sorted_descending_func_unsorted);
	RUN_TEST(test_is_sorted_with_duplicates);
	return UNITY_END();
}
