#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void	copy_file(istream &infile, ofstream &outfile, string s1, string s2);

int	main(void)
{
	string	filename, s1, s2;

	if (!(cin >> filename >> s1 >> s2))
	{
		cout << "Nigga\n";
	}
	string	outfile = filename + ".replace";
	ifstream file(filename);
	if (!file)
	{
		cerr << "Error occured when opening file: "
			<< filename << endl;
		return (2);
	}
	ofstream file_replace(outfile);
	if (!file_replace.is_open())
	{
		cerr << "Error opening file " << outfile << endl;
		return (3);
	}
	copy_file(file, file_replace, s1, s2);
	// char	line[80];
	// ifstream nigga(outfile);
	// while (nigga.getline(line, 80))
	// {
	// 	cout << line << endl;
	// }
	// if (!file.eof())
	// {
	// 	cerr << "Error reading file: " << filename << endl;
	// }
	return (0);
}

void	copy_file(istream &infile, ofstream &outfile, const string s1, const string s2)
{
	char	c;
	string	word;
	int	i = 0;
	while (infile.get(c))
	{
		if (isspace(c))
		{
			if (word == s1)
			{
				outfile << s2;
				cout << s2;
			}
			else
			{
				outfile << word;
				cout << word;
			}
			cout << c;
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
		cout << s2;
	}
	else
	{
		outfile << word;
		cout << word;
	}
}
