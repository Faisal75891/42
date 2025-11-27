/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:25:08 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/26 16:25:08 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*read_line(char *stash)
{
	char	*buffer;
	int		bytes;
	char	*new_stash;

	buffer = malloc (1025);
	bytes = 1;
	new_stash = NULL;
	while (bytes > 0 && (!stash || !ft_strchr(stash, '\n')))
	{
		bytes = read(0, buffer, 10);
		if (bytes <	 0)
		{
			if (stash)
				free(stash);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (!stash)
		{
			stash = ft_strdup (buffer);
			if (!stash)
			{
				stash = NULL;
				return (NULL);
			}
		}
		else
		{
			new_stash = ft_strjoin(stash, buffer);
			free(stash);
			stash = new_stash;
			if (!stash)
				return (NULL);
		}
	}
	if (bytes <= 0 && (!stash))
	{
		free(stash);
		stash=NULL;
		return (NULL);
	}
	free(buffer);
	return (stash);
}

char	*get_line(char *stash)
{
		char    *line;
		int		i;

		if (!stash)
				return (NULL);
		i = 0;
		while (stash[i] && stash[i] != '\n')
				i++;
		if (stash[i] == '\n')
				i++;
		line = malloc(i + 1);
		if (!line)
		{
				free(stash);
				stash = NULL;
				return (NULL);
		}
		ft_strlcpy(line, stash, i + 1);
		return (line);
}

char	*reset_stash(char *stash)
{
	char	*new_stash;
	int		i;

	i = 0;
	new_stash = NULL;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
	{
		new_stash = ft_strdup(&stash[i + 1]);
		if (!new_stash)
		{
			free(stash);
			return (NULL);
		}
	}
	free(stash);
	return (new_stash);
}

char	*get_operation()
{
	static char	*stash;
	char		*new_line;

	stash = read_line (stash);
	new_line = get_line(stash);
	stash = reset_stash (stash);
	return (new_line);
}
