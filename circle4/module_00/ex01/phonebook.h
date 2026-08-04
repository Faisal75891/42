#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define MAX_CONTACTS 3

class Contact
{
	private:
		int		index;
		string	first_name, last_name, nickname,
				darkest_secret, phone_number;
	public:
		Contact() { index = 0; }
		void	display()
		{
			if (first_name.size() > 10) {first_name.replace(9, 11, ".");}
			if (last_name.size() > 10) {last_name.replace(9, 11, ".");}
			if (nickname.size() > 10) {nickname.replace(9, 11, ".");}
			cout << setw(10) << right<< index
			<< "|"
			<< setw(10) << right << first_name.substr(0, 10)
			<< "|"
			<< setw(10) << right << last_name.substr(0, 10)
			<< "|"
			<< setw(10) << right << nickname.substr(0, 10)
			<< "|" << endl;
		}
		void			set_first_name(const string &name) { first_name = name; }
		void			set_last_name(const string &name) { last_name= name; }
		void			set_nickname(const string &name) { nickname = name; }
		void			set_phone_number(const string &name) { phone_number = name; }
		void			set_darkest_secret(const string &name) { darkest_secret = name; }
		void			set_index(int i) { index = i; }
		const string	&get_f_name() const { return first_name; }
};

class Phonebook
{
private:
	Contact	contacts[MAX_CONTACTS];
	int		contacts_count;
public:
	Phonebook() { contacts_count = 0; }
	Contact	create_contact();
	void	search();
	void	display(int i)
	{
		contacts[i].display();
	}
	void	header()
	{
		string line = "---------------------------------------------";
		cout << line << endl;
		cout << setw(10) << right << "Index"
			 << "|"
			 << setw(10) << right << "first name" 
			 << "|"
			 << setw(10) << right << "last name"
			 << "|"
			 << setw(10) << right << "nickname"
			 << "|" << endl;
		cout << line << endl;
	}
	void	display()
	{
		int	i = 0;
		header();
		while (i < contacts_count && i < 4)
		{
			display(i);
			i++;
		}
		cout << "---------------------------------------------\n";
	}
	void	exit();
	int		get_count() const { return (contacts_count); }
	void	increment_count() { contacts_count++; }
	void	append_contact(Contact &c)
	{
		contacts[contacts_count % MAX_CONTACTS] = c;
		if (contacts_count < MAX_CONTACTS)
			increment_count();
	}
	Contact	*retrieve(int i)
	{
		if (i >= 0 && i < contacts_count)
			return (&contacts[i]);
		cout << "There is no such record\n";
		return (NULL);
	}
};

// Phonebook::Phonebook(/* args */)
// {
// }

// Phonebook::~Phonebook()
// {
// }
