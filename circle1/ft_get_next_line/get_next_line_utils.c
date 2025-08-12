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

// int	size_of_line(int fd)
// {
// 	char	byte;
// 	int		chars_read;

// 	chars_read = 0;
// 	while (read(fd, &byte, 1) > 0)
// 	{
// 		write(1, &byte, 1);
// 		if (byte == '\n')
// 			break;
// 		chars_read++;
// 	}
// 	close (fd);
// 	return (chars_read);
// }

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	i;
	size_t	j;

	new_string = malloc((len) + 1);
	if (!new_string || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (i < start)
		i++;
	while ((i <= len) || ((int)len == -1 && s[i]))
	{
		new_string[j] = s[i];
		i++;
		j++;
	}
	new_string[j] = '\0';
	return (new_string);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		len;
	char	*res;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = malloc(len);
	if (!string)
		return (NULL);
	while (*s1)
		*string++ = *s1++;
	while (*s2)
		*string++ = *s2++;
	*string = '\0';
	res = &string[0];
	if (ft_strlen(string) > 0)
		free(string);
	return (res);
}

int	ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c || (char)c == '\0' || *s == '\0')
		return (1);
	return (0);
}
