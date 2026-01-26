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

int	philo_eat(t_table *table, int i)
{
	if (take_fork(table, i) == TRUE)
	{
		if (get_terminate_flag(table) == 1)
		{
			put_fork(table, i);
			return (FALSE);
		}
		change_state(table, i, "eating");
		print_state(table, i);
		usleep(table->philos[i]->time_to_eat * 1000);
		put_fork(table, i);
		return (TRUE);
	}
	return (FALSE);
}

void	philo_sleep(t_table *table, int i)
{
	if (get_terminate_flag(table) == 1)
		return ;
	if (table->philos[i]->time_to_sleep > 0)
	{
		change_state(table, i, "sleeping");
		print_state(table, i);
		usleep(table->philos[i]->time_to_sleep * 1000);
	}
}

void	philo_die(t_table *table, int i)
{
	pthread_mutex_lock(&table->mutexes->printing_mutex);
	printf("%lu %d died\n", time_stamp() - table->starting_time, i);
	pthread_mutex_unlock(&table->mutexes->printing_mutex);
	set_terminate_flag(table, 1);
}
