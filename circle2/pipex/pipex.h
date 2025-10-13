/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 21:31:23 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/13 17:54:33 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <errno.h>
# include <string.h>
# include "ft_printf/ft_printf.h"

typedef struct s_global_variables
{
	char	**argv;
	int		argc;
	char	**envp;
	int		arg_index;
	int		is_heredoc;
	int		heredoc_pipe[2];
}	t_gl_variable;

void	init_glv(t_gl_variable *glv, int argc, char **argv, char **envp);
int		setup_here_doc(t_gl_variable *glv);
int		read_line(int fd, char *buffer);
void	execute_all_commands(t_gl_variable *glv);
void	wait_for_children(int n);
void	renew_pipe(int *prev_fd, int i, int n_cmds, int pipefd[2]);
void	exec_command(t_gl_variable *glv);
void	setup_input(t_gl_variable *glv);
void	setup_output(t_gl_variable *glv);
void	child_process(t_gl_variable *glv, int prev_fd,
			int n_cmds, int pipefd[2]);
void	dup_and_close(int old_fd, int new_fd);
void	free_split(char **arr);

#endif