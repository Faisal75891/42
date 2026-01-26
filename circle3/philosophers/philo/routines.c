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
	if (get_state(table, i) != 0)
	{
		change_state(table, i, "thinking");
		print_state(table, i);
	}
	if (philo_eat(table, i) == TRUE)
	{
		increment_num_times_eaten(table, i);
		set_last_eaten_now(table, i);
		if (get_terminate_flag(table) == 1)
			return ;
		philo_sleep(table, i);
		if (get_terminate_flag(table) == 1)
			return ;
		change_state(table, i, "thinking");
		print_state(table, i);
		return ;
	}
}

void	*create_philo(void *args)
{
	t_thread_args	*arg;

	arg = (t_thread_args *)args;
	while (get_start_flag(arg->table) == FALSE)
		usleep(1);
	set_last_eaten_now(arg->table, arg->index);
	if (get_num_times_eaten(arg->table, arg->index)
		>= arg->table->num_of_times_to_eat)
	{
		return (0);
	}
	if (get_terminate_flag(arg->table) == 1)
		return (0);
	while (get_terminate_flag(arg->table) != 1
		&& get_num_times_eaten(arg->table, arg->index)
		< arg->table->num_of_times_to_eat)
	{
		philosopher(arg->table, arg->index);
	}
	return (0);
}

static void	join_all_threads(t_thread_args *arg)
{
	int	i;

	i = 0;
	while (i < arg->table->philos_num)
	{
		if (pthread_join(arg->threads[i], NULL) != 0)
		{
			return ;
		}
		i++;
	}
}

void	*monitor_philos(void *args)
{
	int				i;
	t_thread_args	*arg;
	int				all_done;

	arg = (t_thread_args *)args;
	while (get_terminate_flag(arg->table) != 1)
	{
		usleep(1000);
		i = 0;
		all_done = 1;
		while (i < arg->table->philos_num)
		{
			if (!finished_eating(arg->table, i) && /*get_state(arg->table, i) != eating &&*/ time_difference(get_last_eaten(arg->table, i))
				> arg->table->philos[i]->time_to_die)
			{
				all_done = 0;
				philo_die(arg->table, i);
				break ;
			}
			i++;
		}
		if (all_done)
			set_terminate_flag(arg->table, 1);
	}
	join_all_threads(args);
	return (0);
}
