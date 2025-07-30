/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:49:47 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/23 22:49:47 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (!lst || !f)
		return ;
	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}

// void f_toupper(void *thing)
// {
//     char *str = (char *)thing;
//     int i = 0;

//     while (str[i])
//     {
//         if (str[i] >= 'a' && str[i] <= 'z')
//             str[i] -= 32;
//         i++;
//     }
// }
// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	char	*s1 = ft_strdup("hi1");

// 	char	*s2 = ft_strdup("hi2");
// 	t_list	*lst = NULL;
// 	ft_lstadd_back(&lst, ft_lstnew(s2));
// 	ft_lstadd_back(&lst, ft_lstnew(s1));

// 	ft_lstiter(lst, &f_toupper);

// 	while (lst != NULL)
// 	{
// 		printf("%s\n", lst->content);
// 		lst = lst->next;
// 	}
// 	ft_lstclear(&lst, &free);
// 	return (0);
// }
