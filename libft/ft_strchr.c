/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:20:56 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/15 18:20:56 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c || (char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("1. %s\n", ft_strchr("hello", 0));
// 	printf("2. %s\n", ft_strchr(NULL, '\0'));
// 	printf("3. %s\n", ft_strchr("hello", '\0'));
// 	printf("4. %s\n", ft_strchr("hello", 'e'));
// 	printf("5. %s\n", ft_strchr("hello", 'x'));
// }
