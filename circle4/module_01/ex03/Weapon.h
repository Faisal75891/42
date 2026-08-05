/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 23:10:06 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/04 23:10:06 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string	&getType(void) const;
		void				setType(std::string new_type);
};

#endif
