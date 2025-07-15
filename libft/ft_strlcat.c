/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:06:34 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/15 15:52:31 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	int		j;

	j = 0;
	while (dst[j])
		j++;
	if (dstsize == 0 || dstsize <= j)
		return (ft_strlen(src) + dstsize);
	i = 0;
	while (i < dstsize - j - 1 && src[i] != '\0')
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (j + i + dstsize);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char h[20] = "Hello";
// 	char w[] = ", World!";
// 	printf("%zu\n", ft_strlcat(h, w, 0));
// 	printf("%s\n", h);
// }