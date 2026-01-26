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
	if (arg->index % 2 == 0)
		usleep(1000);
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

static int	check_state(t_table *table, int i, int *all_done)
{
	if (!finished_eating(table, i))
		*all_done = 0;
	if (!finished_eating(table, i)
		&& time_difference(get_last_eaten(table, i))
		> table->philos[i]->time_to_die)
	{
		philo_die(table, i);
		return (FALSE);
	}
	return (TRUE);
}

void	*monitor_philos(void *args)
{
	int				i;
	t_thread_args	*arg;
	int				all_done;

	arg = (t_thread_args *)args;
	while (get_terminate_flag(arg->table) != 1)
	{
		usleep(1);
		i = 0;
		all_done = 1;
		while (i < arg->table->philos_num)
		{
			check_state(arg->table, i, &all_done);
			i++;
		}
		if (all_done)
			set_terminate_flag(arg->table, 1);
	}
	join_all_threads(args);
	return (0);
}
