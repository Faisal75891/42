/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:10:17 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/15 19:10:17 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*temp_ptr;

	i = 0;
	temp_ptr = (unsigned char *)s;
	while (temp_ptr[i] && i < n)
	{
		if (temp_ptr[i] == (char)c)
			return ((void *)temp_ptr + i);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	printf("%s\n", ft_memchr("hello", '\0', 10));
// 	printf(memchr("hello", '\0', 10));
// }
