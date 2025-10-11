#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n)
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}


int	read_lines(int fd, char *buffer, int BUFFER_SIZE)
{
	char	temp;
	int		bytes;
	int		i;

	bytes = 1;
	i = 0;
	while (i < BUFFER_SIZE - 1)
	{
		bytes = read(fd, &temp, 1);
		if (bytes <= 0)
			break ;
		buffer[i++] = temp;
		if (temp == '\n')
			break ;
	}
	buffer[i] = '\0';
	if (i > 0)
		return (i);
	else
		return (-1);
}


int main(int argc, char **argv)
{
	int		BUFFER_SIZE = 1024;
	char	*limiter = argv[1];
	char	buffer[BUFFER_SIZE];
	int		bytes_read = 1;

	while (1)
	{
		bytes_read = read_lines(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		if (ft_strncmp(buffer, limiter, ft_strlen(limiter)) == 0)
			break;
		buffer[bytes_read - 1] = '\n';
		write(STDOUT_FILENO, buffer, bytes_read);
	}
}

