/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:38:53 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/08 11:38:53 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <exception>

class Intern
{
	private:
		/* data */
	public:
		class FormDoesNotExistException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		Intern(/* args */);
		~Intern();
		AForm	*makeForm(std::string target, std::string form);
};
