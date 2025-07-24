/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:23:51 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/15 20:23:51 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return (*big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && (i + j) < len && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/*
	// 012345678910
	// Foo Bar Baz
	// Bar

	i = 0;
	big[0]
		little[0]
			little != big
			break;
	big[4]
		little[0]
			little == big[4] 4 + 0
		little[1]
			little == big[5] 4 + 1
		little[2]
				   == big[6] 4 + 2
		little[3] == '\0'
			return big[i]

*/