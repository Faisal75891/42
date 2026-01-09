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

int	philo_eat(t_philo *philo, int *forks, int fork_num, struct timeval start, pthread_mutex_t mutex)
{
	struct timeval stop;

	// take fork and mutex lock
	pthread_mutex_lock(&mutex);
	if (take_fork(forks, fork_num, philo->id) == 0)
	{
		gettimeofday(&stop, NULL);
		if (philo->time_to_die < (stop.tv_usec - start.tv_usec))
		{
			put_fork(forks, fork_num, philo->id);
			return (0);
		}
		change_state(philo, "eating");
		print_state(philo);
		usleep(philo->time_to_eat);
		// put fork and mutex unlock
		put_fork(forks, fork_num, philo->id);
	}
	pthread_mutex_unlock(&mutex);
	return (1);
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
	printf("philosopher %d died\n", i);
}
