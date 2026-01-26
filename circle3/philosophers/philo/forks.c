/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:23:23 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/26 18:23:46 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_table *table, int index)
{
	int	left;
	int	right;

	if (table->fork_num < 1)
		return (FALSE);
	left = index;
	right = (index + 1) % table->fork_num;
	if (left == right)
		return (handle_one_philo(table, index, left));
	if (index % 2 == 0)
	{
		if (!take_right_fork_first(table, index, left, right))
			return (FALSE);
	}
	else if (!take_left_fork_first(table, index, left, right))
		return (FALSE);
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
