/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:42:59 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/11 12:40:19 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	read_lines(int fd, char *buffer, int BUFFER_SIZE)
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

void	read_stdin(char *limiter, int pipefd[2])
{
	int		bytes_read;
	int		BUFFER_SIZE = 1024;
	char	buffer[BUFFER_SIZE];

	close(pipefd[0]);

	while (1)
	{
		ft_printf("pipe heredoc> ");
		bytes_read = read_lines(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		if (buffer[bytes_read - 1] == '\n')
			buffer[bytes_read - 1] = '\0';
		if (ft_strncmp(buffer, limiter, ft_strlen(limiter) + 1) == 0)
			break;
		buffer[bytes_read - 1] = '\n';
		write(pipefd[1], buffer, bytes_read);
	}
	close(pipefd[1]);
}


int	main(int argc, char **argv)
{
	int		pipefd[2];
	int		num_of_commands;
	int		i;
	pid_t	pid;
	int		prev_pipe;
	int		file;
	char	**args;

	if (argc < 5)
		exit(0);
	num_of_commands = argc - 3;
	i = 0;
	prev_pipe = -1;

	int heredoc_pipe[2];
	int is_heredoc = 0;
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		if (pipe(heredoc_pipe) == -1)
			exit(1);
		pid_t heredoc_pid = fork();
		if (heredoc_pid == -1)
			exit(1);
		if (heredoc_pid == 0)
		{
			read_stdin(argv[2], heredoc_pipe);
			exit(0);
		}
		else
		{
			close(heredoc_pipe[1]);
			waitpid(heredoc_pid, NULL, 0);
		}
		is_heredoc = 1;
		num_of_commands = argc - 4;
	}

	while (i < num_of_commands)
	{
		if (pipe(pipefd) == -1)
			exit(1);
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0) // This is the child process. Parent will be executed first. at line: 83.
		{
			if (i == 0)
			{
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
					dup2(file, STDIN_FILENO);
					close(file);
				}
			}
			else
			{
				// Keep in mind that the previous pipe is the output from the first file or the previous command
				dup2(prev_pipe, STDIN_FILENO);
				close(prev_pipe);
			}
			if (i == num_of_commands - 1)
			{
				file = open (argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
				if (file == -1)
					exit(1);
				dup2(file, STDOUT_FILENO);
				close(file);
			}
			// We will always go inside here if i isnt 1 or argc - 1; This part 
			// Sets the Output of the command to the read end of the pipe.
			else
			{
				dup2(pipefd[1], STDOUT_FILENO);
				close(pipefd[1]); // close becuase we just redirected it.
				close(pipefd[0]); // close just to be safe as good practice.
			}

			// Here execute the commands at argv[i]
			// i starts from 0 and the first command is at index 2
			args = ft_split(argv[i + 2 + is_heredoc], ' ');
			execve(args[0], args, NULL);
			ft_printf("error: %s at cmd%d", strerror(errno), i);
			exit(1);
		}
		// This is the parent.
		// Keep setting the previous pipe as the read end for the next iteration.
		if (prev_pipe != -1)
			close(prev_pipe);
		if (i < num_of_commands)
		{
			close (pipefd[1]);
			prev_pipe = pipefd[0];
		}
		i++;
	}
	while (i < num_of_commands)
	{
		wait (NULL);
		i++;
	}
	return (0);
}
