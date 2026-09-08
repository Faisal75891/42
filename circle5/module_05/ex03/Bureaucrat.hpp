/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:15:50 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/07 17:15:50 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int			grade;
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		const std::string&	getName() const;
		int	getGrade() const;

		void	executeForm(AForm const & form) const;

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
		void				signForm(AForm &form);
		void				increment_grade();
		void				decrement_grade();
};

std::ostream& operator<<(std::ostream &e, const Bureaucrat &s);
