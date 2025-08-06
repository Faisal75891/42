/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:57:15 by fbaras            #+#    #+#             */
/*   Updated: 2025/08/06 21:57:15 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_putnbr_base_fd(unsigned int nbr, const char *base, int fd)
{
    int i;

    i = 0;
    if (nbr >= ft_strlen(base))
        i += ft_putnbr_base_fd(nbr / ft_strlen(base), base, 1);
    i += write(1, &base[nbr % ft_strlen(base)], 1);
    return (i);
}
