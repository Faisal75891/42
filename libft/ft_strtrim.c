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
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	string = ft_substr(s1, start, end - start);
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
