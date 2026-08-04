#include "Harl.h"

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	cout << "Debug\n";
}

void	Harl::info( void )
{
	cout << "Info\n";
}

void	Harl::warning( void )
{
	cout << "warning\n";
}

void	Harl::error( void )
{
	cout << "error\n";
}

void	Harl::complain(string level)
{
	void	(Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	if (level == "DEBUG")
		(this->*ptr[0])();
	else if (level == "INFO")
		(this->*ptr[1])();
	else if (level == "WARNING")
		(this->*ptr[2])();
	else if (level == "ERROR")
		(this->*ptr[3])();
	// else
	// 	(this->*ptr[3])();
}

int	main(void)
{
	Harl h;

	h.complain("INFO");
	h.complain("ffasjflkas");
	return (0);
}
