#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat n("n", 3);
        Bureaucrat e;
        Bureaucrat a(e);

        // copies only grade because name is const
        e = n;
		std::cout << n << "\n";
		std::cout << e << "\n";
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << '\n';
	}
	
    Bureaucrat bureaucrat("faisal", 2);
    std::cout << "My Grade is: " << bureaucrat.getGrade() << std::endl;
    std::cout << "My name is: " << bureaucrat.getName() << std::endl;
    bureaucrat.increment_grade();
    std::cout << "after incrementing my grade: " << bureaucrat.getGrade() << std::endl;
    try
    {
        std::cout << "After increment_grade too much: ";
        bureaucrat.increment_grade();
        bureaucrat.increment_grade();
        bureaucrat.increment_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    bureaucrat.decrement_grade();
    bureaucrat.decrement_grade();
    std::cout << "after decrementing my grade: " << bureaucrat.getGrade() << std::endl;

    try
    {
        Bureaucrat  test("test", 150);
        std::cout << "after decrementing my grade: \n";
        test.decrement_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Bureaucrat("Jeff", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat("test", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
	return (0);
}


