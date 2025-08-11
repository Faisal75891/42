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

char	*extract_line(char *temp)
{
	int		i;

	i = 0;
	if (!temp)
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	return (ft_substr(temp, 0, i));
}

char	*reset_temp(char *temp)
{
	char	*new_temp;
	int		i;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	i++;
	new_temp = ft_substr(temp, i, -1);
	free(temp);
	return (new_temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*new_line;
	char		*buffer;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(temp, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	new_line = extract_line(temp);
	temp = reset_temp(temp);
	return (new_line);
}
