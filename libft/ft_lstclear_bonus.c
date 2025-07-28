/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:33:50 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/23 22:33:50 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*next;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		ft_lstdelone(temp, del);
		temp = next;
	}
	lst = NULL;
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*s1 = ft_strdup("hi1");
// 	char	*s2 = ft_strdup("hi2");
// 	t_list	*lst = NULL;
// 	ft_lstadd_back(&lst, ft_lstnew(s2));
// 	ft_lstadd_back(&lst, ft_lstnew(s1));

// 	while (lst != NULL)
// 	{
// 		printf("%s\n", lst->content);
// 		lst = lst->next;
// 	}
// 	ft_lstclear(&lst, &free);
// 	printf("List cleared :)\n I think...");
// 	return (0);
// }
