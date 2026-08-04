#include <iostream>
using namespace std;


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
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			to_upper(argv[i]);
			cout << argv[i];
			i++;
		}
		cout << endl;
	}
	return (1);
}
