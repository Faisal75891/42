/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:52:20 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/17 14:52:20 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count_words(const char *s, char c)
{
	int	i;
	int	in_word;

	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			i++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (i);
}

int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		len;

	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = word_len(s, c);
			arr[i] = malloc(len + 1);
			if (!arr[i])
				return (NULL);
			ft_memcpy(arr[i], s, len);
			arr[i++][len] = '\0';
			s += len;
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	strs[] = "Hello, world!";
// 	char	**str = ft_split(strs, ',');
// 	for (int i = 0; str[i] != NULL; i++)
// 	{
// 		printf("%s", str[i]);
// 		free(str[i]);
// 	}
// 	free(str);
// 	return (0);
// }
