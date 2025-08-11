/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:17:44 by fbaras            #+#    #+#             */
/*   Updated: 2025/08/08 16:17:44 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	byte;
	char	buffer[BUFSIZ];
	char	*new_line;
	// int		line_size;
	int		i;

	// line_size = size_of_line(fd) + 1;

	// new_line = malloc (line_size * sizeof(char *));
	// if (!new_line)
	// {
	// 	close(fd);
	// 	return (NULL);
	// }
	i = 0;
	while (read(fd, &byte, sizeof(char)) > 0)
	{
		if (byte == '\n')
			break;
		if (i >= BUFSIZ -1)
			break;
		buffer[i++] = byte;
	}
	buffer[i] = '\0';
	new_line = buffer;
	return (new_line);
}
