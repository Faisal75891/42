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

static void	philosopher(t_table *table, int i)
{
	if (get_terminate_flag(table) == 1)
		return ;
	change_state(table, i, "thinking");
	print_state(table, i);
	if (philo_eat(table, i) == TRUE)
	{
		increment_num_times_eaten(table, i);
		set_last_eaten_now(table, i);
		if (get_terminate_flag(table) == 1)
			return ;
		philo_sleep(table, i);
	}
}

void	*create_philo(void *args)
{
	t_thread_args	*arg;
	
	arg = (t_thread_args *)args;
	while (arg->table->start_flag == FALSE)
		usleep(1);
	set_last_eaten_now(arg->table, arg->index);
	if (get_num_times_eaten(arg->table, arg->index) >= arg->table->num_of_times_to_eat)
	{
		set_terminate_flag(arg->table, 1);
		return (0);
	}
	if (get_terminate_flag(arg->table) == 1)
		return (0);
	while (get_terminate_flag(arg->table) != 1
		&& get_num_times_eaten(arg->table, arg->index) < arg->table->num_of_times_to_eat)
	{
		philosopher(arg->table, arg->index);
	}
	return (0);
}

void	*monitor_philos(void *args)
{
	int				i;
	t_thread_args	*arg;

	arg = (t_thread_args *)args;
	while (get_terminate_flag(arg->table) != 1)
	{
		usleep(10);
		i = 0;
		while (i < arg->table->philos_num)
		{
			if (time_difference(get_last_eaten(arg->table, i)) > arg->table->philos[i]->time_to_die)
			{
				philo_die(arg->table, i);
				set_terminate_flag(arg->table, 1);
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
