/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 21:31:23 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/14 20:40:19 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
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

int		count_words(const char *s, char c);
void	*free_array(char **arr, int size);
void	close_if_open(int *fd);
void	error_exit(int exit_code, char **args);
char	*handle_absolute_path(char *cmd);
void	handle_permission_denied(char *full_path);
void	exec_error(char *cmd, char **args, char *full_path);
void	command_not_found_error(char *cmd, char **args);
char	*unescape_string(char *str);

void	init_glv(t_gl_variable *glv, int argc, char **argv, char **envp);
int		setup_here_doc(t_gl_variable *glv);
int		read_line(int fd, char *buffer);
int		execute_all_commands(t_gl_variable *glv);
int		wait_for_children(int num_of_commands, pid_t last_pid);
void	renew_pipe(t_gl_variable *glv, int *prev_pipe,
			int num_of_commands, int pipefd[2]);
void	exec_command(t_gl_variable *glv);
void	setup_input(t_gl_variable *glv);
void	setup_output(t_gl_variable *glv);
void	child_process(t_gl_variable *glv, int prev_fd,
			int n_cmds, int pipefd[2]);
void	dup_and_close(int old_fd, int new_fd);
void	free_split(char **arr);
char	*get_cmd_path(char *cmd, char **envp);
char	*test_paths(char **paths, char *cmd);
char	**ft_split_new(char const *s, char c);

#endif