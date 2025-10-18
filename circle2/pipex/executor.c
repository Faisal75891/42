/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:31:45 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/14 20:57:35 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wait_for_children(int num_of_commands)
{
	int	status;
	int	exit_code;
	int	i;

	i = 0;
	exit_code = 0;
	while (i < num_of_commands)
	{
		wait(&status);
		if ((status & 0x7F) == 0)
			exit_code = (status >> 8) & 0xFF;
		i++;
	}
	return (exit_code);
}

void	renew_pipe(t_gl_variable *glv, int *prev_pipe,
	int num_of_commands, int pipefd[2])
{
	if (*prev_pipe != -1)
		close(*prev_pipe);
	if (glv->is_heredoc && glv->arg_index == 1)
		close(glv->heredoc_pipe[0]);
	if (glv->arg_index < num_of_commands - 1)
	{
		*prev_pipe = pipefd[0];
	}
	else
	{
		close(pipefd[0]);
		close(pipefd[1]);
		*prev_pipe = -1;
	}
}

int	execute_all_commands(t_gl_variable *glv)
{
	int		pipefd[2];
	pid_t	pid;
	int		prev_pipe;
	int		num_of_commands;

	num_of_commands = glv->argc - 3 - glv->is_heredoc;
	prev_pipe = -1;
	while (glv->arg_index < num_of_commands)
	{
		if (pipe(pipefd) == -1)
			exit(1);
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
			child_process(glv, prev_pipe, num_of_commands, pipefd);
		close(pipefd[1]);
		renew_pipe(glv, &prev_pipe, num_of_commands, pipefd);
		glv->arg_index++;
	}
	if (prev_pipe != -1)
		close(prev_pipe);
	return (wait_for_children(num_of_commands));
}

void	child_process(t_gl_variable *glv, int prev_pipe,
	int num_of_commands, int pipefd[2])
{
	if (glv->arg_index < num_of_commands - 1)
		close(pipefd[0]);
	if (glv->is_heredoc && glv->arg_index == 0)
		close(glv->heredoc_pipe[1]);
	if (glv->arg_index == 0)
		setup_input(glv);
	else
		dup_and_close(prev_pipe, STDIN_FILENO);
	if (glv->arg_index == num_of_commands - 1)
		setup_output(glv);
	else
		dup_and_close(pipefd[1], STDOUT_FILENO);
	exec_command(glv);
}
