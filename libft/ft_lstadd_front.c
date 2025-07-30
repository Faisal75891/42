/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:40:55 by fbaras            #+#    #+#             */
/*   Updated: 2025/07/23 12:40:55 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst)
		new->next = *lst;
	else
		new->next = NULL;
	*lst = new;
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*lst = ft_lstnew("hiii");
// 	printf("lst before adding: %s\n", lst->content);

// 	t_list	*new_node = ft_lstnew("hi");
// 	ft_lstadd_front(&lst, new_node);

// 	while (lst != NULL)
// 	{
// 		printf("%s\n", lst->content);
// 		lst = lst->next;
// 	}
// }
