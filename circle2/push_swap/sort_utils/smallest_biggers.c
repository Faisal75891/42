/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_biggers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:03:42 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 21:03:42 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	smallest_bigger(t_stack *a, int b)
{
	int	i;
	int	sb_found;
	int	sb_index;
	int	val;

	if (!a || a->size == 0)
		return (-1);
	i = a->size - 1;
	sb_found = 0;
	sb_index = -1;
	while (i >= 0)
	{
		val = a->collection[i];
		if (val > b)
		{
			if (!sb_found || val < a->collection[sb_index])
			{
				sb_found = 1;
				sb_index = i;
			}
		}
		i--;
	}
	return (sb_index);
}

int	smallest_bigger_in_a(t_stack *a, int b_val)
{
	int	i;
	int	sb_found;
	int	sb_index;
	int	val;

	if (!a || a->size == 0)
		return (-1);
	i = a->size - 1;
	sb_found = 0;
	sb_index = -1;
	while (i >= 0)
	{
		val = a->collection[i];
		if (val > b_val)
		{
			if (!sb_found || val < a->collection[sb_index])
			{
				sb_found = 1;
				sb_index = i;
			}
		}
		i--;
	}
	return (sb_index);
}

int	largest_smaller(t_stack *a, int value)
{
	int	candidate;
	int	pos;
	int	i;

	if (!a || a->size == 0)
		return (-1);
	candidate = INT_MIN;
	pos = -1;
	i = 0;
	while (i < a->size)
	{
		if (a->collection[i] < value && a->collection[i] > candidate)
		{
			candidate = a->collection[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}
