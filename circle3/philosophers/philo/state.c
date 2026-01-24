/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:38:07 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/14 22:37:13 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// index: 0=thinking, 1=eating, 2=sleeping
void	change_state(t_table *table, int i, char *state)
{
	pthread_mutex_lock(&table->mutexes->state_mutex);
	if (ft_strcmp(state, "thinking") == 0)
	{
		table->philos[i]->state[0] = 1;
		table->philos[i]->state[1] = 0;
		table->philos[i]->state[2] = 0;
	}
	else if (ft_strcmp(state, "eating") == 0)
	{
		table->philos[i]->state[0] = 0;
		table->philos[i]->state[1] = 1;
		table->philos[i]->state[2] = 0;
	}
	else if (ft_strcmp(state, "sleeping") == 0)
	{
		table->philos[i]->state[0] = 0;
		table->philos[i]->state[1] = 0;
		table->philos[i]->state[2] = 1;
	}
	else
		printf("bad state\n");
	pthread_mutex_unlock(&table->mutexes->state_mutex);
}

// write
void	print_state(t_table *table, int i)
{
	pthread_mutex_lock(&table->mutexes->terminate_mutex);
	if (!table->philos[i] || table->terminate_flag == 1)
	{
		pthread_mutex_unlock(&table->mutexes->terminate_mutex);
		return ;
	}
	pthread_mutex_unlock(&table->mutexes->terminate_mutex);
	pthread_mutex_lock(&table->mutexes->printing_mutex);
	pthread_mutex_lock(&table->mutexes->state_mutex);
	if (table->philos[i]->state[2] == 0
		&& table->philos[i]->state[1] == 0
		&& table->philos[i]->state[0] == 1)
		printf("%lu %d is thinking\n",
			time_stamp() - table->starting_time, table->philos[i]->id);
	else if (table->philos[i]->state[2] == 0
		&& table->philos[i]->state[1] == 1 && table->philos[i]->state[0] == 0)
		printf("%lu %d is eating\n",
			time_stamp() - table->starting_time, table->philos[i]->id);
	else if (table->philos[i]->state[2] == 1
		&& table->philos[i]->state[1] == 0
		&& table->philos[i]->state[0] == 0)
		printf("%lu %d is sleeping\n",
			time_stamp() - table->starting_time, table->philos[i]->id);
	pthread_mutex_unlock(&table->mutexes->state_mutex);
	pthread_mutex_unlock(&table->mutexes->printing_mutex);
}
