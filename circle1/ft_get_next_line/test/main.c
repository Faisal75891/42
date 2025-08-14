#include "get_next_line.h"

// char    *read_file(char *filename)
// {
//     int file;
//     file = open(filename, O_RDONLY);
//     if (file == -1)
//         return (NULL);
	
//     char *string = malloc(sizeof(char *) * 20);
//     if (!string)
//     {
//         close(file);
//         return (NULL);
//     }
//     int c;
//     char byte;
//     int i = 0;
//     while (read(file, &byte, 1) > 0) {
//         if (byte == 'r')
//         {
//             string[i++] = '\n';
//             continue;
//         }
//         string[i++] = byte;
//         if (i >= 1023)
//             break;
//     }
//     string[i] = '\0';
//     return (string);
// }

int main(int argc, char **argv)
{
	int	fd;
	char		*new_line;
	(void)argc;

	fd = open(argv[1], O_RDONLY);

	// char *new_string = extract_line(NULL);
	// printf("main function test: %s\n", new_string);
 
	printf("========== %s TEST==========", argv[1]);
	new_line = get_next_line(fd);
	char *line_two = get_next_line(fd);
	char *line_three = get_next_line(fd);
	char *line_four = get_next_line(fd);
	printf("\nLINE 1:%s\n", new_line);
	printf("LINE 2: %s\n", line_two);
	printf("LINE 3: %s\n", line_three);
	printf("LINE 4: %s\n", line_four);

	free(new_line);
	free(line_two);
	free(line_three);
	free(line_four);

	close (fd);
	return (0);
}
