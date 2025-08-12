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

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	return (ft_substr(stash, 0, i));
}

char	*reset_stash(char *stash)
{
	char	*new_stash;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (*stash && *stash != '\n')
		stash++;
	new_stash = ft_strdup(stash);
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

void	ft_strlcat(char *dst, const char *src)
{
	size_t	i;
	size_t	dst_len;

	dst_len = 0;
	while (dst[dst_len])
		dst_len++;
	i = 0;
	while (i < dst_len - 1 && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (b);
}



char	*get_next_line(int fd)
{
	static char	*stash;
	char		*new_line;
	char		*buffer;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, &buffer[0], BUFFER_SIZE);
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
