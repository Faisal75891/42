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
	int		check;
	int		i;
	t_stack	*temp;

	temp = a;
	i = 0;
	check = 0;
	while(i < temp->size)
	{
		if (check > temp->collection[i])
			return (0);
		check = temp->collection[i];
		i++;
	}
	return (1);
}

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	if (a->size != 3)
		return;
	
	bot = a->collection[0];
	mid = a->collection[1];
	top = a->collection[2];
	
	if (bot < mid && mid > top && bot > top)
		sa(a);
	else if (bot < mid && mid < top)
	{
		sa(a);
		rra(a);
	}
	else if (bot < top && top < mid)
		ra(a);
	else if (bot > mid && mid < top && bot > top)
	{
		rra(a);
		sa(a);
	}
	else if (bot > mid && mid < top && bot < top)
		rra(a);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	//int	popped;
	int	peeked;
	int	sb;
	int	i;
	int	min_index;

	i = 0;
	while (a->size > 3)
		pb(a, b);
	//ft_printf("sorthing three...\n");
	sort_three(a);
	while (!is_empty(b))
	{
		peek(b, &peeked);
		sb = smallest_bigger(a, peeked);
		//ft_printf("smallest bigger than %d is at %d\n", peeked, sb);
		while (i < sb)
		{
			ra(a);
			i++;
		}
		pa(a, b);
		i = 0;
	}
	min_index = find_position(a, find_max(a));
	while (min_index-- > 0)
		ra(a);
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
	
	i = size - 1;
	while (i >= 0)
	{
		a->collection[a->size] = args[i];
		a->size++;
		i--;
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
	ft_sort(stack_a, stack_b);
	print_stack(stack_a, "A"); 
	int		temp;
	if (is_sorted(stack_a))
		ft_printf("sorted!\n");
	while (!is_empty(stack_a))
	{
		pop(stack_a, &temp);
		ft_printf("%d, ", temp);
	}
	write(1, "\n", 1);
	return (0);
}
