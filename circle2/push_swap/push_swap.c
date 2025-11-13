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

/*
	Moves the cheapest value to move from a to b.

	Cost to push from a to b is:
		distance of the index from the median, + 1 pb()
	Cost to rotate list in b:
		distance from the index of the target(sb) to the median
	Total Cost = cost to push + cost to rotate

	keep track of the lowest cost in the stack and return it.
	stack: [2, 5, 9, 80, 54, ...]
	array: [2, 3, 1, 4 , 5 , ...] <- each element is the cost value.
	               ^
	then get the index of the minimum_value
	this means i will try to push the element at index 2 or value 9.
*/ 
int	best_index_to_move(t_stack *a, t_stack *b)
{
	int	total;
	int	min_index;
	int	min;
	int	i;

	min = INT_MAX;
	min_index = -1;
	i = 0;
	while (i < a->size)
	{
	// 	position = smallest_bigger(b, a->collection[i]);
	// 	cost_to_rotate = cost_to_top(b, position);
	// 	total = cost_to_rotate + cost_to_top(a, a->collection[i]);
		total = cost_to_top(b, smallest_bigger(b, a->collection[i])) + cost_to_top(a, i);
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

void	rotate_to_top(t_stack *stack, int index, int a)
{
	int	rotations;

	rotations = cost_to_top(stack, index);
	if (rotations == 0)
	{
		print_stack(stack, "YA");
		return ;
	}
	ft_printf("rotations needed %d to reach top from index %d\n", rotations, index);
	
	if (a == 0)
	{
		print_stack(stack, "A");
		if (rotations > 0)
		{
			while (rotations-- > 0)
				rra(stack);
		}
		else
		{
			while (rotations++ < 0)
				ra(stack);
		}
		print_stack(stack, "A");
	}
	else
	{
		print_stack(stack, "B");
		if (rotations > 0)
		{
			while (rotations-- > 0)
				rb(stack);
		}
		else
		{
			while (rotations++ < 0)
				rrb(stack);
		}
		print_stack(stack, "B");
	}
}

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
	}
	else if (sb_index <= -1)
	{
		max = find_position(b, find_max(b));
		rotate_to_top(b, max, 1);
	}
	else
	{
		rotate_to_top(b, sb_index, 1);
		rb(b);
	}
	print_stack(a, "A");
	print_stack(b, "B");
	pb(a, b);
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

// takes in either:  1 2 3 4 5 6 7 8 9 10  : argc = 11;
// or             : "1 2 3 4 5 6 7 8 9 10" : argc = 2;
int	parse_arguments(int argc, char **argv, int *int_array)
{
	char	**args;
	int		i;
	int		last;
	int		atoi_check;

	i = 0;
	last = argc;
	if (argc == 2)
	{
		last = 0;
		args = ft_split(argv[1], ' ');
		if (!args)
			return (0);
		while (args[last])
			last++;
		last--;
		while(args[i])
		{
			atoi_check = ft_atoi(args[last]);
			if (atoi_check > 0)
				int_array[i] = atoi_check;
			else
			{
				return (0);
			}
			i++;
			last--;
		}
		return (i);
	}
	else
	{
		while (i < argc - 1)
		{
			int_array[i] = ft_atoi(argv[last - 1]);
			i++;
			last--;
		}
	}
	return(i);
}

// Takes in an array of ints.
void	push_args(t_stack *a, int *args, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		a->collection[a->size] = args[i];
		a->size++;
		i++;
	}
}

void	print_stack(t_stack *stack, char *name)
{
	int	i;

	ft_printf("Stack %s (size=%d): [", name, stack->size);
	i = 0;
	while (i < stack->size)
	{
		ft_printf("%d", stack->collection[i]);
		if (i < stack->size - 1)
			ft_printf(", ");
		i++;
	}
	ft_printf("]\n");
}

int	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*int_array;
	int		capacity;

	int_array = malloc(sizeof(int *) * argc -1);
	capacity = parse_arguments(argc, argv, int_array);
	if (capacity == 0)
	{
		free(int_array);
		return (0);
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
