/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:09:10 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 22:09:10 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	if (!a || a->size <= 1)
		return (1);
	i = 1;
	while (i < a->size)
	{
		if (a->collection[i - 1] <= a->collection[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted_descending(t_stack *a)
{
	int	i;

	if (!a || a->size <= 1)
		return (1);
	i = 1;
	while (i < a->size)
	{
		if (a->collection[i - 1] >= a->collection[i])
			return (0);
		i++;
	}
	return (1);
}
