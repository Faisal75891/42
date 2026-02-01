/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:34:49 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/26 19:34:49 by fbaras           ###   ########.fr       */
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
		set_last_eaten_now(table, i);
		change_state(table, i, "eating");
		print_state(table, i);
		ft_usleep(table->philos[i]->time_to_eat);
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
		ft_usleep(table->philos[i]->time_to_sleep);
	}
}

void	philo_die(t_table *table, int i)
{
	pthread_mutex_lock(&table->mutexes->printing_mutex);
	printf("%lu %d died\n", time_stamp() - table->starting_time, i + 1);
	pthread_mutex_unlock(&table->mutexes->printing_mutex);
	set_terminate_flag(table, 1);
}
