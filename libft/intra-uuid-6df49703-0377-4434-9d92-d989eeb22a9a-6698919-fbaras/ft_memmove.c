/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:06:55 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/15 14:47:09 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_temp;
	char	*src_temp;

	dst_temp = (char *)dst;
	src_temp = (char *)src;
	i = 0;
	while (i < len)
	{
		if (dst_temp <= src_temp)
		{
			*dst_temp++ = *src_temp++;
		}
		else
			dst_temp[i] = src_temp[i];
		i++;
	}
	return (dst);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {	
// 	char	b[] = "sigma";
// 	//ft_memmove(b + 1, b, 1);
// 	memmove(b + 1, b, 1);

// 	printf("%s", b);
// }
