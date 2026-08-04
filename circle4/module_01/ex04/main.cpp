#include <iostream>
#include <string>
#include <fstream>

void	copy_file(std::istream &infile, std::ofstream &outfile, std::string s1, std::string s2);

int	main(void)
{
	std::string	filename, s1, s2;
	// const	std::string filename; cin doesnt work when filename is const

	if (!(std::cin >> filename >> s1 >> s2))
	{
		std::cout << "Enter in this format: [filename] [string1] [string2] \n";
	}
	std::string	outfile = filename + ".replace";
	std::ifstream file(filename.c_str()); // this makes filename a const string
	if (!file)
	{
		std::cerr << "Error occured when opening file: "
			<< filename << " Does the file exist?" << std::endl;
		return (2);
	}
	std::ofstream file_replace(outfile.c_str()); // this makes outfile variable a const string
	if (!file_replace.is_open())
	{
		std::cerr << "Error opening file " << outfile << std::endl;
		return (3);
	}
	copy_file(file, file_replace, s1, s2);
	return (0);
}

void	copy_file(std::istream &infile, std::ofstream &outfile, const std::string s1, const std::string s2)
{
	char	c;
	std::string	word;
	while (infile.get(c))
	{
		if (isspace(c))
		{
			// std::cout << word << std::endl;
			if (word == s1)
			{
				outfile << s2;
				std::cout << s2;
			}
			else
			{
				outfile << word;
				std::cout << word;
			}
			std::cout << c;
			outfile << c;
			word = "";
		}
		else
			word += c;
		// outfile.put(c);
	}
	// checking the last word
	if (word == s1)
	{
		outfile << s2;
		std::cout << s2;
	}
	else
	{
		outfile << word;
		std::cout << word;
	}
}
