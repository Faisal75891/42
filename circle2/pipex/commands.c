/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:32:55 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/14 21:01:48 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_and_close(int fd1, int fd2)
{
	if (fd1 == -1)
	{
		ft_putstr_fd("pipex: dup_and_close: invalid fd\n", 2);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd1, fd2) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (fd1 > -1)
		close(fd1);
}

char	*test_paths(char **paths, char *cmd)
{
	char	*temp;
	int		i;
	char	*full_path;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
		{
			return (NULL);
		}
		full_path = ft_strjoin(temp, cmd);
		if (!full_path)
			return (NULL);
		if (temp)
			free(temp);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		if (full_path)
			free(full_path);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*full_path;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	full_path = test_paths(paths, cmd);
	if (paths)
		free_split(paths);
	return (full_path);
}

void	exec_command(t_gl_variable *glv)
{
	char	*cmd;
	char	*full_path;
	char	**args;

	cmd = glv->argv[glv->arg_index + 2 + glv->is_heredoc];
	args = ft_split_new(cmd, ' ');
	if (!args || !args[0] || args[0][0] == '\0')
	{
		ft_putstr_fd("pipex: command not found\n", 2);
		if (args)
			free_split(args);
		exit(127);
	}
	full_path = get_cmd_path(args[0], glv->envp);
	if (!full_path)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		if (args)
			free_split(args);
		exit(127);
	}
	if (execve(full_path, args, glv->envp) == -1)
	{
		perror("execve");
		if (full_path)
			free(full_path);
		if (args)
			free_split(args);
		exit(126);
	}
}

// void	exec_command(t_gl_variable *glv)
// {
// 	char	*cmd;
// 	char	*args[4];

// 	cmd = glv->argv[glv->arg_index + 2 + glv->is_heredoc];
// 	args[0] = "/bin/sh";
// 	args[1] = "-c";
// 	args[2] = cmd;
// 	args[3] = NULL;
// 	execve("/bin/sh", args, glv->envp);
// 	perror("pipex");
// 	if (errno == ENOENT)
// 		exit(127);
// 	else
// 		exit(1);
// }
