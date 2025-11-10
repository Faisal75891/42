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

//failed on:
// -312, 686, -819, 321, 267
// 237 126 -346 -325 -166 -442
// 925 141 -278 -898 -930 -655
// 104 121 662 385 235 -89 -761 168 -781

void	ft_sort(t_stack *a, t_stack *b)
{
	int	peeked;
	int	sb_index;
	int	i;
	int	max;
	int max_pos;

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
		max = sort_three_b(b);
		while (!is_empty(a))
		{
			peek(a, &peeked);
			if (peeked > max)
				max = peeked;
			sb_index = smallest_bigger(b, peeked);
			//print_stack(a, "A");
			//ft_printf("top of a: %d\n", a->collection[a->size - 1]);
			//print_stack(b, "B");
			//ft_printf("top of b: %d\n", b->collection[b->size - 1]);
			//ft_printf("sb: %d is %d\n", sb_index, b->collection[sb_index]);
			if (sb_index < 0)
			{
				//ft_printf("PEEKED IS %d\n", peeked);
				max = find_max(b);
				max_pos = find_position(b, max);
				//ft_printf("max num: %d %d %d\n", b->collection[max_pos], max_pos, max);
				if (max_pos > b->size / 2)
				{
					while (max_pos < b->size -1)
					{
						rb(b);
						//print_stack(b, "B!!");
						//ft_printf("max: %d\n", max_pos);
						max_pos++;
					}
					pb(a, b);
				}
				else
				{
					while (max_pos >= 0)
					{
						rrb(b);
						//print_stack(b, "B!!");
						max_pos--;
					}
					pb(a, b);
				}
			}
			else if (sb_index == 0)
			{
				pb(a, b);
				continue ;
			}
			else if (sb_index == b->size - 1)
			{
				pb(a, b);
				sb(b);
				continue ;
			}
			else
			{
				if (sb_index > (b->size)/ 2)
				{
					i = 0;
					int rots = b->size - sb_index;
					while (i < rots)
					{
						rb(b);
						//print_stack(b, "B");
						i++;
					}
				}
				else
				{
					i = 0;
					while (i < sb_index)
					{
						rrb(b);
						i++;
					}
				}
				pb(a, b);
				//print_stack(b, "B");
			}
		}
		max_pos = find_position(b, max);
		if (max_pos > b->size / 2)
		{
			while (max_pos < b->size -2)
			{
				rb(b);
				//print_stack(b, "B!!");
				//ft_printf("max: %d\n", max_pos);
				max_pos++;
			}
		}
		else
		{
			while (max_pos >= -1)
			{
				rrb(b);
				//print_stack(b, "B!!");
				max_pos--;
			}
		}
		while (!is_empty(b))
			pa(a, b);
		if (!is_sorted_descending(a))
		{
			max = find_max(a);
			max_pos = find_position(a, max);
			if (max_pos > a->size / 2)
			{
				while (max_pos < a->size -2)
				{
					ra(a);
					//print_stack(b, "B!!");
					//ft_printf("max: %d\n", max_pos);
					max_pos++;
				}
			}
			else
			{
				while (max_pos > -1)
				{
					rra(a);
					//print_stack(b, "B!!");
					max_pos--;
				}
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
