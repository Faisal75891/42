/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:46:16 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/07 17:46:16 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	b("sigma", 45);
	ShrubberyCreationForm shrub("sigma_document");
    RobotomyRequestForm bo("hiiii");
    Intern  randomBo;
    AForm	*wo;

    wo = randomBo.makeForm("New form", "ShrubberyCreationForm");

	b.signForm(*wo);
    b.executeForm(*wo);

	delete wo;
}
