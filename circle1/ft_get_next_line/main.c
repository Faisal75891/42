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

int main(void)
{
	static int	fd;
	char		*new_line;

	fd = open("test.txt", O_RDONLY);

	//printf("%s", ft_strchr("weqwkhdw", '\n'));
	//printf("1.%s\n", ft_strjoin("word 1", "wor"));
	// printf("%s", reset_temp("hello, \n world\n\n"));

	new_line = get_next_line(fd);
	char *line_two = get_next_line(fd);
	char *line_three = get_next_line(fd);
	char *line_four = get_next_line(fd);
	printf("LINE 1: %s", new_line);
	printf("LINE 2: %s", line_two);
	printf("LINE 3: %s", line_three);
	printf("LINE 4: %s", line_four);


	close (fd);
	return (0);
}
