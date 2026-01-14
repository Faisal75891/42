/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:36:28 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/14 22:59:18 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(int *forks, int fork_num, int index, pthread_mutex_t *fork_mutexes, int *terminate, unsigned long start_time)
{
	(void) forks;
	int	left;
	int	right;

	if (fork_num <= 1)
		return (FALSE);
	left = index;
	right = (index + 1) % fork_num;
	
	// Block here until left fork is available
	pthread_mutex_lock(&fork_mutexes[left]);
	if (*terminate)
	{
		pthread_mutex_unlock(&fork_mutexes[left]);
		return (FALSE);
	}
	printf("%lu %d has taken a fork\n", time_stamp() - start_time, index);
	
	// Block here until right fork is available
	pthread_mutex_lock(&fork_mutexes[right]);
	if (*terminate)
	{
		pthread_mutex_unlock(&fork_mutexes[right]);
		pthread_mutex_unlock(&fork_mutexes[left]);
		return (FALSE);
	}
	printf("%lu %d has taken a fork\n", time_stamp() - start_time, index);
	
	return (TRUE);
}

void	put_fork(int *forks, int fork_num, int index, pthread_mutex_t *fork_mutexes)
{
	int	left;
	int	right;

	(void)forks;
	left = index;
	right = (index + 1) % fork_num;
	pthread_mutex_unlock(&fork_mutexes[right]);
	pthread_mutex_unlock(&fork_mutexes[left]);
}
