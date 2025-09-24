#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
# include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

char	**parse_arguments(char *arg)
{
	return NULL;
}

/* void	main(void)
{
	int		pipefds[2];
	char	buffer[256] = {0};

	printf("I am the Parent pid: %d\n", getpid());
	pipe(pipefds);
	if (fork() > 0)
		return ;
	read (pipefds[1], buffer, 20);
	printf("Read: %s\n", buffer);
	printf("Cchild pid: %d\n", getpid());
} */

int	main(int argc, char **argv)
{
	int		pipefd[2];
	pid_t	cpid;
	char	buffer;
	int		savestdin;
	int		savestdout;

	if (argc != 5)
	{
		printf("%d\n", argc);
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
		close(file1);
		
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
			char *newargv[] = {argv[2], "--help", NULL};
			char *newenviron[] = { NULL };
			execve(argv[2], newargv, newenviron);
		
		exit(1);
	}
	
	pid_t pid2 = fork();
    if (pid2 == 0)
    {
        // Child 2: cmd2 - reads from pipe, writes to file2
        close(pipefd[1]); // Close write end (not needed)
        
        // Redirect stdin from pipe read end
        dup2(pipefd[0], 0);
        close(pipefd[0]);
        
        // Redirect stdout to file2
        int outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (outfile == -1) {
            perror("open output file");
            exit(1);
        }
        dup2(outfile, 1);
        close(outfile);
        
        // Execute cmd2
			char *newargv[] = {NULL, NULL};
			char *newenviron[] = { NULL };
        execve(argv[3], newargv, newenviron);
        perror("execve cmd2");
        exit(1);
    }

	close(pipefd[0]);
    close(pipefd[1]);
    
    // Wait for both children to finish
    waitpid(cpid, NULL, 0);
    waitpid(pid2, NULL, 0);
}