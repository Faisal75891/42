/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_find_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:10:35 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 15:10:35 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../circle2/push_swap/push_swap.h"
#include "unity.h"

void	setUp(void) {}
void	tearDown(void) {}

/*
int	find_position(t_stack *a, int b)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->collection[i] == b)
			return (i);
		i++;
	}
	return (-1);
}
*/

void	normal_case(void)
{
	t_stack	*a = create_stack(10);
	int		array_a[] = {1, 2, 3, 4, 5};
	push_args(a, array_a, 5);

	TEST_ASSERT_EQUAL_INT(0, find_position(a, 1));
	TEST_ASSERT_EQUAL_INT(1, find_position(a, 2));
	TEST_ASSERT_EQUAL_INT(2, find_position(a, 3));
	TEST_ASSERT_EQUAL_INT(3, find_position(a, 4));
	TEST_ASSERT_EQUAL_INT(4, find_position(a, 5));
	destroy_stack(a);
}

void	not_found(void)
{
	t_stack	*a = create_stack(10);
	int		array_a[] = {1, 2, 3, 4, 5};
	push_args(a, array_a, 5);

	TEST_ASSERT_EQUAL_INT(-1, find_position(a, 20));
	destroy_stack(a);
}

void	empty_stack(void)
{
	t_stack	*a = create_stack(10);
	int		array_a[] = {1, 2, 3, 4, 5};

	TEST_ASSERT_EQUAL_INT(-1, find_position(a, 20));
	destroy_stack(a);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(normal_case);
	RUN_TEST(not_found);
	RUN_TEST(empty_stack);
	return UNITY_END();
}
