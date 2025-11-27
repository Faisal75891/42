/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:52:50 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/26 15:52:50 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	choose_operation(t_stack *a, t_stack *b, char *operation)
{
	if (!ft_strncmp(operation, "pb", 4))
		pb(a, b);
	else if (!ft_strncmp(operation, "pa", 4))
		pa(a, b);
	else if (!ft_strncmp(operation, "sa", 4))
		sa(a);
	else if (!ft_strncmp(operation, "sb", 4))
		sb(b);
	else if (!ft_strncmp(operation, "ss", 4))
		ss(a, b);
	else if (!ft_strncmp(operation, "ra", 4))
		ra(a);
	else if (!ft_strncmp(operation, "rb", 4))
		rb(b);
	else if (!ft_strncmp(operation, "rr", 4))
		rr(a, b);
	else if (!ft_strncmp(operation, "rra", 5))
		rra(a);
	else if (!ft_strncmp(operation, "rrb", 5))
		rrb(b);
	else if (!ft_strncmp(operation, "rrr", 5))
		rrr(a, b);
	else
		return ;
}

static int	do_operations(t_stack *a, t_stack *b)
{
	char	*operation;

	operation = get_operation();
	while (operation != NULL)
	{
		choose_operation(a, b, operation);
		operation = get_operation();
	}
	if (is_sorted(a))
		return (0);
	else
		return (1);
}

/*
 ./push_swap "1 2 4 3 5 7 9" 
pb
pb
pb
rrb
pb
pa
rr
pa
pa
rb
rb
rb
pa
rra
rra
rra

./push_swap "1 2 4 3 5 7 9" | ./checker/checker "1 2 4 3 5 7 9"
*/

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int		capacity;
	int		*int_array;
	int		result = 0;

	if (argc < 2)
		return (1);
	int_array = malloc (sizeof(int) * (argc - 1));
	if (!int_array)
		return (1);
	capacity = parse_arguments(argc, argv, int_array);
	if (capacity == 0 || check_for_duplicates(int_array, capacity))
	{
		free(int_array);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a = create_stack(capacity);	
	b = create_stack(capacity);	
	push_args(a, int_array, capacity);
	result = do_operations(a, b);
	print_stack(a, "A");
	if (result == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	else if (result == 0)
	{
		ft_printf("OK\n");
		print_stack(a, "A");
		print_stack(b, "B");
		return (0);
	}
	else
	{
		ft_printf("KO\n");
		print_stack(a, "A");
		print_stack(b, "B");
		return (1);
	}
	destroy_stack(a);
	destroy_stack(b);
	return (0);
}
