/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:07:13 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/28 21:09:35 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

// awk "{count++} END {printf \"count: %i\" , count}"
// word1 "               word2                      "
// 0                       1                        2

int	count_words(const char *s, char c)
{
	int	i;
	int	in_word;
	int	in_quote;
	int	in_double_quote;

	i = 0;
	in_word = 0;
	in_quote = 0;
	in_double_quote = 0;
	while (*s)
	{
		if (*s == '\'' && !in_double_quote)
			in_quote = !in_quote;
		else if (*s == '"' && !in_quote)
			in_double_quote = !in_double_quote;
		if (*s != c && !in_word)
		{
			in_word = 1;
			i++;
		}
		else if (*s == c && !in_quote && !in_double_quote)
			in_word = 0;
		s++;
	}
	return (i);
}

void	*free_array(char **arr, int size)
{
	while (size--)
		free(arr[size]);
	free(arr);
	return (NULL);
}

int	get_len(const char *s, int in_quote, int in_double_quote, char c)
{
	int	len;

	len = 0;
	while (s[len])
	{
		if (s[len] == '\'' && !in_double_quote)
			in_quote = !in_quote;
		else if (s[len] == '"' && !in_quote)
			in_double_quote = !in_double_quote;
		if (!in_quote && !in_double_quote && s[len] == c)
			break ;
		len++;
	}
	return (len);
}

void	is_inside_quote(char *s, int *in_quote, int *in_double_quote)
{
	if (*s == '\'' && !(*in_double_quote))
		*in_quote = !(*in_quote);
	else if (*s == '"' && !(*in_quote))
		*in_double_quote = !(*in_double_quote);
}
