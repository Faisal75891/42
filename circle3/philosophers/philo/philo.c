/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:26:29 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/10 19:18:10 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// the basic idea before starting with threads.
void	philosophers(t_philo *philo, int *forks, int fork_num, pthread_mutex_t *mutexes, int *terminate)
{
	struct timeval	now;


	change_state(philo, "thinking");
	print_state(philo);
	gettimeofday(&now, NULL);
	if (philo->time_to_eat >
		(philo->last_eaten.tv_usec - now.tv_usec))
	{
		if (philo_eat(philo, forks, fork_num, mutexes) == 1)
		{
			gettimeofday(&philo->last_eaten, NULL);
			philo_sleep(philo);
		}
		else
		{
			philo_die(philo->id);
			*terminate = 1;
			return ;
		}
	}
}

void	*routine(void *args)
{
	t_thread_args	*arg;
	
	arg = (t_thread_args *)args;
	while (arg->table->num_of_times_to_eat > arg->table->philos[arg->index]->num_of_times_eaten && arg->table->terminate != 1)
	{	
		philosophers(arg->table->philos[arg->index],
			arg->table->forks,
			arg->table->fork_num,
			arg->table->fork_mutexes,
			&arg->table->terminate);
		arg->table->philos[arg->index]->num_of_times_eaten++;
	}
	if (arg->table->terminate == 1)
		return ((void *)1);
	return (0);
}

void	philo(t_table *table)
{
	pthread_t		*th;
	t_thread_args	*args;
	int				i;
	//void			*status;

	th = malloc (sizeof(pthread_t) * table->philos_num);
	if (!th)
		return ;
	args = malloc (sizeof(t_thread_args) * table->philos_num);
	if (!args)
	{
		free(th);
		return ;
	}
	i = 0;
	while (i < table->philos_num)
	{
		args[i].table = table;
		args[i].index = i;
		args[i].thread = th[i];
		if (pthread_create(th + i, NULL, &routine, (void *)&args[i]) != 0)
		{
			printf("thread %d not started\n", i);
			return ;
		}
		i++;
	}
	i = 0;
	while (i < table->philos_num)
	{
		if (pthread_join(th[i], NULL) != 0)
			return ;
		// int	temp = (int)(intptr_t)status;
		// if (temp == 1)
		// {
		// 	i = 0;
		// 	while (i < table->philos_num)
		// 	{
		// 		pthread_cancel(th[i]);
		// 		i++;
		// 	}
		// }
		// printf("status: %d\n", temp);
		i++;
	}
	free(th);
	free(args);
}

int	main(int argc, char **argv)
{
	t_table	*table;
	int		optional;
	int		i;

	optional = 0;
	if (argc < 5)
	{
		printf("USAGE: ./philo number_of_philosophers time_to_die time_to_eat\
			time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	else if (argc == 6)
		optional = 1;
	table = init_table_and_philos(argv, optional);
	if (!table)
	{
		return (0);
	}
	philo(table);
	free_philos(table->philos);
	free(table->forks);
	i = 0;
	while (i < table->fork_num)
	{
		pthread_mutex_destroy(&table->fork_mutexes[i]);
		i++;
	}
	free(table->fork_mutexes);
	free(table);
	return (0);
}
