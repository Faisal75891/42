/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:31:45 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/12 21:34:44 by fbaras           ###   ########.fr       */
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

void	renew_pipe(int *prev_pipe, int num_of_commands,
	int i, int pipefd[2])
{
	if (*prev_pipe != -1)
		close(*prev_pipe);
	if (i < num_of_commands)
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
		{
			perror("couldn't fork");
			exit(1);
		}
		if (pid == 0)
			child_process(glv, prev_pipe, num_of_commands, pipefd);
		renew_pipe(&prev_pipe, num_of_commands, glv->arg_index, pipefd);
		glv->arg_index++;
	}
	wait_for_children(num_of_commands);
}
