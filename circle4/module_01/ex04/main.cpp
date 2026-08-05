#include <iostream>
#include <string>
#include <fstream>

std::string	search_replace(std::string line, const std::string s1, const std::string s2);

int	main(int argc, char **argv)
{
	std::string	filename, line, s1, s2;

	if (argc != 4)
	{
		std::cout << "Invalid Input!\nUsage: ./s infile <search> <replace>\n";
		return (1);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	std::ifstream	infile;
	std::ofstream	outfile;

	infile.open(filename.c_str());
	if (infile.is_open())
	{
		const std::string out = filename + ".replace";
		outfile.open(out.c_str(), std::ios::out | std::ios::trunc);
		if (outfile.is_open())
		{
			while (getline(infile, line))
			{
				line = search_replace(line, s1, s2);
				outfile << line;
				if (!infile.eof())
					outfile << std::endl;
			}
			outfile.close();
		}
		else
		{
			std::cerr << "couldn't open/create " << filename + ".replace" << std::endl;
			infile.close();
			return (1);
		}
		infile.close();
	}
	else
	{
		std::cerr << "There was a problem opening: " << filename << std::endl;
		return (1);
	}
	return (0);
}

std::string	search_replace(std::string line, const std::string s1, const std::string s2)
{
	int	erase_len = s1.length();
	int	replace_len = s2.length();
	size_t	i = 0;

	i = line.find(s1);
	while (i != std::string::npos)
	{
		line.erase(i, erase_len);
		line.insert(i, s2);
		i = line.find(s1, i + replace_len);
	}
	return (line);
}
