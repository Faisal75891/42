#include <iostream>

int	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

void	to_upper(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		c[i] = to_upper(c[i]);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			to_upper(argv[i]);
			std::cout << argv[i];
			i++;
		}
		std::cout << std::endl;
	}
	return (1);
}
