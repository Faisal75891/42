/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:59:24 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/31 04:05:14 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>

void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	*handle_absolute_path(char *cmd)
{
	char	*unescaped;
	char	*result;

	unescaped = unescape_string(cmd);
	if (!unescaped)
		return (NULL);
	if (access(unescaped, F_OK) != 0)
		return (NULL);
	if (access(unescaped, X_OK) != 0)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(unescaped, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		free(unescaped);
		exit(126);
	}
	result = ft_strdup(unescaped);
	free(unescaped);
	return (result);
}

void	handle_permission_denied(char *full_path)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(full_path, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	exit (126);
}

void	exec_error(char *cmd, char **args, char *full_path)
{
	ft_putstr_fd("pipex: ", 2);
	perror(cmd);
	free(full_path);
	free_split(args);
	exit(126);
}

void	command_not_found_error(char *cmd, char **args)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	free_split(args);
	exit(127);
}
