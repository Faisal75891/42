/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:40:16 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/23 19:40:16 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// This is for parser.c but there is no space there.
int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
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
