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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		len;
	char	*temp;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = malloc(len);
	if (!string)
		return (NULL);
	temp = string;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (string);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*string;
	int		i;
	int		len;

	if (!s)
		return (NULL);
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
