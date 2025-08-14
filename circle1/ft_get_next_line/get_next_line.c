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

char	*extract_line(char *stash)
{
	int		i;

	if (!stash)
		return (ft_strdup(""));
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	return (ft_substr(stash, 0, i));
}

char	*reset_stash(char *stash)
{
	char	*new_stash;
	int		i;

	if (!stash)
		return (ft_strdup(""));
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i + 1])
		i++;
	new_stash = ft_strdup((char *)&stash[i]);
	free(stash);
	return (new_stash);
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
	static char	*stash;
	char		*new_line;
	char		*buffer;
	char		dummy;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &dummy, 0) < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			break ;
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	new_line = extract_line(stash);
	stash = reset_stash(stash);
	return (new_line);
}
