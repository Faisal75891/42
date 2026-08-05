/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 22:57:40 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 22:57:40 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.h"

class FragTrap  : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap();
		~FragTrap();
		void	highFiveGuys(void) const;
};
