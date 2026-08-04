#include "Harl.h"

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
}

int main(int argc, char **argv)
{
	int		level;
	Harl	h;
	if (argc != 2)
	{
		cout << "./harlfilter \"LOG LEVEL\"\n";
		return (1);
	}
	if (!strcmp(argv[1], "DEBUG"))
		level = 0;
	else if (!strcmp(argv[1], "INFO"))
		level = 1;
	else if (!strcmp(argv[1], "WARNING"))
		level = 2;
	else if (!strcmp(argv[1], "ERROR"))
		level = 3;
	else
		level = -1;
	switch (level)
	{
	case 0:
		cout << "[ DEBUG ]\n";
		h.complain("DEBUG");
		cout << endl;
	case 1:
		cout << "[ INFO ]\n";
		h.complain("INFO");
		cout << endl;
	case 2:
		cout << "[ WARNING ]\n";
		h.complain("WARNING");
		cout << endl;
	case 3:
		cout << "[ ERROR ]\n";
		h.complain("ERROR");
		cout << endl;
		break;
	default:
		cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	}
}
