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

// 'awk "{count++} END {printf \"count: %i\" , count}"' 

// arg[0] = awk
// arg[1] = "{count++} END {printf \"count: %i\" , count}"
//                                 ^          ^
// arg[2] = NULL



static int	fill_array(char **arr, const char *s, char c)
{
	int	i = 0;
	int	j = 0;
	char	quote;
	int		start;

	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		if (s[i] == '"' || s[i] == '\'')
		{
			quote = s[i++];
			start = i;
			while (s[i] && s[i] != quote)
			{
				if (s[i] == '\\' && s[i+1])
					i++;
				i++;
			}
			int len = i - start;
			arr[j] = malloc(len + 1);
			if (!arr[j])
				return free_array(arr, j), -1;
			ft_strlcpy(arr[j++], &s[start], len + 1);
			if (s[i] == quote)
				i++;
		}
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			int len = i - start;
			arr[j] = malloc(len + 1);
			if (!arr[j])
				return free_array(arr, j), -1;
			ft_strlcpy(arr[j++], &s[start], len + 1);
		}
	}
	arr[j] = NULL;
	return (1);
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
	if (fail_index < 0)
		return (free_array(arr, fail_index));
	return (arr);
}

