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

static int	choose_operation(t_stack *a, t_stack *b, char *operation)
{
	if (!ft_strncmp(operation, "pb\n", 4))
		pb(a, b);
	else if (!ft_strncmp(operation, "pa\n", 4))
		pa(a, b);
	else if (!ft_strncmp(operation, "sa\n", 4))
		sa(a);
	else if (!ft_strncmp(operation, "sb\n", 4))
		sb(b);
	else if (!ft_strncmp(operation, "ss\n", 4))
		ss(a, b);
	else if (!ft_strncmp(operation, "ra\n", 4))
		ra(a);
	else if (!ft_strncmp(operation, "rb\n", 4))
		rb(b);
	else if (!ft_strncmp(operation, "rr\n", 4))
		rr(a, b);
	else if (!ft_strncmp(operation, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		rrr(a, b);
	else
		return (1);
	return (0);
}

static int	do_operations(t_stack *a, t_stack *b)
{
	char	*operation;
	int		i;
	int		op_check;
	int		error_exit;

	operation = get_operation();
	i = 1;
	error_exit = 0;
	while (operation != NULL)
	{
		op_check = choose_operation(a, b, operation);
		free(operation);
		if (op_check == 1)
			error_exit = -1;
		operation = get_operation();
		i++;
	}
	if (error_exit == -1)
		return (-1);
	if (is_sorted(a) && is_empty(b))
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

int	initialize_stacks(t_stack **a, t_stack **b, int argc, char **argv)
{
	int		*int_array;
	int		capacity;

	int_array = malloc(sizeof(int) * array_size(argc, argv));
	if (!int_array)
		return (1);
	capacity = parse_arguments(argc, argv, int_array);
	if (capacity == 0 || check_for_duplicates(int_array, capacity))
	{
		free(int_array);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	*a = create_stack(capacity);
	*b = create_stack(capacity);
	push_args(*a, int_array, capacity);
	free(int_array);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		result;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	if (initialize_stacks(&a, &b, argc, argv) == 1)
		return (1);
	result = do_operations(a, b);
	if (result == 0)
		ft_printf("OK\n");
	else if (result == 1)
		ft_printf("KO\n");
	else
		ft_putstr_fd("Error\n", 2);
	destroy_stack(a);
	destroy_stack(b);
	return (result);
}
