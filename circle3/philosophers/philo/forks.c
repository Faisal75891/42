/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:36:28 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/05 15:49:04 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// mutex locks the fork
int	take_fork(int *forks, int fork_num, int index)
{
	// ->
	if (forks[index] == 1
		&& forks[(index + 1) % fork_num] == 1)
	{
		forks[index] = 0;
		forks[(index + 1) % fork_num] = 0;
	}
	else
		return (0);
	return (1);
}

// mutex unlocks the fork
void	put_fork(int *forks, int fork_num, int index)
{
	if (forks[index] == 0
    	&& forks[(index + 1) % fork_num] == 0)
    {
		forks[index] = 1;
		forks[(index + 1) % fork_num] = 1;
	}
	// ->
	return ;
}
