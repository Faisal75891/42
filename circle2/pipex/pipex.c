#include <sys/types.h>
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
	if (argc != 5)
	{
		printf("%d\n", argc);
		exit(0) ;
	}
	int fds[2];
	char	buffer[30] = {0};
	pipe(fds);

	printf("I am the Parent pid: %d\n", getpid());
	int file1 = open(argv[1], O_RDONLY); // read from. INFILE
	int file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644); // write into. OUTFILE
	if (fork() == 0)
	{
		close(fds[0]);
        close(fds[1]);
		// redirect the inputs and outputs of the pipe.
		int	savestdin = dup(0);
		int	savestout = dup(1);
		dup2(file1, 0);
		dup2(file2, 1);

		char **arg_list = parse_arguments(argv[2]);
		char **arg_list2 = parse_arguments(argv[3]);

		ssize_t bytes_read = read(0, buffer, sizeof(buffer) - 1);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            printf("Read from input file: %s\n", buffer);
            write(1, buffer, bytes_read);
        }
		// execute the child processes
		// i.e argv 1 and 2;
		//execve(argv[2], arg_list, NULL);
		//execve(argv[3], arg_list2, NULL);
		dup2(savestdin, 0);
        dup2(savestout, 1);
        close(savestdin);
        close(savestout);
        
        close(file1);
        close(file2);
        exit(0);
	}
	//wait for the child processes;
	//wait(NULL);
	// close the files.

	wait(NULL);
	close(fds[0]);
	close(fds[1]);
	close(file1);
	close(file2);
	// finally exit the program
	exit(0);
}