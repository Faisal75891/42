/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operation_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:09:07 by fbaras            #+#    #+#             */
/*   Updated: 2025/11/30 22:59:47 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*copy_buffer(char *buffer)
{
	char	*stash;

	stash = ft_strdup(buffer);
	if (!stash)
		return (free_and_return(stash, buffer));
	return (stash);
}

char	*concatenate_buffer(char *stash, char *buffer)
{
	char	*new_stash;

	new_stash = ft_strjoin(stash, buffer);
	free(stash);
	stash = new_stash;
	if (!stash)
	{
		free(buffer);
		return (NULL);
	}
	return (stash);
}
