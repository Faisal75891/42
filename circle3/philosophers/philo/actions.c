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

// if can take fork
// and gave time to eat
// and put fork back
// return 1
// else return 0
int	philo_eat(t_philo *philo, int *forks, int fork_num, pthread_mutex_t *mutexes)
{
	struct timeval	now;

	if (take_fork(forks, fork_num, philo->id, mutexes) == TRUE)
	{
		gettimeofday(&now, NULL);
		if (philo->time_to_die < now.tv_usec - philo->last_eaten.tv_usec)
		{
			printf("time to die was too low :(\n");
			return (FALSE);
		}
		change_state(philo, "eating");
		print_state(philo);
		usleep(philo->time_to_eat);
		put_fork(forks, fork_num, philo->id, mutexes);
		return (TRUE);
	}
	return (FALSE);
}

void	philo_sleep(t_philo *philo)
{
	if (philo->time_to_sleep > 0)
	{
		change_state(philo, "sleeping");
		print_state(philo);
		usleep(philo->time_to_sleep);
	}
}

void	philo_die(int i)
{
	printf("%lu %d died\n", time_stamp(), i);
}
