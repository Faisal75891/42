/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_find_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:24:01 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 15:24:01 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "unity.h"

void	setUp(void) {}
void	tearDown(void) {}

/*
int	find_max(t_stack *stack)
{
	int	max;
	int	i;

	if (is_empty(stack))
		return (-1);
	max = stack->collection[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->collection[i] > max)
			max = stack->collection[i];
		i++;
	}
	return (max);
}
*/

void	normal_case(void)
{
	t_stack	*a = create_stack(10);
	int		array_a[] = {1, 6, 200, 4, 5};
	push_args(a, array_a, 5);

	TEST_ASSERT_EQUAL_INT(200, find_max(a));

	destroy_stack(a);
}

void	normal_case2(void)
{
	t_stack	*a = create_stack(10);
	int		array_a[] = {1, 2, 3, 4, 5};
	push_args(a, array_a, 5);

	TEST_ASSERT_EQUAL_INT(5, find_max(a));
	destroy_stack(a);
}

void	empty_stack(void)
{
	t_stack	*a = create_stack(10);
	int		array_a[] = {1, 2, 3, 4, 5};

	TEST_ASSERT_EQUAL_INT(-1, find_max(a));
	destroy_stack(a);
}


int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(normal_case);
	RUN_TEST(normal_case2);
	RUN_TEST(empty_stack);
	return UNITY_END();
}