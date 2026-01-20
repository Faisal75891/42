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
int	philo_eat(t_philo *philo, int fork_num, pthread_mutex_t *mutexes, int *terminate, unsigned long start_time)
{
	if (take_fork(fork_num, philo->id, mutexes, terminate, start_time) == TRUE)
	{
		if (*terminate == 1)
		{
			put_fork(fork_num, philo->id, mutexes);	
			return (FALSE);
		}
		change_state(philo, "eating");
		print_state(philo, terminate, start_time);
		usleep(philo->time_to_eat * 1000);
		put_fork(fork_num, philo->id, mutexes);
		return (TRUE);
	}
	return (FALSE);
}

void	philo_sleep(t_philo *philo, int *terminate, unsigned long start_time)
{
	if (philo->time_to_sleep > 0 && *terminate != 1)
	{
		change_state(philo, "sleeping");
		print_state(philo, terminate, start_time);
		usleep(philo->time_to_sleep * 1000);
	}
}

void	philo_die(int i, unsigned long start_time)
{
	printf("%lu %d died\n", time_stamp() - start_time, i);
}
