/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   instructions.c :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: fbaras <fbaras@student.42.fr>  +#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2025/10/15 09:44:47 by fbaras#+##+# */
/*   Updated: 2025/10/15 09:50:04 by fbaras   ###   ########.fr   */
/**/
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;
	int	temp2;

	temp = pop(a, &temp);
	temp2 = pop(a, &temp);
	push(a, temp2);
	push(a, temp);
}

void	sb(t_stack *b)
{
	int	temp;
	int	temp2;

	temp = pop(b, &temp);
	temp2 = pop(b, &temp);
	push(b, temp2);
	push(b, temp);
}

void	ss(t_stack a, t_stack b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	int	item;

	if (b->size == 0)
		return ;
	pop(b, &item);
	push(a, &item);
}

void	pb(t_stack *a, t_stack *b)
{
	int	item;

	if (a->size == 0)
		return ;
	pop(a, &item);
	push(b, &item);
}

void	ra(t_stack *a, t_stack *b)
{
	int	item;
	int	first_item;
	int	elements_moved;

	elements_moved = 0;
	pop(a, &first_item);
	while (!is_empty(a))
	{
		pb(a, b);
		elements_moved++;
	}
	push(a, &first_item);
	while (elements_moved > 0)
	{
		pa(a, b);
		elements_moved--;
	}
}

void	rb(t_stack *a, t_stack *b)
{
	int	item;
	int	first_item;
	int	elements_moved;

	elements_moved = 0;
	pop(b, &first_item);
	while (!is_empty(b))
	{
		pa(a, b);
		elements_moved++;
	}
	push(b, &first_item);
	while (elements_moved > 0)
	{
		pb(a, b);
		elements_moved--;
	}
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, b);
	rb(a, b);
}

void	rra(t_stack *a, t_stack *b)
{
	int	item;
	int	elements_moved;

	elements_moved = 0;
	while (!is_empty(a))
	{
		pb(a, b);
		elements_moved++;
	}
	pop(b, &item);
	while (elements_moved > 0)
	{
		pa(a, b);
		elements_moved--;
	}
	push(a, item);
}

void	rrb(t_stack *a, t_stack *b)
{
	int	item;
	int	elements_moved;

	elements_moved = 0;
	while (!is_empty(b))
	{
		pa(a, b);
		elements_moved++;
	}
	pop(a, &item);
	while (elements_moved > 0)
	{
		pb(a, b);
		elements_moved--;
	}
	push(b, item);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, b);
	rrb(a, b);
}
