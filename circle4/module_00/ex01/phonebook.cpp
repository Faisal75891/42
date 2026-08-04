#include "PhoneBook.h"
#include "Contact.h"

void	header();

PhoneBook::PhoneBook() : contacts_count(0)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::append_contact(Contact &c)
{
	contacts[contacts_count % MAX_CONTACTS] = c;
	if (contacts_count < MAX_CONTACTS)
		increment_count();
}

int		PhoneBook::get_count() const
{
	return (contacts_count);
}

void	PhoneBook::increment_count()
{ 
	this->contacts_count++;
}

Contact	*PhoneBook::retrieve(int i)
{
	if (i >= 0 && i < contacts_count)
		return (&contacts[i]);
	std::cout << "There is no such record\n";
	return (NULL);
}

void	PhoneBook::display()
{
	int	i;
	
	i = 0;
	header();
	while (i < contacts_count && i < 4)
	{
		display(i);
		i++;
	}
	std::cout << "---------------------------------------------\n";
}

Contact PhoneBook::create_contact()
{
	Contact		new_contact; // = new Contact();
	std::string	f, l, n, d, p;
	int			current_count = get_count();

	std::cout << "First Name: ";
	std::cin >> f;
	std::cout << "Last Name: ";
	std::cin >> l;
	std::cout << "Nickname: ";
	std::cin >> n;
	std::cout << "Phone Number: ";
	std::cin >> p;
	std::cout << "Darkest Secret: ";
	std::cin.ignore();
	getline(std::cin, d);
	new_contact.set_first_name(f);
	new_contact.set_last_name(l);
	new_contact.set_nickname(n);
	new_contact.set_phone_number(p);
	new_contact.set_darkest_secret(d);
	new_contact.set_index(current_count % MAX_CONTACTS);
	return (new_contact);
}

void	header()
{
	std::string line = "---------------------------------------------";
	std::cout << line << std::endl;
	std::cout << std::setw(10) << std::right << "Index"
			<< "|"
			<< std::setw(10) << std::right << "first name" 
			<< "|"
			<< std::setw(10) << std::right << "last name"
			<< "|"
			<< std::setw(10) << std::right << "nickname"
			<< "|" << std::endl;
	std::cout << line << std::endl;
}

void PhoneBook::exit()
{
	std::cout << "exit\n";

}
void PhoneBook::search()
{
	int		index = 0;

	display();
	std::cout << "Search: ";
	if (this->contacts_count == 0)
	{
		std::cout << "Please add a contact first\n";
		return ;
	}
	if (! (std::cin	>> index) || index < 0 )
	{
		std::cout << "Invalid input!\n";
		std::cin.clear();
	}
	else if (index > MAX_CONTACTS && index < 0)
	{
		if (index < 0)
			index = -index;
		if (index > MAX_CONTACTS)
			index = index % MAX_CONTACTS;
	}
	else
	{
		Contact *contact = retrieve(index);
		if (contact)
		{
			header();
			display(index);
			std::cout << "---------------------------------------------\n";
		}
	}
}

void	PhoneBook::display(int i)
{
	contacts[i].display();
}

