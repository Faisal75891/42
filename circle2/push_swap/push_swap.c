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

void	sort_two(t_stack *a)
{
	if (a->collection[0] < a->collection[1])
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	top;
	int	middle;
	int	last;
	int	max;

	max = find_max(a);
	top = a->collection[2];
	middle = a->collection[1];
	last = a->collection[0];
	if (top == max)
		ra(a);
	else if (middle == max)
		rra(a);
	top = a->collection[2];
	middle = a->collection[1];
	last = a->collection[0];
	if (top > middle)
		sa(a);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	int	peeked;
	int	sb_index;
	int	i;

	if (a->capacity == 2)
		sort_two(a);
	else if (a->capacity == 3)
		sort_three(a);
	else
	{
		while (a->size != 3)
			pb(a, b);
		if (a->size == 3)
			sort_three(a);
		else
			ft_printf("no\n");
		peek(b, &peeked);
		while (!is_empty(b))
		{
			print_stack(a, "A");
			print_stack(b, "B");
			sb_index = smallest_bigger(a, peeked); //gets the index;
			ft_printf("sb: %d\n", sb_index);
			if (sb < 0)
				pa(a, b);
			else
			{
				i = 0;
				while (i < sb_index - 1)
				{
					ra(a);
					i++;
				}
				pa(a, b);
			}
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

int	main(int argc, char **argv)
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
	if (is_sorted(stack_a) == 1)
		ft_printf("sorted!\n");
	else
	{
		ft_sort(stack_a, stack_b);
		if (is_sorted(stack_a) == 1)
		{
			print_stack(stack_a, "A after sort");
			ft_printf("sorted!\n");
		}
		else
		{
			print_stack(stack_a, " ");
			ft_printf("not sorted!!\n");
		}
	}
	return (0);
}
