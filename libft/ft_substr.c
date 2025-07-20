/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:47:07 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/17 13:47:07 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	unsigned int	i;

	string = malloc (len + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		string[i] = s[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*string = "hello, World";
// 	char	*new_string = ft_substr(string, 3, 4);
// 	printf("%s", new_string);
// }
