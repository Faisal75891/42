/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:17:08 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/25 22:17:08 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
