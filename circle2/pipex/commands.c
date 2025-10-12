/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:32:55 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/12 22:17:10 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_and_close(int fd1, int fd2)
{
	if (fd1 == -1)
	{
		fprintf(stderr, "dup_and_close: invalid fd (%d)\n", fd1);
		exit(1);
	}
	if (dup2(fd1, fd2) == -1)
	{
		perror("couldn't dup2");
		exit (1);
	}
	close(fd1);
}

void	setup_input(t_gl_variable *glv)
{
	int	file;

	if (glv->is_heredoc == 1)
		dup_and_close(glv->heredoc_pipe[0], STDIN_FILENO);
	else
	{
		if (access(glv->argv[1], R_OK) != 0)
		{
			perror("infile access error");
			exit(EXIT_FAILURE);
		}
		file = open(glv->argv[1], O_RDONLY);
		if (file == -1)
		{
			perror("infile couldn't be opened");
			exit(1);
		}
		dup_and_close(file, STDIN_FILENO);
	}
}

void	set_output(t_gl_variable *glv)
{
	int	file;

	file = open (glv->argv[glv->argc - 1], O_WRONLY
			| O_CREAT | O_TRUNC, 0644);
	if (file == -1)
	{
		perror("outfile couldn't be opened");
		exit(1);
	}
	dup_and_close(file, STDOUT_FILENO);
}

void free_split(char **arr)
{
    int i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}

void	exec_command(t_gl_variable *glv)
{
	char	**args;

	args = ft_split(glv->argv[glv->arg_index + 2 + glv->is_heredoc], ' ');
	if (!args)
	{
		perror("ft_split failed!");
		exit(1);
	}
	if (access(args[0], X_OK) == 0)
	{
		execve(args[0], args, glv->envp);
		ft_printf("error: %s at cmd %d", strerror(errno), glv->arg_index);
	}
	else
	{
		perror("command was not executed or not found");
		exit(127);
	}
	free_split(args);
	exit(1);
}

void	child_process(t_gl_variable *glv, int prev_pipe,
	int num_of_commands, int pipefd[2])
{
	if (glv->arg_index == 0)
		setup_input(glv);
	else
		dup_and_close(prev_pipe, STDIN_FILENO);
	if (glv->arg_index == num_of_commands - 1)
		set_output(glv);
	else
		dup_and_close(pipefd[1], STDOUT_FILENO);
	exec_command(glv);
}
