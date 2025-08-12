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
	return (ft_substr(temp, 0, i));
}

char	*reset_temp(char *temp)
{
	char	*new_temp;
	int		i;

	if (!temp)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
		return (NULL);
	i++;
	new_temp = ft_strdup(&temp[i]);
	return (new_temp);
}

char	*ft_strdup(const char *s)
{
	char	*string;
	int		i;
	int		len;

	len = ft_strlen(s);
	string = malloc(len + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (i < len)
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*new_line;
	char		*buffer;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (ft_strchr(temp, '\n') == 0 && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		buffer[bytes] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	new_line = extract_line(temp);
	temp = reset_temp(temp);
	return (new_line);
}
