/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:00:51 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/17 21:00:51 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	int		i;

	string = malloc(ft_strlen(s) + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (s[i])
	{
		string[i] = f(i, s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}

// char	f_toupper(unsigned int index, char c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }

// #include <stdio.h>
// int	main(void)
// {
// 	char	*string = "hello, world!";
// 	printf("%s", ft_strmapi(string, f_toupper));
// }
