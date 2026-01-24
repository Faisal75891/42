/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 21:55:47 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/24 21:55:47 by fbaras           ###   ########.fr       */
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
