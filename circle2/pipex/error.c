/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:59:24 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/28 17:44:21 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>

void	error_exit(char *msg, int exit_code)
{
	write(2, "pipex: ", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(exit_code);
}

void	perror_exit(char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
    if(!arr)
        return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
