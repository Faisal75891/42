/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:36:28 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/09 17:02:41 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// mutex locks the fork
int	take_fork(int *forks, int fork_num, int index)
{
	int	left;
	int	right;
	// ->

	left = index;
	right = (index + 1) % fork_num;
	if (!forks || index < 0 || index >= fork_num)
		return (1);
	if (forks[left] == 1 && forks[right] == 1)
	{
		forks[left] = 0;
		forks[right] = 0;
		return (0);
	}
	return (1);
}

// mutex unlocks the fork
void	put_fork(int *forks, int fork_num, int index)
{
	int	left;
	int	right;

	left = index;
	right = (index + 1) % fork_num;
	if (forks[left] == 0 && forks[right] == 0)
	{
		forks[left] = 1;
		forks[right] = 1;
	}
	// ->
	return ;
}
