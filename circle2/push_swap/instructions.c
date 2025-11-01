/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:42:41 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/16 15:42:41 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;
	int	temp2;

	pop(a, &temp);
	pop(a, &temp2);
	push(a, &temp);
	push(a, &temp2);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	int	temp;
	int	temp2;

	pop(b, &temp);
	pop(b, &temp2);
	push(b, &temp);
	push(b, &temp2);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;
	int	temp2;

	pop(a, &temp);
	pop(a, &temp2);
	push(a, &temp2);
	push(a, &temp);
	pop(b, &temp);
	pop(b, &temp2);
	push(b, &temp2);
	push(b, &temp);
	ft_printf("ss\n");
}

void	pa(t_stack *a, t_stack *b)
{
	int	item;

	if (b->size == 0)
		return ;
	pop(b, &item);
	push(a, &item);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	int	item;

	if (a->size == 0)
		return ;
	pop(a, &item);
	push(b, &item);
	ft_printf("pb\n");
}

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return;
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
		return;
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

void	rr(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;
	
	if (a->size >= 2)
	{
		temp = a->collection[a->size - 1];
		i = a->size - 1;
		while (i > 0)
		{
			a->collection[i] = a->collection[i - 1];
			i--;
		}
		a->collection[0] = temp;
	}
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

void	rra(t_stack *a)
{
	int	temp;
	int	i;
	
	if (a->size < 2)
		return;
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
		return;
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

void	rrr(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;
	
	if (a->size >= 2)
	{
		temp = a->collection[0];
		i = 0;
		while (i < a->size - 1)
		{
			a->collection[i] = a->collection[i + 1];
			i++;
		}
		a->collection[a->size - 1] = temp;
	}
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
