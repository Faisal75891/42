/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:25:12 by fbaras            #+#    #+#             */
/*   Updated: 2025/10/25 12:25:12 by fbaras           ###   ########.fr       */
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

	if (argc < 5)
	{
        ft_printf("Usage: %s file1 cmd1 cmd2 ... cmdn file2\n", argv[0]);
		exit(EXIT_FAILURE);
	}
    init_glv(&glv, argc, argv, envp);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0 && argv[1][8] == '\0')
	{
		if (argc < 6)
		{
			ft_printf("Usage: %s here_doc LIMITER cmd1 cmd2 ... cmdn file\n", argv[0]);
			exit(EXIT_FAILURE);
		}
		glv.is_heredoc = setup_here_doc(&glv);
	}
	return (execute_all_commands(&glv));
}
