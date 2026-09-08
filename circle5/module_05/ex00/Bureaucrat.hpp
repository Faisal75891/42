/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 01:37:08 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/07 01:37:08 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
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
		
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		const std::string	&getName() const;
		int					getGrade() const;
		void				increment_grade();
		void				decrement_grade();
};

std::ostream& operator<<(std::ostream &e, const Bureaucrat &s);
