#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
# include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	count_words(char *arg)
{
	int		i;
	int		word_count;
	char	*trimmed_arg;
	int		in_word;

	i = 0;
	word_count = 0;
	in_word = 0;
	trimmed_arg = ft_strtrim(arg, " ");
	if (!trimmed_arg)
		return (0);
	while (trimmed_arg[i])
	{
		if (trimmed_arg[i] != ' ' && in_word == 0)
		{
			word_count++;
			in_word = 1;
		}
		else if (trimmed_arg[i] == ' ')
			in_word = 0;
		i++;
	}
	free(trimmed_arg);
	return (word_count);
}

int	word_len(char *arg, int i)
{
	int len;

	len = 0;
	while (arg[len + i] && arg[len + i] != ' ')
		len++;
	return (len + 1);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	**parse_arguments(char *arg)
{
	char	**arg_list;
	int		i;
	int		j;
	int		len;

	arg = ft_strtrim(arg, " ");
	arg_list = malloc ((count_words(arg) + 1) * sizeof(char *));
	if (!arg_list)
		return (NULL);
	i = 0;
	len = 0;
	j = 0;
	while (arg[i])
	{
		len = word_len(arg, i);
		arg_list[j] = malloc(len + 1);
		if (!arg_list[j])
		{
			free_array(arg_list);
			return (NULL);
		}
		ft_strlcpy(arg_list[j], &arg[i], len);
		arg_list[j++][len] = '\0';
		i += len;
	}
	arg_list[j] = NULL;
	return (arg_list);
}


int	main(int argc, char **argv)
{
	int		pipefd[2];
	pid_t	cpid;

	if (argc != 5)
	{
		exit(0) ;
	}
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	cpid = fork();
	if (cpid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (cpid == 0)
	{
		int file1 = open(argv[1], O_RDONLY);
		dup2(file1, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(file1);
		close(pipefd[0]);
		close(pipefd[1]);
		char **newargv = parse_arguments(argv[2]);
		char *newenviron[] = { NULL };
		execve(argv[2], newargv, newenviron);
		perror("execve cmd1");
		exit(1);
	}
	pid_t cpid2 = fork();
	if (cpid2 == 0)
	{
		int	file2 = open(argv[4], O_WRONLY);
		dup2(file2, STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		close(file2);
		close(pipefd[0]);
		close(pipefd[1]);
		char **newargv = parse_arguments(argv[3]);
		char *newenviron[] = { NULL };
		execve(argv[3], newargv, newenviron);
		perror("execve cmd2");
		exit(1);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(cpid, NULL, 0);
	waitpid(cpid2, NULL, 0);
}
