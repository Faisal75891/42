/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:26:29 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/09 18:40:03 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// the basic idea before starting with threads.
void	philosophers(t_philo *philo, pthread_mutex_t mutex, int *forks, int fork_num)
{
	struct timeval start;

	change_state(&philo[philo->id], "thinking");
	print_state(philo);
	gettimeofday(&start, NULL);
	if (philo[philo->id].time_to_eat > 0)
	{
		if (!philo_eat(philo, forks, fork_num, start, mutex))
		{
			printf("didnt eat\n");
			philo_die(philo->id);
			return ;
		}
		gettimeofday(&start, NULL); // restart the time
		philo_sleep(philo);
	}
}

void	*routine(void *args)
{
	t_thread_args *arg = (t_thread_args *)args;
	
	while (arg->table->num_of_times_to_eat > arg->table->philos[arg->index]->num_of_times_eaten)
	{	
		philosophers(arg->table->philos[arg->index],arg->mutex, arg->table->forks, arg->table->fork_num);
		arg->table->philos[arg->index]->num_of_times_eaten++;
	}
	return (0);
}

void	philo(t_table *table)
{
	pthread_t		*th;
	t_thread_args	*args;
	pthread_mutex_t	fork_mutex;
	
	pthread_mutex_init(&fork_mutex, NULL);
	th = malloc (sizeof(pthread_t) * table->philos_num);
	if (!th)
		return ;
	args = malloc (sizeof(t_thread_args));
	if (!args)
	{
		free(th);
		pthread_mutex_destroy(&fork_mutex);
		return ;
	}
	args->table = table;
	args->index = 0;
	args->mutex = fork_mutex;
	while (args->index < table->philos_num - 1)
	{
		if (pthread_create(th + args->index, NULL, &routine, (void *)args) != 0)
		{
			printf("thread %d not started\n", args->index);
			return ;
		}
		args->index++;
	}
	if (pthread_create(&th[args->index], NULL, &routine, (void *)args) != 0)
	{
		printf("thread %d not started\n", args->index);
		return ;
	}
		
	int	i = 0;
	while (i <= table->philos_num)
	{
		if (pthread_join(th[i], NULL) != 0)
			return ;
		i++;
	}
	pthread_mutex_destroy(&fork_mutex);
}

// not using threads yet...
int	main(int argc, char **argv)
{
	t_table	*table;
	int		optional;

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

	return (0);
}
