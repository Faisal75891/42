/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:40:41 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/15 17:40:43 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_best_move_in_a(t_stack *a, t_stack *b)
{
	int	peeked;
	int	sb_index;
	int	best_move_index;
	int	min;

<<<<<<< HEAD
void	rotate_to_top(t_stack *stack, int index, int a)
{
	int	rotations;

	rotations = cost_to_top(stack, index);
	if (rotations == 0)
	{
		rra(stack);
		print_stack(stack, "YA");
		return ;
	}
	ft_printf("rotations needed %d to reach top from index %d\n", rotations, index);
	
	if (a == 0)
	{
		print_stack(stack, "A");
		if (rotations > 0)
		{
			while (rotations-- > 1)
				ra(stack);
		}
		else
		{
			while (rotations++ <= 0)
				rra(stack);
		}
		print_stack(stack, "A");
	}
	else
	{
		print_stack(stack, "B");
		if (rotations > 0)
		{
			while (rotations-- > 1)
				rb(stack);
		}
		else
		{
			while (rotations++ <= 0)
				rrb(stack);
		}
		print_stack(stack, "B");
=======
	best_move_index = best_index_to_move(a, b);
	peek_at_index(a, best_move_index, &peeked);
	sb_index = smallest_bigger(b, peeked);
	if (sb_index == -1)
	{
		min = find_min(b);
		sb_index = find_position(b, min);
>>>>>>> 32d832156f7b16884e66701041c3a981eec31d75
	}
	rotate_both_to_top(a, b, best_move_index, sb_index);
	pb(a, b);
}

void	make_best_move_in_b(t_stack *a, t_stack *b)
{
	int	back_index;
	int	target_pos;
	int	peeked;
	int	max;

<<<<<<< HEAD
	max = find_max(stack);
	pos_max = find_position(stack, max);
	if (pos_max == 0)
		return ;
	rotate_to_top(stack, pos_max, a);
}

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
		return ;
	}
	else if (sb_index <= -1)
=======
	back_index = best_index_to_move_back(b, a);
	if (back_index == -1)
		back_index = 0;
	peek_at_index(b, back_index, &peeked);
	target_pos = largest_smaller(a, peeked);
	if (target_pos == -1)
>>>>>>> 32d832156f7b16884e66701041c3a981eec31d75
	{
		max = find_max(a);
		target_pos = find_position(a, max);
	}
	rotate_both_to_top(a, b, target_pos, back_index);
	pa(a, b);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	if (a->capacity == 2)
		sort_two(a);
	else if (a->capacity == 3)
		sort_three(a);
	else if (a->capacity == 4)
		sort_four(a, b);
	else if (a->capacity == 5)
		sort_five(a, b);
	else
	{
		while (a->size > 3)
			make_best_move_in_a(a, b);
		sort_three(a);
		while (!is_empty(b))
			make_best_move_in_b(a, b);
		put_to_bot(a, find_position(a, find_min(a)), 0);
	}
}

void	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*int_array;
	int		capacity;

	int_array = malloc(sizeof(int) * (argc - 1));
	if (!int_array)
		return ;
	capacity = parse_arguments(argc, argv, int_array);
	if (capacity == 0 || check_for_duplicates(int_array, capacity))
	{
		free(int_array);
		ft_printf("Error\n");
		return ;
	}
	stack_a = create_stack(capacity);
	stack_b = create_stack(capacity);
	push_args(stack_a, int_array, capacity);
	ft_sort(stack_a, stack_b);
	print_stack(stack_a, "A");
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	free(int_array);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	push_swap(argc, argv);
}

// #include <stdio.h>
// #include <time.h>
// int main(int argc, char **argv) {
// 	if (argc > 1)
// 		return (push_swap(argc, argv));

//     srand(time(NULL)); // Seed random number generator

//     int num_args = 101;
//     char *argv_test[num_args + 1];
//     int argc_test = num_args;
//     int numbers[num_args];

//     // Generate unique random numbers using shuffle algorithm
//     for (int i = 0; i < num_args; i++) {
//         numbers[i] = i;
//     }

//     // Fisher-Yates shuffle
//     for (int i = num_args - 1; i > 0; i--) {
//         int j = rand() % (i + 1);
//         int temp = numbers[i];
//         numbers[i] = numbers[j];
//         numbers[j] = temp;
//     }

//     // Set program name
//     argv_test[0] = "./push_swap";

//     // Convert shuffled numbers to strings
//     for (int i = 1; i < num_args; i++) {
//         char num_str[10];
//         sprintf(num_str, "%d", numbers[i - 1]);
//         argv_test[i] = malloc(ft_strlen(num_str) + 1);
//         ft_strlcpy(argv_test[i], num_str, 10);
//     }

//     // Call the function with simulated arguments
//     push_swap(argc_test, argv_test);

//     // Free allocated memory
//     for (int i = 1; i < num_args; i++) {
//         free(argv_test[i]);
//     }

//     return 0;
// }
