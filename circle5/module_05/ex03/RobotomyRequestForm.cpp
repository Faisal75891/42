/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:08:41 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/08 11:08:41 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm (target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm (src)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::doExecute(const Bureaucrat &bureaucrat) const
{
	(void) bureaucrat;
	std::cout << "Burrrrrrrrrrrrrrrrrrrrrrr\n"
			<< "drilling in progress....\n";
	
	std::srand(time(0));
	if (std::rand() % 2)
    {
        std::cout << "Success! " << getName() << " has robotomized successfully\n";
    }
    else
    {
        std::cout << "Failure! Robotomy has failed\n";
    }
}
