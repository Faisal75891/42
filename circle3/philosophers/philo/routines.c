/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:12:50 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/14 22:56:30 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO: use the table directly
static void	philosopher(t_table *table, t_philo *philo, int fork_num, pthread_mutex_t *mutexes, int *terminate)
{

	if (*terminate == 1)
		return ;
	change_state(philo, "thinking");
	print_state(philo, terminate, table->start_time);
	if (philo_eat(philo, fork_num, mutexes, terminate, table->start_time) == TRUE)
	{
		philo->num_of_times_eaten++;
		gettimeofday(&philo->last_eaten, NULL);
		if (*terminate == 1)
		{
			return ;
			printf(" dead\n");
		}
		philo_sleep(philo, terminate, table->start_time);
	}
}

void	*create_philo(void *args)
{
	t_thread_args	*arg;
	
	arg = (t_thread_args *)args;
	while (arg->table->start == FALSE)
		usleep(1);
	gettimeofday(&arg->table->philos[arg->index]->last_eaten, NULL);
	while (arg->table->terminate != 1
		&& arg->table->philos[arg->index]->num_of_times_eaten < arg->table->num_of_times_to_eat)
	{
		philosopher(arg->table,
			arg->table->philos[arg->index],
			arg->table->fork_num,
			arg->table->fork_mutexes,
			&arg->table->terminate);
	}
	return (0);
}

void	*monitor_philos(void *args)
{
	int				i;
	t_thread_args	*arg;

	arg = (t_thread_args *)args;
	while (!(arg->table->terminate == 1))
	{
		usleep(10);
		i = 0;
		while (i < arg->table->philos_num)
		{
			if (time_difference(arg->table->philos[i]->last_eaten) > arg->table->philos[i]->time_to_die)
			{
				philo_die(arg->table->philos[i]->id, arg->table->start_time);
				arg->table->terminate = 1;
				break ;
			}
			i++;
		}
	}
	i = 0;
	while (i < arg->table->philos_num)
	{
		// sometimes some threads dont get freed. idk why??
		pthread_detach(arg->threads[i]);
		i++;
	}
	return (0);
}
