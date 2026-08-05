#include <string>
#include <iostream>

int	main(void)
{
	std::string	s("HI THIS IS BRAIN");
	std::string	*stringPTR = &s;
	std::string	&stringREF = s;

	std::cout 
	<< "Address of string: " << &s << std::endl 
	<< "Address of ptr: " << &stringPTR << std::endl
	<< "Address of reference: " << &stringREF << std::endl << std::endl;

	std::cout 
	<< "string: " << s << std::endl 
	<< "ptr: " << stringPTR << std::endl
	<< "reference: " << stringREF << std::endl;
}
