#include <string>
#include <iostream>
using namespace std;

int	main(void)
{
	string	s("HI THIS IS BRAIN");
	string	*stringPTR = &s;
	string	&stringREF = s;

	cout 
	<< "Address of string: " << &s << endl 
	<< "Address of ptr: " << &stringPTR << endl
	<< "Address of reference: " << &stringREF << endl << endl;

	cout 
	<< "string: " << s << endl 
	<< "ptr: " << stringPTR << endl
	<< "reference: " << stringREF << endl;

}
