/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:40:07 by fbaras            #+#    #+#             */
/*   Updated: 2025/08/06 21:40:07 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int ft_putunbr_fd(unsigned int nbr, int fd)
{
    char digit;
    
    if (nbr > 9)
        ft_putunbr_fd(nbr / 10, fd);
    
    digit = nbr % 10 + '0';
    write(fd, &digit, 1);
    return (1);
}