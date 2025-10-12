/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:42:59 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/12 17:19:49 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	read_lines(int fd, char *buffer)
{
	char	temp;
	int		bytes;
	int		i;

	bytes = 1;
	i = 0;
	while (i < BUFFER_SIZE - 1)
	{
		bytes = read(fd, &temp, 1);
		if (bytes <= 0)
			break ;
		buffer[i++] = temp;
		if (temp == '\n')
			break ;
	}
	buffer[i] = '\0';
	if (i > 0)
		return (i);
	else
		return (-1);
}

void	read_heredoc_input(char *limiter, int pipefd[2])
{
	int		bytes_read;
	char	buffer[BUFFER_SIZE];

	close(pipefd[0]);
	while (1)
	{
		ft_printf("pipe heredoc> ");
		bytes_read = read_lines(STDIN_FILENO, buffer);
		if (bytes_read <= 0)
			break ;
		if (buffer[bytes_read - 1] == '\n')
			buffer[bytes_read - 1] = '\0';
		if (ft_strncmp(buffer, limiter, ft_strlen(limiter) + 1) == 0)
			break ;
		buffer[bytes_read - 1] = '\n';
		write(pipefd[1], buffer, bytes_read);
	}
	close(pipefd[1]);
}

int	setup_here_doc(char **argv, int heredoc_pipe[2])
{
	pid_t	heredoc_pid;

	if (pipe(heredoc_pipe) == -1)
		exit(1);
	heredoc_pid = fork();
	if (heredoc_pid == -1)
		exit(1);
	if (heredoc_pid == 0)
		read_heredoc_input(argv[2], heredoc_pipe);
	else
	{
		close(heredoc_pipe[1]);
		waitpid(heredoc_pid, NULL, 0);
	}
	return (1);
}

void	redirect(int fd1, int fd2)
{
	dup2(fd1, fd2);
	close(fd1);
}

void	read_input(int is_heredoc, int heredoc_pipe[2], char **argv)
{
	int	file;

	if (is_heredoc)
	{
		dup2(heredoc_pipe[0], STDIN_FILENO);
		close(heredoc_pipe[0]);
	}
	else
	{
		file = open(argv[1], O_RDONLY);
		if (file == -1)
			exit(1);
		redirect(file, STDIN_FILENO);
	}
}

void	set_output(t_gl_variable *glv)
{
	int	file;

	file = open (glv->argv[glv->argc - 1], O_WRONLY
			| O_CREAT | O_TRUNC, 0644);
	if (file == -1)
		exit(1);
	redirect(file, STDOUT_FILENO);
}

void	execute_one_command(t_gl_variable *glv)
{
	execve(glv->argv[glv->arg_index + 2 + glv->is_heredoc],
		ft_split(argv[glv->arg_index + 2 + glv->is_heredoc], ' '), NULL);
	ft_printf("error: %s at cmd %d", strerror(errno), glv->arg_index);
	exit(1);
}

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

void	renew_pipe(int prev_pipe, int num_of_commands,
	t_gl_variable *glv, int pipefd[2])
{
	if (prev_pipe != -1)
		close(prev_pipe);
	if (glv->arg_index < num_of_commands)
	{
		close (pipefd[1]);
		prev_pipe = pipefd[0];
	}
}

void	handle_pipeline_command(t_gl_variable *glv, int prev_pipe,
	int num_of_commands, int pipefd[2])
{
	if (glv->arg_index == 0)
		read_input(glv->is_heredoc, glv->heredoc_pipe, glv->argv);
	else
		redirect(prev_pipe, STDIN_FILENO);
	if (glv->arg_index == num_of_commands - 1)
		set_output(glv->argv, glv->argc);
	else
		redirect(pipefd[1], STDOUT_FILENO);
	execute_one_command(glv->argv, glv->is_heredoc, glv->arg_index);
}

//execute_commands(&glv, argv, argc);
void	execute_commands(t_gl_variable *glv, char **argv, int argc)
{
	int		pipefd[2];
	pid_t	pid;
	int		prev_pipe;
	int		num_of_commands;

	num_of_commands = argc - 3 - glv->is_heredoc;
	prev_pipe = -1;
	while (glv->arg_index < num_of_commands)
	{
		if (pipe(pipefd) == -1)
			exit(1);
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
			handle_pipeline_command(glv, prev_pipe, num_of_commands, pipefd);
		renew_pipe(prev_pipe, num_of_commands, i, pipefd);
		glv->arg_index++;
	}
	wait_for_children(num_of_commands);
}

void	set_glv(t_gl_variable *glv, int argc, char **argv)
{
	glv->argc = argc;
	glv->argv = argv;
	glv->arg_index = 0;
	glv->heredoc_pipe[0] = -1;
	glv->heredoc_pipe[1] = -1;
	glv->is_heredoc = 0;
}

int	main(int argc, char **argv)
{
	t_gl_variable	glv;

	set_glv(glv, argc, argv);
	if (argc < 5)
		exit(EXIT_FAILURE);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
		glv.is_heredoc = setup_here_doc(argv);
	execute_commands(&glv, argv, argc);
	return (0);
}
