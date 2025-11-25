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

void	sort_two(t_stack *a)
{
	if (a->collection[0] > a->collection[1])
		sa(a);
}

int	sort_three(t_stack *a)
{
	int	top;
	int	middle;
	int	min;

	min = find_min(a);
	top = a->collection[2];
	middle = a->collection[1];
	if (top == min)
		ra(a);
	else if (middle == min)
		rra(a);
	top = a->collection[2];
	middle = a->collection[1];
	if (top < middle)
		sa(a);
	int last = a->collection[2];
	return (last);
}

int	sort_three_b(t_stack *b)
{
	int	top;
	int	middle;
	int	min;

	min = find_min(b);
	top = b->collection[2];
	middle = b->collection[1];
	if (top == min)
		rb(b);
	else if (middle == min)
		rrb(b);
	top = b->collection[2];
	middle = b->collection[1];
	if (top < middle)
		sb(b);
	top = b->collection[2];
	return (top);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	if (!a || a->size != 4)
		return ;
	min = find_min(a);
	pos = find_position(a, min);
	rotate_to_top(a, pos, 0);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	if (!a || a->size != 5)
		return ;
	min = find_min(a);
	pos = find_position(a, min);
	rotate_to_top(a, pos, 0);
	pb(a, b);
	min = find_min(a); // second minimum after removal
	pos = find_position(a, min);
	rotate_to_top(a, pos, 0);
	pb(a, b);
	sort_three(a);
	// Push back the two mins; current top of B is second min (larger of the two)
	pa(a, b);
	pa(a, b);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	int	peeked;
	int	sb_index;
	int	best_move_index;

	if (a->capacity == 2)
	{
		sort_two(a);
		return ;
	}
	else if (a->capacity == 3)
	{
		sort_three(a);
		return ;
	}
	else if (a->capacity == 4)
	{
		sort_four(a, b);
		return ;
	}
	else if (a->capacity == 5)
	{
		sort_five(a, b);
		return ;
	}
	else
	{
		// Push all but 3 to B using cost-based selection
		while (a->size > 3)
		{
			best_move_index = best_index_to_move(a, b);
			peek_at_index(a, best_move_index, &peeked);
			sb_index = smallest_bigger(b, peeked);
			if (sb_index == -1)
			{
				int min = find_min(b);
				sb_index = find_position(b, min);
			}
			
			// Use simultaneous rotation when beneficial
			rotate_both_to_top(a, b, best_move_index, sb_index);
			pb(a, b);
		}
		// Sort final 3 in A
		sort_three(a);
		while (!is_empty(b))
		{
			int back_index = best_index_to_move_back(b, a);
			if (back_index == -1)
				back_index = 0;
			peek_at_index(b, back_index, &peeked);
			
			// Find largest value in A smaller than peeked (where to insert AFTER)
			int target_pos = -1;
			int largest_smaller = INT_MIN;
			int i = 0;
			
			while (i < a->size)
			{
				if (a->collection[i] < peeked && a->collection[i] > largest_smaller)
				{
					largest_smaller = a->collection[i];
					target_pos = i;
				}
				i++;
			}
			
			if (target_pos == -1)
			{
				// Element is smaller than everything - insert after max
				int max = find_max(a);
				target_pos = find_position(a, max);
			}
			
			// Use simultaneous rotation when beneficial
			rotate_both_to_top(a, b, target_pos, back_index);
			pa(a, b);
		}
		// Final rotation: put min at index 0 (bottom) for ascending order
		int min = find_min(a);
		int min_pos = find_position(a, min);
		// Rotate to put min at bottom (index 0)
		if (min_pos <= a->size / 2)
		{
			while (min_pos-- > 0)
				rra(a);
		}
		else
		{
			while (min_pos++ < a->size)
				ra(a);
		}
	}
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*int_array;
	int		capacity;

	if (argc == 1)
		return (1);
	int_array = malloc(sizeof(int) * (argc - 1));
	if (!int_array)
		return (1);
	capacity = parse_arguments(argc, argv, int_array);
	if (capacity == 0)
	{
		free(int_array);
		ft_printf("Error\n");
		return (1);
	}
	stack_a = create_stack(capacity);
	stack_b = create_stack(capacity);
	push_args(stack_a, int_array, capacity);
	//print_stack(stack_a, "A initially");
	if (is_sorted_descending(stack_a) == 1)
		ft_printf("");
	else
	{
		ft_sort(stack_a, stack_b);
		if (is_sorted_descending(stack_a) == 1)
		{
			//print_stack(stack_a, "A after sort");
			//ft_printf("sorted!\n");
		}
		else
		{
			print_stack(stack_a, " ");
			ft_printf("not sorted!!\n");
		}
	}
	return (0);
}

#include <stdio.h>
#include <time.h>
int main(int argc, char **argv) {
	if (argc > 1)
		return (push_swap(argc, argv));

    srand(time(NULL)); // Seed random number generator

    int num_args = 501;
    char *argv_test[num_args + 1];
    int argc_test = num_args;
    int numbers[num_args];
    
    // Generate unique random numbers using shuffle algorithm
    for (int i = 0; i < num_args; i++) {
        numbers[i] = i;
    }
    
    // Fisher-Yates shuffle
    for (int i = num_args - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Set program name
    argv_test[0] = "./push_swap";

    // Convert shuffled numbers to strings
    for (int i = 1; i < num_args; i++) {
        char num_str[10];
        sprintf(num_str, "%d", numbers[i - 1]);
        argv_test[i] = malloc(ft_strlen(num_str) + 1);
        ft_strlcpy(argv_test[i], num_str, 10);
    }

    // Call the function with simulated arguments
    push_swap(argc_test, argv_test);

    // Free allocated memory
    for (int i = 1; i < num_args; i++) {
        free(argv_test[i]);
    }

    return 0;
}
