/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 10:31:30 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/21 10:31:30 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
	private:
		/* data */
	public:
		Base(/* args */);
		virtual ~Base() {};
		Base(const Base& s);
		Base&	operator=(const Base& s);
		static Base*	generate(void);
		static void	identify(Base* p);
		static void	identify(Base& p);
};
