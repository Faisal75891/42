/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:34:34 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/24 20:34:34 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_terminate_flag(t_table *table)
{
	int	flag;

	pthread_mutex_lock(&table->mutexes->terminate_mutex);
	flag = table->terminate_flag;
	pthread_mutex_unlock(&table->mutexes->terminate_mutex);
	return (flag);
}

void	set_terminate_flag(t_table *table, int value)
{
	pthread_mutex_lock(&table->mutexes->terminate_mutex);
	table->terminate_flag = value;
	pthread_mutex_unlock(&table->mutexes->terminate_mutex);
}

void	set_last_eaten_now(t_table *table, int index)
{
	pthread_mutex_lock(&table->mutexes->last_eaten_mutex);
	gettimeofday(&table->philos[index]->last_eaten, NULL);
	pthread_mutex_unlock(&table->mutexes->last_eaten_mutex);
}

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
