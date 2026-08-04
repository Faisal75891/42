
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
	private:
		int			index;
		std::string	first_name, last_name, nickname,
					darkest_secret, phone_number;
	public:
		Contact();
		~Contact();
		void			    display();
		void			    set_first_name(const std::string &name);	
		void			    set_last_name(const std::string &name); 
		void			    set_nickname(const std::string &name); 
		void			    set_phone_number(const std::string &name);
		void			    set_darkest_secret(const std::string &name);
		void			    set_index(int i);
		const std::string	&get_f_name() const;
};

#endif