/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fdi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 22:35:10 by fbaras            #+#    #+#             */
/*   Updated: 2025/08/06 22:35:10 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fdi(char *s, int fd)
{
	int	i;
	if (!s)
		return (0);

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
	return (i);
}
