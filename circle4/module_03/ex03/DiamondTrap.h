/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 23:02:02 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 23:02:02 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.h"
#include "ScavTrap.h"

/*
Of course, the ClapTrap instance of DiamondTrap will be created once, and only once.
Yes, there’s a trick.??????????????
*/

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		void	attack(const std::string& target);// override;
		void	whoAmI();
};
