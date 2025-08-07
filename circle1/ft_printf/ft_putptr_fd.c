/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 23:37:52 by fbaras            #+#    #+#             */
/*   Updated: 2025/08/06 23:37:52 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	t_ft_putnbr_base_fd(unsigned long long nbr,
										const char *base, int fd)
{
	int		count;
	size_t	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
		count += t_ft_putnbr_base_fd(nbr / base_len, base, fd);
	count += write(fd, &base[nbr % base_len], 1);
	return (count);
}

int	ft_putptr_fd(void *ptr, int fd)
{
	unsigned long long	num;
	int					count;

	if (!ptr)
	{
		count = write(fd, "(nil)", 5);
		return (count);
	}
	num = (unsigned long long)ptr;
	count = write(fd, "0x", 2);
	count += t_ft_putnbr_base_fd(num, "0123456789abcdef", fd);
	return (2 + count);
}
