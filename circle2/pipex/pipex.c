/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:42:59 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/13 19:57:11 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_glv(t_gl_variable *glv, int argc, char **argv, char **envp)
{
	glv->argc = argc;
	glv->argv = argv;
	glv->envp = envp;
	glv->arg_index = 0;
	glv->heredoc_pipe[0] = -1;
	glv->heredoc_pipe[1] = -1;
	glv->is_heredoc = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_gl_variable	glv;

	init_glv(&glv, argc, argv, envp);
	if (argc < 5)
		exit(EXIT_FAILURE);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
		glv.is_heredoc = setup_here_doc(&glv);
	execute_all_commands(&glv);
	return (0);
}
