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

int	philo_eat(t_philo *philo, int *forks, int fork_num, pthread_mutex_t *mutexes)
{
	struct timeval	now;

	if (take_fork(forks, fork_num, philo->id, mutexes) == 0)
	{
		gettimeofday(&now, NULL);
		if (philo->time_to_die < now.tv_usec - philo->last_eaten.tv_usec)
			return (0);
		change_state(philo, "eating");
		print_state(philo);
		usleep(philo->time_to_eat);
		put_fork(forks, fork_num, philo->id, mutexes);
	}
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
