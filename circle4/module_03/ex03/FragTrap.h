/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 23:02:24 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 23:02:24 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.h"

class FragTrap  : public virtual ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap();
		~FragTrap();
		void	highFiveGuys(void) const;
};
