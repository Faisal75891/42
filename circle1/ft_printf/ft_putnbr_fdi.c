/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrfd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 22:30:36 by fbaras            #+#    #+#             */
/*   Updated: 2025/08/06 22:30:36 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int ft_putnbr_fdi(int n, int i, int fd)
{
    long num;

    num = n;
    if (num < 0)
    {
        i = ft_putchar_fdi('-', fd);
        num = -num;
    }
    if (num > 9)
        i += ft_putnbr_fdi(num / 10, 0, fd);
    i += ft_putchar_fdi(num % 10 + '0', fd);
	return (i);
}