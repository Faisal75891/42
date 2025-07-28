/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:43:36 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/17 19:43:36 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strrev(char	*s)
{
	char	temp;
	int		end;
	int		start;
	int		len;

	len = ft_strlen(s);
	end = len - 1;
	start = 0;
	while (start < len / 2)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		end--;
		start++;
	}
	return (s);
}

int	int_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		n = -n;
	if (n <= 9)
		len = 1;
	while (n / 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		i;
	int		end;
	int		start;
	char	temp;

	string = malloc((sizeof(int) * int_len(n)) + 1);
	if (!string)
		return (NULL);
	i = 0;
	if (n == 0)
	{
		string[0] = '0';
		string[1] = '\0';
		return (string);
	}
	while (n != 0)
	{
		string[i++] = (n % 10) + '0';
		n /= 10;
	}
	string[i] = '\0';
	string = ft_strrev(string);
	return (string);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%s", ft_itoa(1234455));
// }
