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
#include <bits/stdc++.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm (target, 72, 45)
{
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
        std::cout << "Success! " << getName() << " has robotomized succefully\n";
    }
    else
    {
        std::cout << "Failure! Robotomy has failed\n";
    }
}
