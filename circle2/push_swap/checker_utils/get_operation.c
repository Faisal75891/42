/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:26:13 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/27 19:26:13 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*free_and_return(char *stash, char *buffer)
{
	if (stash)
	{
		free(stash);
		stash = NULL;
	}
	if (buffer)
		free(buffer);
	return (NULL);
}

char	*read_line(char *stash)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = malloc(1025);
	if (!buffer)
		return (free_and_return(stash, NULL));
	bytes = 1;
	while (bytes > 0 && (!stash || !ft_strchr(stash, '\n')))
	{
		bytes = read(0, buffer, 1024);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		if (!stash)
			stash = copy_buffer(buffer);
		else
			stash = concatenate_buffer(stash, buffer);
	}
	if (bytes == 0 && (!stash || stash[0] == '\0'))
		return (free_and_return(stash, buffer));
	if (buffer)
		free(buffer);
	return (stash);
}

char	*get_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, i + 1);
	return (line);
}

char	*reset_stash(char *stash)
{
	char	*new_stash;
	int		i;

	if (!stash || stash[0] == '\0')
	{
		if (stash)
			free(stash);
		return (NULL);
	}
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(&stash[i + 1]);
	free(stash);
	return (new_stash);
}

char	*get_operation(void)
{
	static char	*stash;
	char		*new_line;

	stash = read_line(stash);
	if (!stash)
		return (NULL);
	new_line = get_line(stash);
	stash = reset_stash(stash);
	return (new_line);
}
