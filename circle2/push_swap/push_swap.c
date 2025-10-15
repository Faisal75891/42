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
	while(temp->collection[i])
	{
		if (check > temp->collection[i])
			return (1);
		check = temp->collection[i];
		i++;
	}
	destroy_stack(temp);
	return (0);
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!is_sorted(stack_a))
	{
		
	}
	destroy_stack(stack_a);
	destroy_stack(stack_b);
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
void	parse_arguments(int argc, char **argv, int *int_array)
{
	char	**args;
	int		i;
	int		last;

	i = 0;
	last = argc;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return ;
		while (args[i])
		{
			int_array[i] = ft_atoi(args[last]);
			i++;
			last--;
		}
		return ;
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
}

// Takes in an array of ints.
void	push_args(t_stack *a, int *args)
{
	int	i;

	i = 0;
	while (!is_full(a))
	{
		if (is_full(a))
			return ;
		a->collection[a->size] = args[i];
		a->size++;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*int_array;
	int		temp;

	int_array = malloc(sizeof(int *)*argc -1);
	parse_arguments(argc, argv, int_array);
	stack_a = create_stack(argc);
	push_args(stack_a, int_array);
	pop(stack_a, &temp);
	pop(stack_a, &temp);
	pop(stack_a, &temp);
	ft_printf("%d", temp);
	stack_b = create_stack(argc); // leave empty
	//ft_sort(stack_a, stack_b);
	return (0);
}
