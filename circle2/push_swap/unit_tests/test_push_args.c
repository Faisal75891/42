/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 23:34:32 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/23 23:34:32 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "unity.h"

/*
void	push_args(t_stack *a, int *args, int size)
{
	int	i;
	
	if (!a || !args)
		return ;
	i = 0;
	while (i < size)
	{
		a->collection[a->size] = args[i];
		a->size++;
		i++;
	}
}
*/

// push_args(stack_a, int_array, capacity);

void	setUp(void) {}
void	tearDown(void) {}

void	test_push_multiple_elements(void)
{
	t_stack *a = create_stack(4);
	int int_array[] = {1, 3, 4, 2};
	
	push_args(a, int_array, 4);
	
	TEST_ASSERT_EQUAL_INT(4, a->size);
	TEST_ASSERT_EQUAL_INT_ARRAY(int_array, a->collection, 4);
	destroy_stack(a);
}

void	test_push_single_element(void)
{
	t_stack *a = create_stack(1);
	int int_array[] = {42};
	
	push_args(a, int_array, 1);
	
	TEST_ASSERT_EQUAL_INT(1, a->size);
	TEST_ASSERT_EQUAL_INT(42, a->collection[0]);
	destroy_stack(a);
}

void	test_push_zero_elements(void)
{
	t_stack *a = create_stack(5);
	int int_array[] = {1, 2, 3};
	
	push_args(a, int_array, 0);
	
	TEST_ASSERT_EQUAL_INT(0, a->size);
	destroy_stack(a);
}

void	test_push_negative_numbers(void)
{
	t_stack *a = create_stack(4);
	int int_array[] = {-5, -10, 0, 15};
	
	push_args(a, int_array, 4);
	
	TEST_ASSERT_EQUAL_INT_ARRAY(int_array, a->collection, 4);
	destroy_stack(a);
}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_push_multiple_elements);
	RUN_TEST(test_push_single_element);
	RUN_TEST(test_push_zero_elements);
	RUN_TEST(test_push_negative_numbers);
	return UNITY_END();
}
