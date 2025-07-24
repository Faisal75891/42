/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:32:26 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/23 23:32:26 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	void	*temp;
	t_list	*new_node;

	list = NULL;
	while (lst != NULL)
	{
		temp = f(lst->content);
		if (!temp)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		new_node = ft_lstnew(temp);
		if (!new_node)
		{
			del(new_node);
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_front(&list, new_node);
		lst = lst->next;
	}
	return (list);
}

// void *f_toupper(void *thing)
// {
//     char *str = (char *)thing;
//     char *string;
//     int i = 0;

//     string = malloc(ft_strlen(str) + 1);
//     if (!string)
//         return (NULL);

//     while (str[i])
//     {
//         if (str[i] >= 'a' && str[i] <= 'z')
//             string[i] = str[i] - 32;
//         else
//             string[i] = str[i];
//         i++;
//     }
//     string[i] = '\0';
//     return (string);
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

// 	lst = ft_lstmap(lst, &f_toupper, &free);

// 	while (lst != NULL)
// 	{
// 		printf("%s\n", lst->content);
// 		lst = lst->next;
// 	}
// 	ft_lstclear(&lst, &free);
// 	return (0);
// }
