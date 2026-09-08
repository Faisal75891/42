/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:39:24 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/07 14:39:24 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("form grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("form grade too low");
}

Form::Form(std::string name, int grade_sign, int grade_execute) 
	: name(name), gradeSign(grade_sign), gradeExecute(grade_execute), isSigned(false)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeSign > 150 || gradeExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form created\n";
}

Form::~Form()
{
	std::cout << std::endl;
}

const	std::string& Form::getName() const
{
	return (name);
}

int	Form::get_grade_sign() const
{
	return (gradeSign);
}

int	Form::get_grade_execute() const
{
	return (gradeExecute);
}

int	Form::get_IsSigned() const
{
	return (isSigned);
}

void    Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeSign)
		throw GradeTooLowException();
	isSigned = true;
}

