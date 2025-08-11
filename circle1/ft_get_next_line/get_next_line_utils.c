/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:17:13 by fbaras            #+#    #+#             */
/*   Updated: 2025/08/08 20:17:13 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	size_of_line(int fd)
{
	char	byte;
	int		chars_read;

	chars_read = 0;
	while (read(fd, &byte, 1) > 0)
	{
		write(1, &byte, 1);
		if (byte == '\n')
			break;
		chars_read++;
	}
	return (chars_read);
}
