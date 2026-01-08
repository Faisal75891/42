/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:01:48 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/07 13:01:48 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo, int *forks, int fork_num, int i, struct timeval start)
{
	struct timeval stop;

	// take fork and mutex lock
	if (!take_fork(forks, fork_num, i))
	{
		gettimeofday(&stop, NULL);
		if (philo->time_to_die < (stop.tv_usec - start.tv_usec))
		{
			put_fork(forks, fork_num, i);
			return (0);
		}
		change_state(philo, "eating");
		print_state(philo, i);
		usleep(philo->time_to_eat);
		// put fork and mutex unlock
		put_fork(forks, fork_num, i);
	}
	return (1);
}

void	philo_sleep(t_philo *philo, int i)
{
	if (philo->time_to_sleep > 0)
	{
		change_state(philo, "sleeping");
		print_state(philo, i);
		usleep(philo->time_to_sleep);
	}
}

void	philo_die(int i)
{
	printf("philosopher %d died\n", i);
}
