/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:32:39 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/15 14:46:55 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memset(void *b, int c, size_t len)
{
	int		i;
	char	*temp;

	temp = b;
	i = 0;
	while (i <= len)
	{
		temp[i] = c;
		i++;
	}
	temp[i] = 0;
	return (b);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char buffer[50];

// 	memset(buffer, 'A', sizeof(buffer));
//     printf("Buffer after memset with 'A': %s\n", buffer);
// }