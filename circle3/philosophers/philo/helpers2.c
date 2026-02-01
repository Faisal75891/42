/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:35:20 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/26 19:35:20 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct timeval	get_last_eaten(t_table *table, int index)
{
	struct timeval	stamp;

	pthread_mutex_lock(&table->mutexes->last_eaten_mutex);
	stamp = table->philos[index]->last_eaten;
	pthread_mutex_unlock(&table->mutexes->last_eaten_mutex);
	return (stamp);
}

int	get_num_times_eaten(t_table *table, int index)
{
	int	count;

	pthread_mutex_lock(&table->mutexes->num_of_times_eaten_mutex);
	count = table->philos[index]->num_of_times_eaten;
	pthread_mutex_unlock(&table->mutexes->num_of_times_eaten_mutex);
	return (count);
}

void	increment_num_times_eaten(t_table *table, int index)
{
	pthread_mutex_lock(&table->mutexes->num_of_times_eaten_mutex);
	table->philos[index]->num_of_times_eaten++;
	pthread_mutex_unlock(&table->mutexes->num_of_times_eaten_mutex);
}

int	get_state(t_table *table, int i)
{
	pthread_mutex_lock(&table->mutexes->state_mutex);
	if (table->philos[i]->state[0] == 1)
	{
		pthread_mutex_unlock(&table->mutexes->state_mutex);
		return (0);
	}
	else if (table->philos[i]->state[1] == 1)
	{
		pthread_mutex_unlock(&table->mutexes->state_mutex);
		return (1);
	}
	else if (table->philos[i]->state[2] == 1)
	{
		pthread_mutex_unlock(&table->mutexes->state_mutex);
		return (2);
	}
	else
	{
		pthread_mutex_unlock(&table->mutexes->state_mutex);
		return (-1);
	}
}

int	finished_eating(t_table *table, int i)
{
	return (get_num_times_eaten(table, i) >= table->num_of_times_to_eat);
}
