#include "PhoneBook.h"
#include "Contact.h"

int	main()
{
	PhoneBook	    phonebook;
	Contact		    new_contact;
	std::string		operation;

	std::cout	
            << "\n------ MAIN MENU ------\n"
			<< "ADD: save a new contact\n"
			<< "SEARCH: display a specific contact\n"
			<< "EXIT: to exit the program\n"
			<< "-----------------------\n\n";
			
	while (1)
	{
		std::cout << "Enter operation: ";
		std::cin >> operation;
		if (std::cin.eof() == true)
			break ;
		if (operation == "ADD")
		{
			std::cin.ignore();
			new_contact = phonebook.create_contact();
			phonebook.append_contact(new_contact);
		}
		else if (operation == "SEARCH")
		{
			// I have to do all this so it doesn't infinite loop.
			// std::cin.ignore();
			phonebook.search();
			// std::cin.ignore();
			// std::cin.clear();
			// std::cin.sync();
		}
		else if (operation == "EXIT")
		{
			std::cin.ignore();
			phonebook.exit();
			return (1);
		}
		else
		{
			std::cin.clear();
			std::cin.sync();
		}
		operation.clear();
		std::cout	
            << "\n------ MAIN MENU ------\n"
			<< "ADD: save a new contact\n"
			<< "SEARCH: display a specific contact\n"
			<< "EXIT: to exit the program\n"
			<< "-----------------------\n\n";
	}
	return (1);
}
