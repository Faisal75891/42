/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:16:47 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 22:16:47 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
