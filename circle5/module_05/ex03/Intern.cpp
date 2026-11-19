/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:43:46 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/08 11:43:46 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);        
}

Intern::~Intern()
{
}

const char	*Intern::FormDoesNotExistException::what() const throw()
{
	return ("Form not found");
}

static AForm *createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *createPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}


AForm	*Intern::makeForm(std::string target, std::string form)
{
	const std::string names[] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};

	AForm	*(*forms[])(std::string) = {
		createShrubbery,
		createRobotomy,
		createPardon,
	};
	for (int i = 0; i < 3; i++)
	{
		if (form.compare(names[i]) == false)
		{
			std::cout << "Intern creates " << form << std::endl;
			return (forms[i](target));
		}
	}

	throw FormDoesNotExistException();
}
