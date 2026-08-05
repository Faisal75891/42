/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 22:04:15 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 16:49:45 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(void)
{
    int zombieSize = 1;
	Zombie  *z = zombieHorde(zombieSize, "gurrrr");
    
    for (int i = 0; i < zombieSize; i++)
    {
        z[i].announce();
    }
    delete[] z;
	return (1);
}
