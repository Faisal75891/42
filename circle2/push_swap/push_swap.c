/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:40:41 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/15 11:15:51 by fbaras           ###   ########.fr       */
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

// takes in either:  1 2 3 4 5 6 7 8 9 10  : argc = 11;
// or             : "1 2 3 4 5 6 7 8 9 10" : argc = 2;
char	**parse_arguments(char **argv)
{
	char **args;
	
	
	return (args);
}

// Takes in an array of ints.
void	push_args(t_stack *a, int *args)
{
	int	i;

	i = 0;
	while (!is_full(a))
	{
		push(a, &args[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	args = parse_arguments(argv);
	stack_a = create_stack(argc);
	push_args(stack_a, args);
	stack_b = create_stack(argc); // leave empty
	ft_sort(stack_a, stack_b);
	return (0);
}
