#include "../circle1/ft_get_next_line/get_next_line_bonus.h"

// BONUS TEST
#include <stdio.h>
void	bonus(void)
{
	int	fd1, fd2, fd3;

	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);

	int i = 0;
	while (i < 3)
	{
		char *line = get_next_line(fd1);
		char *lin  = get_next_line(fd2);
		char *li   = get_next_line(fd3);
		printf("1. %s\n", line);
		printf("2. %s\n", lin);
		printf("3. %s\n\n", li);
		free(line);
		free(lin);
		free(li);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
}


int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);

    char *line;
    (void)argc;
    printf("========== %s TEST==========", argv[1]);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("\nLINE :[%s]\n", line);
        free(line);
    }
    close(fd);

    printf("\n============BONUS============\n");
    //bonus();
    return 0;
}


