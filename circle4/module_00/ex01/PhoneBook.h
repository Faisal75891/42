
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.h"

#define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact	contacts[MAX_CONTACTS];
		int		contacts_count;
	public:
		PhoneBook();
		~PhoneBook();
		Contact	create_contact();
		void	search();
		void	display(int i);
		void	display();
		void	exit();
		int		get_count() const;
		void	increment_count();
		void	append_contact(Contact &c);
		Contact	*retrieve(int i);
};

#endif
