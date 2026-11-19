/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:26:34 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/08 11:26:34 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		/* data */
	public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& );
        PresidentialPardonForm& operator=(const PresidentialPardonForm& );
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
	protected:
		void	doExecute(const Bureaucrat &bureaucrat) const;
};
