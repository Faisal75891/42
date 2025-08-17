#include "../get_next_line.h"

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
    char *line;
    (void)argc;
    printf("========== %s TEST==========", argv[1]);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("\nLINE :[%s]\n", line);
        free(line);
    }
    close(fd);
    return 0;
}
