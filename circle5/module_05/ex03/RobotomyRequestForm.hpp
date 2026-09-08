/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:04:47 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/08 11:04:47 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		/* data */
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
	protected:
		void	doExecute(const Bureaucrat &bureaucrat) const;
};
