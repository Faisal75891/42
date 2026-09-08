/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:58:04 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/07 16:58:04 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		const int	gradeToSign;
		const int	gradeToExecute;
		bool		isSigned;
	protected:
		virtual void	doExecute(const Bureaucrat& bureaucrat) const = 0;
	public:
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		~AForm();
		const std::string&	getName() const;
		int	getGradeToSign() const;
		int	getGradeToExecute() const;
		int			get_IsSigned() const;
		void    	beSigned(const Bureaucrat& b);
		void	execute(Bureaucrat const & executor) const;
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};
