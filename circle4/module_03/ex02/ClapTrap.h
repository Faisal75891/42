/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:36:03 by fbaras            #+#    #+#             */
/*   Updated: 2026/11/10 16:36:03 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	protected:
		std::string	name;
		int	hp, ad, ep;
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &src);
		ClapTrap(std::string name);
		virtual ~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	display() const;

		ClapTrap&	operator=(const ClapTrap& src);
};

#endif
