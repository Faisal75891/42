/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 23:02:38 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 23:02:38 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public virtual ClapTrap
{
	private:
		bool gateMode;
	public:
		ScavTrap(std::string name);
		ScavTrap();
		~ScavTrap();
		void	guardGate();
		void	attack(const std::string& target);
};

#endif
