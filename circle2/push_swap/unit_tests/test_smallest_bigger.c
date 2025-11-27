/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_smallest_bigger.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:32:43 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/23 21:32:43 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include "unity.h"

/*
int	smallest_bigger(t_stack *a, int b)
{
	int	i;
	int	sb_found;
	int	sb_index;
	int	val;

	if (!a || a->size == 0)
		return (-1);
	i = a->size - 1;
	sb_found = 0;
	val = 0;
	sb_index = -1;

	while (i >= 0)
	{
		val = a->collection[i];
		if (val > b)
		{
			if (!sb_found || val < a->collection[sb_index])
			{
				sb_found = 1;
				sb_index = i;
			}
		}
		i--;
	}
	return (sb_index);
}
*/

void	setUp(void) {}
void	tearDown(void) {}

void	test_functionallity(void)
{
	int	val1 = 2;
	int	val2 = 10;
	int	val3 = 6;
	int	val4 = 5;
	int	val5 = 4;
	int	val6 = 3;
	int	val7 = 8;
	int	val8 = 5;
	t_stack *a = create_stack(8);
	TEST_ASSERT_EQUAL_INT(-1, smallest_bigger(a, 5));
	push(a, &val1); push(a, &val2); push(a, &val3); push(a, &val4); push(a, &val5);
	// [2, 10, 6, 5, 4]
	TEST_ASSERT_EQUAL_INT(2, smallest_bigger(a, 5));
	push(a, &val6); push(a, &val7); push(a, &val8); push(a, &val8);
	// [2, 10, 6, 5, 4, 3, 8, 5]
	TEST_ASSERT_EQUAL_INT(6, smallest_bigger(a, 7));
	TEST_ASSERT_EQUAL_INT(1, smallest_bigger(a, 8));
	// no bigger
	TEST_ASSERT_EQUAL_INT(-1, smallest_bigger(a, 20));
	destroy_stack(a);
}

void	test_null(void)
{
	t_stack *a = NULL;
	TEST_ASSERT_EQUAL_INT(-1, smallest_bigger(a, 5));
}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_functionallity);
	RUN_TEST(test_null);
	return UNITY_END();
}
