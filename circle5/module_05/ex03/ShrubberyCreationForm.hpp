/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:55:38 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/07 17:55:38 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		/* data */
	public:
		class FileOpenException : public std::exception
		{
			virtual const char	*what() const throw();
		};
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& );
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& );
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
	protected:
		void	doExecute(const Bureaucrat& bureaucrat) const;
};
