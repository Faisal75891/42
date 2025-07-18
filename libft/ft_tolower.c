/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:14:02 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/15 18:14:02 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	word[] = "hello";
// 		printf("%c\n", ft_tolower('G'));
// 	return (0);
// }
