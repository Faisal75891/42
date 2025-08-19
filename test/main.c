#include "../circle1/ft_get_next_line/get_next_line_bonus.h"

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
    int fd = open(argv[1], O_RDONLY);

    int test1 = open("tests.txt", O_RDONLY);
    int test2 = open("words.txt", O_RDONLY);

    char *lines;
    char *line2;
    for (int i = 0; i < 4; i++)
    {
        lines = get_next_line(test1);
        printf("iteration: %d Line: %s\n", i, lines);
        line2 = get_next_line(test2);
        printf("iteration: %d Line2: %s\n", i, line2);
    }
    close(test1);
    close(test2);
    // char *line;
    (void)argc;
    // printf("========== %s TEST==========", argv[1]);
    // while ((line = get_next_line(fd)) != NULL)
    // {
    //     printf("\nLINE :[%s]\n", line);
    //     free(line);
    // }
    close(fd);
    return 0;
}
