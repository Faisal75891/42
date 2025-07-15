/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:54:03 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/15 14:48:09 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;
	int		i;

	temp = s;
	i = 0;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}

// #include <stdio.h>
// int	main(void)
// {
// 	char buffer[50];

// 	bzero(buffer, sizeof(buffer));
//     printf("Buffer after: %s\n", buffer);
// }