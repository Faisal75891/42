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

static void	safe_print(t_table *table, int index)
{
	pthread_mutex_lock(&table->mutexes->printing_mutex);
	printf("%lu %d has taken a fork\n",
		time_stamp() - table->starting_time, index);
	pthread_mutex_unlock(&table->mutexes->printing_mutex);
}

static int	take_right_fork_first(t_table *table, int index,
	int left, int right)
{
	pthread_mutex_lock(&table->mutexes->fork_mutexes[left]);
	if (get_terminate_flag(table))
	{
		pthread_mutex_unlock(&table->mutexes->fork_mutexes[left]);
		return (FALSE);
	}
	safe_print(table, index);
	pthread_mutex_lock(&table->mutexes->fork_mutexes[right]);
	return (TRUE);
}

static int	take_left_fork_first(t_table *table, int index,
	int left, int right)
{
	pthread_mutex_lock(&table->mutexes->fork_mutexes[right]);
	if (get_terminate_flag(table))
	{
		pthread_mutex_unlock(&table->mutexes->fork_mutexes[right]);
		return (FALSE);
	}
	safe_print(table, index);
	pthread_mutex_lock(&table->mutexes->fork_mutexes[left]);
	return (TRUE);
}

int	take_fork(t_table *table, int index)
{
	int	left;
	int	right;

	if (table->fork_num <= 1)
		return (FALSE);
	left = index;
	right = (index + 1) % table->fork_num;
	if (index % 2 == 0)
	{
		if (!take_right_fork_first(table, index, left, right))
			return (FALSE);
	}
	else
	{
		if (!take_left_fork_first(table, index, left, right))
			return (FALSE);
	}
	if (get_terminate_flag(table))
	{
		pthread_mutex_unlock(&table->mutexes->fork_mutexes[left]);
		pthread_mutex_unlock(&table->mutexes->fork_mutexes[right]);
		return (FALSE);
	}
	safe_print(table, index);
	return (TRUE);
}

void	put_fork(t_table *table, int index)
{
	int	left;
	int	right;

	left = index;
	right = (index + 1) % table->fork_num;
	pthread_mutex_unlock(&table->mutexes->fork_mutexes[left]);
	pthread_mutex_unlock(&table->mutexes->fork_mutexes[right]);
}

/*
1. Always lock lower-numbered fork first
terminate_flag 
or

2. Odd-Even Strategy
Odd-numbered philosophers pick up left fork first
Even-numbered philosophers pick up right fork first

*/