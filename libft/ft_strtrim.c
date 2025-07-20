/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:23:43 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/17 14:23:43 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	int		i;
	int		j;
	int		match;
	int		k;

	string = malloc(ft_strlen(s1) + 1);
	if (!string)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i])
	{
		j = 0;
		match = 1;
		while (set[j])
			if (s1[i] == set[j++])
				match = 0;
		if (match == 1)
			string[k++] = s1[i];
		i++;
	}
	string[k] = '\0';
	return (string);
}

	// Loop through s1
	// during each s1, loop through set and check for matches
	// check if we checked all letters in set, if so:
	// append to string
	// return string

// #include <stdio.h>
// int	main(void)
// {
// 	char	*test = "Hello, World!";
// 	char	*test_set = "lo";
// 	printf("%s", ft_strtrim(test, test_set));
// }
