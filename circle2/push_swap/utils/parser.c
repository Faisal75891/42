/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:40:45 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/23 19:40:45 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_one_string(char **argv, int *int_array)
{
	int		last;
	char	**args;
	int		i;

	last = 0;
	if (!argv[1])
		return (0);
	args = ft_split(argv[1], ' ');
	if (!args)
		return (0);
	while (args[last])
		last++;
	last--;
	i = 0;
	while (args[i])
	{
		if (!is_valid_number(args[last]))
			return (0);
		int_array[i] = ft_atoi(args[last]);
		i++;
		last--;
	}
	return (i);
}

// takes in either:  1 2 3 4 5 6 7 8 9 10  : argc = 11;
// or             : "1 2 3 4 5 6 7 8 9 10" : argc = 2;
int	parse_arguments(int argc, char **argv, int *int_array)
{
	int		i;
	int		last;

	if (!argv)
		return (0);
	i = 0;
	last = argc;
	if (argc == 2)
		return (parse_one_string(argv, int_array));
	else
	{
		while (i < argc - 1)
		{
			if (!is_valid_number(argv[last - 1]))
				return (0);
			int_array[i] = ft_atoi(argv[last - 1]);
			i++;
			last--;
		}
	}
	return (i);
}

// Takes in an array of ints.
void	push_args(t_stack *a, int *args, int size)
{
	int	i;

	if (!a || !args)
		return ;
	i = 0;
	while (i < size)
	{
		if (push(a, &args[i]))
			return ;
		i++;
	}
}
