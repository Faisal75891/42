/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:26:29 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/05 19:30:30 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// the basic idea before starting with threads.
void	philosophers(t_table *table, int i)
{
	struct timeval stop;
	struct timeval start;

	while (table->num_of_times_to_eat > table->philos[i]->num_of_times_eaten)
	{
		gettimeofday(&start, NULL);

		change_state(table->philos[i], "thinking");
		print_state(table->philos[i], i);

		if (table->philos[i]->time_to_eat > 0)
		{
			// take fork mutex lock
			if (!take_fork(table->forks, table->fork_num, i))
			{
				gettimeofday(&stop, NULL);
				if (table->philos[i]->time_to_eat > (stop.tv_usec - start.tv_usec))
				{
					printf("philosopher %d died\n", i);
					// detach all threads if philo dies
					return ;
				}
				change_state(table->philos[i], "eating");
				print_state(table->philos[i], i);
				usleep(table->philos[i]->time_to_eat);
				// put fork. mutex unlock
				put_fork(table->forks, table->fork_num, i);
				
				gettimeofday(&start, NULL);
			}
			if (table->philos[i]->time_to_sleep > 0)
			{
				change_state(table->philos[i], "sleeping");
				print_state(table->philos[i], i);
				usleep(table->philos[i]->time_to_sleep);
			}
			change_state(table->philos[i], "thinking");
			print_state(table->philos[i], i);
		}
		printf("\n");
		table->philos[i]->num_of_times_eaten++;
	}
	printf("done eating\n");
}

void	philo(t_table *table)
{
	int	index;

	index = 0;
	while (table->philos[index])
	{
		// create thread.
		philosophers(table, index);
		index++;
	}
	// join thread
	
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

	philo(table);

	return (0);
}
