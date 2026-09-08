#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat n("n", 700);
		std::cout << n << "\n";
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << '\n';
	}
	
	return (0);
}
