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

// main code logic

// TODO: use the table directly
static void	philosopher(t_table *table, t_philo *philo, int *forks, int fork_num, pthread_mutex_t *mutexes, int *terminate)
{

	if (*terminate == 1)
		return ;
	change_state(philo, "thinking");
	print_state(philo, terminate, table->start_time);
	if (philo_eat(philo, forks, fork_num, mutexes, terminate, table->start_time) == TRUE)
	{
		philo->num_of_times_eaten++;
		gettimeofday(&philo->last_eaten, NULL);
		if (*terminate == 1)
			return ;
		philo_sleep(philo, terminate, table->start_time);
	}
	else if (time_difference(philo->last_eaten) >= philo->time_to_die)
	{
		printf("time difference %lld\n", time_difference(philo->last_eaten));
		struct timeval now;
		gettimeofday(&now, NULL);
		printf("\nphilo last eaten [%lu]\ntime to die [%d]\nand currecnt time [%lu]\n\n", philo->last_eaten.tv_usec, philo->time_to_die, now.tv_usec);
		philo_die(philo->id, table->start_time);
		*terminate = 1;
		return ;
	}
	usleep(10000);
	//printf("num of times eaten for philo %d is %d\n", philo->id, philo->num_of_times_eaten);
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
			arg->table->forks,
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
		usleep(100);
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
