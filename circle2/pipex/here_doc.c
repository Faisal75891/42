/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 22:53:06 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/13 19:50:57 by fbaras           ###   ########.fr       */
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

void	read_heredoc(char *limiter, int pipefd[2])
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

int	setup_here_doc(t_gl_variable *glv)
{
	pid_t	heredoc_pid;

	if (pipe(glv->heredoc_pipe) == -1)
	{
		perror("couldn't pipe heredoc");
		return (0);
	}
	heredoc_pid = fork();
	if (heredoc_pid == -1)
	{
		perror("couldn't fork heredoc");
		return (0);
	}
	if (heredoc_pid == 0)
	{
		read_heredoc(glv->argv[2], glv->heredoc_pipe);
		exit(0);
	}
	else
	{
		close(glv->heredoc_pipe[1]);
		waitpid(heredoc_pid, NULL, 0);
	}
	return (1);
}
