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

int	main(void)
{
	Bureaucrat	b("sigma", 45);

    {
        std::cout << "Shrubbery form test\n";
        ShrubberyCreationForm shrub("sigma_document");
        ShrubberyCreationForm  n(shrub);
        ShrubberyCreationForm s;

        s = shrub;
        b.executeForm(s);
        b.signForm(s);
        b.executeForm(s);
        Bureaucrat   insuffiecintGrade("bob", 146);
        insuffiecintGrade.signForm(shrub);
    }
        std::cout << "\n";

    {
        std::cout << "Robotomy form test\n";

        RobotomyRequestForm bo("hiiii");
        RobotomyRequestForm a(bo);
        RobotomyRequestForm e;

        e = a;
        b.executeForm(bo);
        b.signForm(bo);
        b.executeForm(bo);
        Bureaucrat   insuffiecintGrade("bob2", 146);
        insuffiecintGrade.signForm(bo);
    }
        std::cout << "\n";
    {
        std::cout << "Presidential form test\n";
        PresidentialPardonForm  presidentailForm("obama");
        PresidentialPardonForm  p(presidentailForm);
        PresidentialPardonForm  c;

        c = p;

        Bureaucrat  president("president", 1);
        president.executeForm(presidentailForm);
        president.signForm(presidentailForm);
        president.executeForm(presidentailForm);
        b.signForm(presidentailForm);
    }

}

/*
TODO:
Add tests for:
unsigned execution
insufficient signing grade
insufficient execution grade
successful execution
all three concrete forms
shrubbery file creation
robotomy success/failure behavior
*/