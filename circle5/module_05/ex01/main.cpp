/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:39:14 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/07 14:39:14 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat n("n", 700);
		std::cout << n << "\n";
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << '\n';
	}
	Bureaucrat alice("Alice", 10);
	Form document("Document", 20, 30);

	alice.signForm(document); // Alice signed Document
	return (0);
}
