/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:42:59 by fbaras            #+#    #+#             */
/*   Updated: 2025/09/27 23:21:17 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


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
	while (i < num_of_commands)
	{
		ft_printf("%d.\n", i);
		if (pipe(pipefd) == -1)
			exit(1);
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0) // This is the child process. Parent will be executed first. at line: 83.
		{
			// if (ft_strcmp(argv[1], "here_doc"))
			// {
			// 	// then save the limit
			// 	char	*limiter = argv[2];
			// 	// then read from stdin.
			// 	while (!ft_strchr(buffer, limiter) && bytes_read > 0)
			// 	{
			// 		bytes_read = read(0, &buffer, BUFFER_SIZE);
			// 		if (bytes_read < 0)
			// 			return (0);
			// 		buffer[bytes_read] = '\0';
			// 	}
			// }
			if (i == 0)
			{
				// This is the infile.
				file = open(argv[1], O_RDONLY);
				if (file == -1)
					exit(1);
				dup2(file, STDIN_FILENO);
				close(file);
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
			args = ft_split(argv[i + 2], ' ');
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
