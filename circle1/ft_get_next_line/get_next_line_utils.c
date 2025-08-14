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

	if (!s)
		return (ft_strdup(""));
	new_string = malloc((len) + 2);
	if (!new_string)
		return (NULL);
	i = 0;
	j = 0;
	while (i < start)
		i++;
	while ((i <= len))
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
	int		i;
	int		j;

	if (!s1)
		return ft_strdup(s2);
	if (!s2)
		return ft_strdup(s1);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = malloc(len);
	if (!string)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		string[i + j] = s2[j];
		j++;
	}
	string[i + j] = '\0';
	return (string);
}

char	*ft_strchr(char *s, char c)
{
	int	i;
	if (!s)
		s = ft_strdup("");
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s);
		i++;
	}
	if ((char)c == '\0')
		return (&s[i]);
	return (NULL);
}
