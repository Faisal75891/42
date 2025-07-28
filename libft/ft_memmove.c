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
	size_t			i;
	unsigned char	*dst_temp;
	unsigned char	*src_temp;

	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	if (dst_temp < src_temp)
		while (len--)
			*dst_temp++ = *src_temp++;
	else if (dst_temp > src_temp)
		while (len--)
			dst_temp[len] = src_temp[len];
	return (dst);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {	
// 	char	b[] = "sigma";
// 	ft_memmove(b + 1, b, 1);
// 	//memmove(b + 1, b, 1);

// 	printf("%s", b);
// }
