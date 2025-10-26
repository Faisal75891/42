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

static int	count_words(const char *s, char c)
{
	int	i;
	int	in_word;
    int in_quote;
    int in_double_quote;

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

static void	*free_array(char **arr, int size)
{
	while (size--)
		free(arr[size]);
	free(arr);
	return (NULL);
}

static int	fill_array(char **arr, const char *s, char c)
{
	int	i;
	int	len;
    int in_quote;
    int in_double_quote;

	i = 0;
    in_quote = 0;
    in_double_quote = 0;
	while (*s)
	{
        if (*s == '\'' && !in_double_quote)
        {
			in_quote = !in_quote;
			s++;
			continue;
        }
		else if (*s == '"' && !in_quote)
        {
			in_double_quote = !in_double_quote;
			s++;
			continue;
        }
		if (*s != c || (*s == c && (in_double_quote || in_quote)))
		{
			len = 0;
            if (in_quote)
                while (s[len] && s[len] != '\'')
                    len++;
            else if (in_double_quote)
                while (s[len] && s[len] != '"')
                    len++;
            else
                while (s[len] && s[len] != c)
                    len++;
			arr[i] = malloc(len + 1);
			if (!arr[i])
				return (i);
			ft_strlcpy(arr[i++], s, len + 1);
			s += len;
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (-1);
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
	if (fail_index >= 0)
		return (free_array(arr, fail_index));
	return (arr);
}

