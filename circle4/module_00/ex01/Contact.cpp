#include "Contact.h"
#include "PhoneBook.h"

Contact::Contact() : index(0)
{
}

Contact::~Contact()
{
}

void	Contact::display()
{
	if (first_name.size() > 10) {first_name.replace(9, 11, ".");}
	if (last_name.size() > 10) {last_name.replace(9, 11, ".");}
	if (nickname.size() > 10) {nickname.replace(9, 11, ".");}
	std::cout << std::setw(10) << std::right<< index
	<< "|"
	<< std::setw(10) << std::right << first_name.substr(0, 10)
	<< "|"
	<< std::setw(10) << std::right << last_name.substr(0, 10)
	<< "|"
	<< std::setw(10) << std::right << nickname.substr(0, 10)
	<< "|" << std::endl;
}

void			Contact::set_first_name(const std::string &name)
{
    first_name = name;
}

void			Contact::set_last_name(const std::string &name)
{
    last_name= name;
}

void			Contact::set_nickname(const std::string &name)
{
    nickname = name;
}

void			Contact::set_phone_number(const std::string &name)
{
    phone_number = name;
}

void			Contact::set_darkest_secret(const std::string &name)
{
    darkest_secret = name;
}

void			Contact::set_index(int i)
{
    index = i;
}

const std::string&	Contact::get_f_name() const
{
    return first_name;
}
