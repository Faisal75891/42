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
	static char	*stash[1024];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_strdup("");
	if (!stash[fd])
		return (NULL);
	stash[fd] = read_line(stash[fd], buffer, fd);
	line = extract_line(stash[fd]);
	stash[fd] = reset_stash(stash[fd]);
	return (line);
}

char	*read_line(char *stash, char *buffer, int fd)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
		if (!stash)
			return (NULL);
	}
	if (bytes_read <= 0 && !stash[0])
		return (free(stash), stash = NULL, NULL);
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

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
	char	*nl_position;

	new_stash = NULL;
	nl_position = ft_strchr(stash, '\n');
	if (!nl_position)
	{
		free(stash);
		return (NULL);
	}
	if (nl_position && *(nl_position + 1))
	{
		new_stash = ft_strdup(nl_position + 1);
		if (!new_stash)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
	}
	free(stash);
	return (new_stash);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	fd1, fd2, fd3;

// 	fd1 = open("file1.txt", O_RDONLY);
// 	fd2 = open("file2.txt", O_RDONLY);
// 	fd3 = open("file3.txt", O_RDONLY);

// 	int i = 0;
// 	while (i < 3)
// 	{
// 		char *line = get_next_line(fd1);
// 		char *lin  = get_next_line(fd2);
// 		char *li   = get_next_line(fd3);
// 		printf("1. %s\n", line);
// 		printf("2. %s\n", lin);
// 		printf("3. %s\n\n", li);
// 		free(line);
// 		free(lin);
// 		free(li);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }