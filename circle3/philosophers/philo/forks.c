/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:36:28 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/10 16:06:49 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(int *forks, int fork_num, int index, pthread_mutex_t *fork_mutexes)
{
	int	left;
	int	right;

	left = index;
	right = (index + 1) % fork_num;
	if (forks[left] == 1 && forks[right] == 1)
	{
		pthread_mutex_lock(&fork_mutexes[left]);
		forks[left] = 0;
		pthread_mutex_unlock(&fork_mutexes[left]);
		pthread_mutex_lock(&fork_mutexes[right]);
		forks[right] = 0;
		pthread_mutex_unlock(&fork_mutexes[right]);
		return (0);
	}
	return (1);
}

void	put_fork(int *forks, int fork_num, int index, pthread_mutex_t *fork_mutexes)
{
	int	left;
	int	right;

	left = index;
	right = (index + 1) % fork_num;
	if (forks[left] == 0 && forks[right] == 0)
	{
		pthread_mutex_lock(&fork_mutexes[right]);
		forks[right] = 1;
		pthread_mutex_unlock(&fork_mutexes[right]);
		pthread_mutex_lock(&fork_mutexes[left]);	
		forks[left] = 1;
		pthread_mutex_unlock(&fork_mutexes[left]);
	}
	return ;
}
