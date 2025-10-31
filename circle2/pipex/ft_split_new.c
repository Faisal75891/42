/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:25:09 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/25 13:25:09 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

static char	*handle_quote(const char *s, int *i)
{
	char	*arr;
	char	quote;
	int		start;

	quote = s[(*i)++];
	start = *i;
	while (s[*i] && s[*i] != quote)
	{
		if (s[*i] == '\\' && s[*i + 1])
			(*i)++;
		(*i)++;
	}
	arr = malloc((*i - start) + 1);
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, &s[start], (*i - start) + 1);
	if (s[*i] == quote)
		(*i)++;
	return (arr);
}

static char	*handle_normal_case(const char *s, int *i, char c)
{
	char	*arr;
	int		start;

	start = *i;
	while (s[*i] && s[*i] != c && s[*i] != '"' && s[*i] != '\'')
		(*i)++;
	arr = malloc((*i - start) + 1);
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, &s[start], (*i - start) + 1);
	return (arr);
}

static char	*populate_index(const char *s, int *i, char c)
{
	char	*arr;

	if (s[*i] == '"' || s[*i] == '\'')
	{
		arr = handle_quote(s, i);
		if (!arr)
			return (NULL);
	}
	else
	{
		arr = handle_normal_case(s, i, c);
		if (!arr)
			return (NULL);
	}
	return (arr);
}

static int	fill_array(char **arr, const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		arr[j] = populate_index(s, &i, c);
		if (!arr[j])
			return (j);
		j++;
	}
	arr[j] = NULL;
	return (0);
}

char	**ft_split_new(char const *s, char c)
{
	char	**arr;
	int		fail_index;

	if (!s)
		return (NULL);
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	fail_index = fill_array(arr, s, c);
	if (fail_index > 0)
		return (free_array(arr, fail_index));
	return (arr);
}
