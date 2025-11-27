/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:17:02 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 22:17:02 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->collection[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->collection[i] = a->collection[i - 1];
		i--;
	}
	a->collection[0] = temp;
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->collection[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->collection[i] = b->collection[i - 1];
		i--;
	}
	b->collection[0] = temp;
	ft_printf("rb\n");
}

static void	rotate_a(t_stack *a)
{
	int	temp;
	int	i;

	temp = a->collection[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->collection[i] = a->collection[i - 1];
		i--;
	}
	a->collection[0] = temp;
}

void	rr(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	if (a->size >= 2)
		rotate_a(a);
	if (b->size >= 2)
	{
		temp = b->collection[b->size - 1];
		i = b->size - 1;
		while (i > 0)
		{
			b->collection[i] = b->collection[i - 1];
			i--;
		}
		b->collection[0] = temp;
	}
	ft_printf("rr\n");
}
