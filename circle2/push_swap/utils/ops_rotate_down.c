/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:16:55 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 22:16:55 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->collection[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->collection[i] = a->collection[i + 1];
		i++;
	}
	a->collection[a->size - 1] = temp;
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->collection[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->collection[i] = b->collection[i + 1];
		i++;
	}
	b->collection[b->size - 1] = temp;
	ft_printf("rrb\n");
}

static void	reverse_rotate_a(t_stack *a)
{
	int	temp;
	int	i;

	temp = a->collection[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->collection[i] = a->collection[i + 1];
		i++;
	}
	a->collection[a->size - 1] = temp;
}

void	rrr(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	if (a->size >= 2)
		reverse_rotate_a(a);
	if (b->size >= 2)
	{
		temp = b->collection[0];
		i = 0;
		while (i < b->size - 1)
		{
			b->collection[i] = b->collection[i + 1];
			i++;
		}
		b->collection[b->size - 1] = temp;
	}
	ft_printf("rrr\n");
}
