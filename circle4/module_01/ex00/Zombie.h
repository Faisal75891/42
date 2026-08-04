/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 20:02:10 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/04 20:02:10 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie(std::string n);
		~Zombie();
		void	announce(void);
		std::string	getName( void ) const;
		void	setName( const std::string &n);
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );
