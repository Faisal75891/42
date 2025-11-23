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
	if (a->collection[0] < a->collection[1])
		sa(a);
}

int	sort_three(t_stack *a)
{
	int	top;
	int	middle;
	int	max;

	max = find_max(a);
	top = a->collection[2];
	middle = a->collection[1];
	if (top == max)
		ra(a);
	else if (middle == max)
		rra(a);
	top = a->collection[2];
	middle = a->collection[1];
	if (top > middle)
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

void	ft_sort(t_stack *a, t_stack *b)
{
	int	peeked;
	int	sb_index;
	int	i;
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
	else
	{
		// push 3 items into b;
		i = 0;
		while (i < 3 && !is_empty(a))
		{
			pb(a, b);
			i++;
		}
		sort_three_b(b);
		while (!is_empty(a))
		{
			best_move_index = best_index_to_move(a, b); // returns index of the number to push.
			ft_printf("best number to move from a %d\n\n", a->collection[best_move_index]);
			rotate_to_top(a, best_move_index, 0);
			peek(a, &peeked);
			sb_index = smallest_bigger(b, peeked);
			push_into_stack(a, b, sb_index);
		}
		// rotate b back into order.
		put_max_top(b, 1);
		while (!is_empty(b))
			pa(a, b);
		// check if a is sorted just for good measure.
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

	if (argc < 2)
		return (1);
	int_array = malloc(sizeof(int) * argc -1);
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
	print_stack(stack_a, "A initially");
	if (is_sorted(stack_a) == 1)
		ft_printf("");
	else
	{
		ft_sort(stack_a, stack_b);
		if (is_sorted(stack_a) == 1)
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

    // Simulate 3 random numbers as arguments
    int num_args = 7; // Program name + 3 random numbers
    char *argv_test[num_args];
    int argc_test = num_args;

    // Set program name
    argv_test[0] = "./push_swap";

    // Generate and convert random numbers
    for (int i = 1; i < num_args; i++) {
        int random_num = rand() % 100; // Random number between 0 and 99
        char num_str[10]; // Buffer for string conversion
        sprintf(num_str, "%d", random_num);
        argv_test[i] = malloc(ft_strlen(num_str) + 1); // Allocate memory
        ft_strlcpy(argv_test[i], num_str, 10); // Copy string
    }

    // Call the function with simulated arguments
    push_swap(argc_test, argv_test);

    // Free allocated memory
    for (int i = 1; i < num_args; i++) {
        free(argv_test[i]);
    }

    return 0;
}
