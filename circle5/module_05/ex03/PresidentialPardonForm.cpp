/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:28:38 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/08 11:28:38 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
 
PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm(target, 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::doExecute(const Bureaucrat& bureaucrat) const
{
    (void) bureaucrat;
	std::cout << getName() << " has been pardoned by Zaphod Beeblbrox\n";	
}
