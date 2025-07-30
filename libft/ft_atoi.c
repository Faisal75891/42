/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:55:59 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/15 20:55:59 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (int)(result * sign);
}

// #include <stdlib.h>
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n", atoi(NULL));

// 	printf("%d\n", atoi("1234"));
// 	printf("%d\n\n", ft_atoi("1234"));

// 	printf("1. \n\n");

// 	printf("%d\n", atoi("-1234"));
// 	printf("%d\n\n", ft_atoi("-1234"));

// 	printf("2. \n\n");

// 	printf("%d\n", atoi("++2147483647"));
// 	printf("%d\n\n", ft_atoi("++2147483647")); // INT_mAX

// 	printf("3. \n\n");

// 	printf("%d\n", atoi("-2147483648"));
// 	printf("%d\n\n", ft_atoi("-2147483648")); // INT_MIN

// 	printf("4. \n\n");

// 	printf("%d\n", atoi("-2147483649"));
// 	printf("%d\n\n", ft_atoi("-2147483649")); // INT_MIN - 1

// 	printf("5. \n\n");

// 	printf("%d\n", atoi("2147483648"));
// 	printf("%d\n\n", ft_atoi("2147483648")); // INT_MAX + 1
// }
