/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:42:43 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/15 14:47:35 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_temp;
	char	*src_temp;

	dst_temp = (char *)dst;
	src_temp = (char *)src;
	i = 0;
	while (i < n)
	{
		dst_temp[i] = src_temp[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	char csrc[] = "GeeksforGeeks"; 
// 	char cdest[100];

// 	ft_memcpy(cdest, csrc, 100);

// 	printf("Copied string is %s", cdest);
// }