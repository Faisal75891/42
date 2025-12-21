/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_best_index_to_move.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:08:12 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/24 20:08:12 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../circle2/push_swap/push_swap.h"
#include "unity.h"

void	setUp(void) {}
void	tearDown(void) {}

/*
	Moves the cheapest value to move from a to b.

	Cost to push from a to b is:
		distance of the index from the median, + 1 pb()
		i.e cost to top.
	Cost to rotate list in b:
		distance from the index of the target(sb) from the median
		i.e cost to top from index sb.
	Total Cost = cost to push + cost to rotate

	keep track of the lowest cost in the stack and return it.
	stack: [2, 5, 9, 80, 54, ...]
	array: [2, 3, 1, 4 , 5 , ...] <- each element is the cost value.
	              ^
	then get the index of the minimum_value
	this means i will try to push the element at index 2 or value 9.

==================================================================================================

int	best_index_to_move(t_stack *a, t_stack *b)
{
	int	total;
	int	min_index;
	int	min;
	int	i;
	int	cost_to_rotate_b;
	int	cost_to_rotate_a;
	int	position;

	min = INT_MAX;
	min_index = -1;
	i = 0;
	while (i < a->size)
	{
		position = smallest_bigger(b, a->collection[i]);
		cost_to_rotate_b = cost_to_top(b, position);
		if (cost_to_rotate_b < 0)
			cost_to_rotate_b = -cost_to_rotate_b;
		cost_to_rotate_a = cost_to_top(a, a->collection[i]);
		if (cost_to_rotate_a < 0)
			cost_to_rotate_a = -cost_to_rotate_a;
		total = cost_to_rotate_b + cost_to_rotate_a + 1;

		//total = cost_to_top(b, smallest_bigger(b, a->collection[i])) + cost_to_top(a, i);
		ft_printf("ctr_a %d & ctr_b %d\n", cost_to_rotate_a, cost_to_rotate_b);
		ft_printf("ft_printf total cost for index %d of value %d is %d\n", i, a->collection[i], total);
		if (total < min)
		{
			min = total;
			min_index = i;
		}
		i++;
	}
	if (min_index < 0)
		return (-1);
	return (min_index);
}
*/


void	all_cases(void)
{
	t_stack *a = create_stack(10);
	t_stack *b = create_stack(10);
	int		array_a[] = {3, 2, 4, 5};
	int		array_b[] = {7, 9, 6, 1};
	push_args(a, array_a, 4);
	push_args(b, array_b, 4);
	// Stack A: [3, 2, 4, 5] (5 is top)
	// Stack B: [7, 9, 6, 1] (1 is top)
	// cost for "3" (idx 0): max(3,1) + 1 = 4
	// cost for "2" (idx 1): max(2,1) + 1 = 3
	// cost for "4" (idx 2): max(1,1) + 1 = 2
	// cost for "5" (idx 3): 0 + 1 + 1 = 2
	// best index to move is index 2 (first minimum), value "4"
	TEST_ASSERT_EQUAL_INT(2, best_index_to_move(a, b));
	destroy_stack(a);
	destroy_stack(b);
}

void	test_element_at_bottom(void)
{
	t_stack *a = create_stack(10);
	t_stack *b = create_stack(10);
	int		array_a[] = {1, 8, 9, 10};
	int		array_b[] = {2, 3, 4, 5};
	push_args(a, array_a, 4);
	push_args(b, array_b, 4);
	// Stack A: [1, 8, 9, 10] (10 is top)
	// Stack B: [2, 3, 4, 5] (5 is top)
	// Value 1 at bottom (idx 0) should have highest cost
	// Value 10 at top (idx 3) should be cheaper
	int result = best_index_to_move(a, b);
	TEST_ASSERT_TRUE(result == 3);
	destroy_stack(a);
	destroy_stack(b);
}

void	test_all_smaller_than_b(void)
{
	t_stack *a = create_stack(10);
	t_stack *b = create_stack(10);
	int		array_a[] = {1, 2, 3, 4};
	int		array_b[] = {10, 20, 30, 40};
	push_args(a, array_a, 4);
	push_args(b, array_b, 4);
	// All elements in A are smaller than all in B
	// smallest_bigger should return -1, which means find max position
	// Both index 0 and 3 tie at cost 2, so returns first (index 0)
	int result = best_index_to_move(a, b);
	TEST_ASSERT_EQUAL_INT(0, result);
	destroy_stack(a);
	destroy_stack(b);
}

void	test_mixed_positions(void)
{
	t_stack *a = create_stack(10);
	t_stack *b = create_stack(10);
	int		array_a[] = {15, 5, 25, 10};
	int		array_b[] = {8, 20, 30, 12};
	push_args(a, array_a, 4);
	push_args(b, array_b, 4);
	// Stack A: [15, 5, 25, 10] (10 is top)
	// Stack B: [8, 20, 30, 12] (12 is top)
	// Different elements will have different target positions in B
	int result = best_index_to_move(a, b);
	TEST_ASSERT_TRUE(result == 3);
	destroy_stack(a);
	destroy_stack(b);
}

void	test_single_element_in_a(void)
{
	t_stack *a = create_stack(10);
	t_stack *b = create_stack(10);
	int		array_a[] = {5};
	int		array_b[] = {1, 2, 3, 4};
	push_args(a, array_a, 1);
	push_args(b, array_b, 4);
	// Only one element in A, should return index 0
	TEST_ASSERT_EQUAL_INT(0, best_index_to_move(a, b));
	destroy_stack(a);
	destroy_stack(b);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(all_cases);
	RUN_TEST(test_element_at_bottom);
	RUN_TEST(test_all_smaller_than_b);
	RUN_TEST(test_mixed_positions);
	RUN_TEST(test_single_element_in_a);
	return UNITY_END();
}
