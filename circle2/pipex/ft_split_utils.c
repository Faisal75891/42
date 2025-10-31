/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:07:13 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/31 04:05:42 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

// awk "{count++} END {printf \"count: %i\" , count}"
// word1 "               word2                      "
// 0                       1                        2

static int	handle_quote(const char *s, int i)
{
	char	quote;

	quote = s[i++];
	while (s[i] && s[i] != quote)
	{
		if (s[i] == '\\' && s[i + 1])
			i++;
		i++;
	}
	if (s[i] == quote)
		i++;
	return (i);
}

char	*unescape_string(char *str)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1])
			i++;
		result[j++] = str[i++];
	}
	result[j] = '\0';
	return (result);
}

int	count_words(const char *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		count++;
		if (s[i] == '"' || s[i] == '\'')
			i += handle_quote(s, i);
		else
		{
			while (s[i] && s[i] != c && s[i] != '"' && s[i] != '\'')
				i++;
		}
	}
	return (count);
}

void	*free_array(char **arr, int size)
{
	while (--size > 0)
		free(arr[size]);
	free(arr);
	return (NULL);
}
