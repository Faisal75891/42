/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 21:59:08 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/04 22:09:54 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie  *zombies;
    int     i = 0;

    if (N < 1)
    {
        std::cout << "Can't have 0 or negative zombies\n";
        return (NULL);
    }
    zombies = new Zombie[N];
    while (i < N)
    {
        zombies[i].setName(name);
        i++;
    }
    return (zombies);
}
