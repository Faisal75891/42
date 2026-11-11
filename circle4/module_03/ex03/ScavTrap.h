/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:38:13 by fbaras            #+#    #+#             */
/*   Updated: 2026/11/10 16:38:13 by fbaras           ###   ########.fr       */
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
		ScavTrap(const ScavTrap& src);
		virtual ~ScavTrap();
		void	guardGate();
		void	attack(const std::string& target);
		ScavTrap&	operator=(const ScavTrap& src);
};

#endif