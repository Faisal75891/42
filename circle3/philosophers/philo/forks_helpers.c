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

void	safe_print(t_table *table, int index)
{
	pthread_mutex_lock(&table->mutexes->printing_mutex);
	printf("%lu %d has taken a fork\n",
		time_stamp() - table->starting_time, index + 1);
	pthread_mutex_unlock(&table->mutexes->printing_mutex);
}

int	take_right_fork_first(t_table *table, int index,
	int left, int right)
{
	pthread_mutex_lock(&table->mutexes->fork_mutexes[left]);
	if (get_terminate_flag(table))
	{
		pthread_mutex_unlock(&table->mutexes->fork_mutexes[left]);
		return (FALSE);
	}
	safe_print(table, index);
	if (left == right)
	{
		while (!get_terminate_flag(table))
			usleep(100);
		pthread_mutex_unlock(&table->mutexes->fork_mutexes[left]);
		return (FALSE);
	}
	pthread_mutex_lock(&table->mutexes->fork_mutexes[right]);
	return (TRUE);
}

int	take_left_fork_first(t_table *table, int index,
	int left, int right)
{
	pthread_mutex_lock(&table->mutexes->fork_mutexes[right]);
	if (get_terminate_flag(table))
	{
		pthread_mutex_unlock(&table->mutexes->fork_mutexes[right]);
		return (FALSE);
	}
	safe_print(table, index);
	if (left == right)
	{
		while (!get_terminate_flag(table))
			usleep(100);
		pthread_mutex_unlock(&table->mutexes->fork_mutexes[right]);
		return (FALSE);
	}
	pthread_mutex_lock(&table->mutexes->fork_mutexes[left]);
	return (TRUE);
}

int	handle_one_philo(t_table *table, int index, int left)
{
	pthread_mutex_lock(&table->mutexes->fork_mutexes[left]);
	safe_print(table, index);
	while (!get_terminate_flag(table))
		usleep(500);
	pthread_mutex_unlock(&table->mutexes->fork_mutexes[left]);
	return (FALSE);
}
