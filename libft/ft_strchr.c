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
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		*s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf(ft_strchr("hello", '\0'));

// }
