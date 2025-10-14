/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:31:45 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/14 16:32:11 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_for_children(int num_of_commands)
{
	int	i;

	i = 0;
	while (i < num_of_commands)
	{
		wait(NULL);
		i++;
	}
}

void	renew_pipe(t_gl_variable *glv, int *prev_pipe,
	int num_of_commands, int pipefd[2])
{
	if (*prev_pipe != -1)
		close(*prev_pipe);
	if (glv->is_heredoc && glv->arg_index == 1)
		close(glv->heredoc_pipe[0]);
	if (glv->arg_index < num_of_commands)
	{
		close (pipefd[1]);
		*prev_pipe = pipefd[0];
	}
}

void	execute_all_commands(t_gl_variable *glv)
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
		{
			perror("couldn't create pipefd pipe");
			exit(1);
		}
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
			child_process(glv, prev_pipe, num_of_commands, pipefd);
		renew_pipe(glv, &prev_pipe, num_of_commands, pipefd);
		glv->arg_index++;
	}
	if (prev_pipe != -1)
		close(prev_pipe);
	wait_for_children(num_of_commands);
}

void	child_process(t_gl_variable *glv, int prev_pipe,
	int num_of_commands, int pipefd[2])
{
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
