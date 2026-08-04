#include "phonebook.h"

Contact Phonebook::create_contact()
{
	Contact	new_contact;
	string	f, l, n, d, p;
	int		index;
	int		current_count = get_count();

	cout << "First Name: ";
	cin >> f;
	cout << "Last Name: ";
	cin >> l;
	cout << "Nickname: ";
	cin >> n;
	cout << "Phone Number: ";
	cin >> p;
	cout << "Darkest Secret: ";
	cin.ignore();
	getline( cin, d);
	new_contact.set_first_name(f);
	new_contact.set_last_name(l);
	new_contact.set_nickname(n);
	new_contact.set_phone_number(p);
	new_contact.set_darkest_secret(d);
	new_contact.set_index(current_count % MAX_CONTACTS);
	return (new_contact);
}

void Phonebook::exit()
{
	cout << "exit\n";

}
void Phonebook::search()
{
	int		index = 0;

	display();
	cout << "Search: ";
	if (! (cin	>> index))
	{
		cout << "Invalid input!\n";
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
		}
	}
}

int	main()
{
	Phonebook	phonebook;
	Contact		new_contact;
	string		operation;

	cout	<< "\n------ MAIN MENU ------\n"
			<< "ADD: save a new contact\n"
			<< "SEARCH: display a specific contact\n"
			<< "EXIT: to exit the program\n"
			<< "-----------------------\n\n";
			
	while (1)
	{
		cout << "Enter operation: ";
		cin >> operation;
		if (operation == "ADD")
		{
			cin.ignore();
			new_contact = phonebook.create_contact();
			phonebook.append_contact(new_contact);
		}
		else if (operation == "SEARCH")
		{
			// I have to do all this so it doesn't infinite loop.
			cin.ignore();
			phonebook.search();
			cin.ignore();
			cin.clear();
			cin.sync();
		}
		else if (operation == "EXIT")
		{
			cin.ignore();
			phonebook.exit();
			return (1);
		}
		else
		{
			cin.clear();
			cin.sync();
		}			
	}
	return (1);
}
