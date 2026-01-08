/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:26:29 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/08 15:19:41 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// the basic idea before starting with threads.
void	philosophers(t_table *table, int i)
{
	struct timeval start;

	while (table->num_of_times_to_eat > table->philos[i]->num_of_times_eaten)
	{
		change_state(table->philos[i], "thinking");
		print_state(table->philos[i], i);
		gettimeofday(&start, NULL);
		if (table->philos[i]->time_to_eat > 0)
		{
			if (!philo_eat(table->philos[i], table->forks, table->fork_num, i, start))
			{
				printf("didnt eat\n");
				philo_die(i);
				return ;
			}
			gettimeofday(&start, NULL); // restart the time
			philo_sleep(table->philos[i], i);
		}
		printf("\n");
		table->philos[i]->num_of_times_eaten++;
	}
	
}

void	*routine(void *args)
{
	t_thread_args *arg = (t_thread_args *)args;
	
	philosophers(arg->table, arg->index);
	return (0);
}

void	philo(t_table *table)
{
	pthread_t		th;
	t_thread_args	*args;

	args = malloc (sizeof(args));
	if (!args)
		return ;
	args->table = table;
	args->index = 0;
	while (args->index < table->philo_num)
	{
		// create thread.
		pthread_create(&th, NULL, &routine, (void *)args);
		//philosophers(table, index);
		args->index++;
	}
	// join thread
	pthread_join(th, NULL);
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
	if (argc == 6)
		optional = 1;
	table = init_table_and_philos(argv, optional);
	if (!table)
	{
		return (0);
	}
	philo(table);

	return (0);
}
