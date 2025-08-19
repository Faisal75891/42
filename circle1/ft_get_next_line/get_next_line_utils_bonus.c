/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:05:31 by fbaras            #+#    #+#             */
/*   Updated: 2025/08/19 19:35:19 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s1)
{
	size_t	len;

	if (!s1)
		return (0);
	len = 0;
	while (s1[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*new_string;
	size_t	len;
	int		i;

	len = 0;
	len = ft_strlen(s1);
	new_string = malloc(len + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_string[i] = s1[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_strchr(const char *s, int c)
{
	char	*wsg;
	int		i;

	wsg = (char *)s;
	i = 0;
	while (*wsg && *wsg != (char)c)
		wsg++;
	if (*wsg == (char)c)
		return (wsg);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_string;
	char	*temp;
	int		len;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	new_string = malloc(len + 1);
	if (!new_string)
		return (NULL);
	temp = new_string;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (new_string);
}
