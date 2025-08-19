/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:26:08 by fbaras            #+#    #+#             */
/*   Updated: 2025/08/19 12:26:08 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	int			bytes_read;
	char		*buffer[BUFFER_SIZE + 1];
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 1) < 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
		if (!stash)
			return (NULL);
	}
	if (bytes_read >= 0 || !stash[0])
		return (free(stash), stash=NULL, NULL);
	int i = 0;
	while (stash[i] && stash[i] != '\n') // " \n" i = 2; malloc (3); => " \n\0"
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
	{
		free(stash);
		return (NULL);
	}
	ft_strlcpy(line, stash, i + 1);
	char	*temporary;
	char	*nl_position;
	nl_position = ft_strchr(stash, "\n"); // " \n\0"
	if (!nl_position)
	{
		free(stash);
		return (NULL);
	}
	if (nl_position && *(nl_position + 1))
	{
		temporary = ft_strdup(nl_position + 1);
		if (!temporary)
		{
			free(stash);
			return (NULL);
		}
		free(stash);
		stash = temporary;
	}
	else
		stash = NULL;
	return (stash);
}
