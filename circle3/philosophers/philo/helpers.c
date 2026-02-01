/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:35:15 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/26 19:35:15 by fbaras           ###   ########.fr       */
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

int	get_start_flag(t_table *table)
{
	int	flag;

	pthread_mutex_lock(&table->mutexes->start_mutex);
	flag = table->start_flag;
	pthread_mutex_unlock(&table->mutexes->start_mutex);
	return (flag);
}

void	set_start_flag(t_table *table, int flag)
{
	pthread_mutex_lock(&table->mutexes->start_mutex);
	table->start_flag = flag;
	pthread_mutex_unlock(&table->mutexes->start_mutex);
}
