/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:21:40 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/15 21:21:40 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*ptr = calloc(10, sizeof(int));
// 	for (int i = 0; i < 10; i++)
// 		printf("index %d has value %d \n", i, ptr[i]);
// 	free(ptr);
// 	return (0);
// }
