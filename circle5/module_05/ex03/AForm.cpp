/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:04:24 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/07 17:04:24 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Form Grade too high lil bro");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Form Grade too low");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form Not Signed");
}

AForm::AForm() : name(""), gradeToSign(150), gradeToExecute(150), isSigned(false)
{
    
}

AForm::AForm(const AForm& src) : name(src.name), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute), isSigned(src.isSigned)
{
    
}

AForm& AForm::operator=(const AForm& src)
{
    if (this != &src)
    {
        this->isSigned = src.isSigned;
    }
    return (*this);
}


AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: name(name), gradeToSign(gradeToSign),  gradeToExecute(gradeToExecute), isSigned(false)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
}

void	AForm::execute(const Bureaucrat& bureaucrat) const
{
	if (!isSigned)
		throw FormNotSignedException();
	if (bureaucrat.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	
	doExecute(bureaucrat);
}

const std::string&	AForm::getName() const
{
	return (name);
}

int	AForm::get_IsSigned() const
{
	return (isSigned);
}

void    AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

int	AForm::getGradeToSign() const
{
	return (gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (gradeToExecute);
}

std::ostream& operator<<(std::ostream &os, const AForm &f)
{
    os << "Form: <" << f.getName()
        << ">, grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute()
        << "signed: " << f.get_IsSigned() << std::endl;
    return (os);
}
