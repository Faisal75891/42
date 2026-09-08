/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:39:19 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/07 14:39:19 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int			gradeSign;
		const int			gradeExecute;
		bool				isSigned;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		Form(std::string name, int gradeSign, int gradeExecute);
		~Form();
		const	std::string& getName() const;
		int	get_grade_sign() const;
		int	get_grade_execute() const;
		int			get_IsSigned() const;
		void    	beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream &os, const Form &f);
