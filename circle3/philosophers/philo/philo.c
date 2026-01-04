/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:26:29 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/04 21:28:07 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// getting the basic idea before starting with threads.
void	philosophers(t_table *table)
{
	int	i;
	int	num_of_times_eaten;

	i = 0;
	num_of_times_eaten = 0;
	while (table->philos[i]
		&& num_of_times_eaten < table->philos[i]->num_of_times_to_eat)
	{
		if (table->philos[i]->time_to_eat > 0)
		{
			if (table->forks[i % table->fork_num] == 1
				&& table->forks[i + 1% table->fork_num] == 1)
			{
				table->forks[i % table->fork_num] = 0;
				table->forks[(i + 1) % table->fork_num] = 0;
			}
			else
				printf("forks still in use\n");
			printf("philosopher %d is eating\n", i);
			usleep(table->philos[i]->time_to_eat);
			table->forks[i % table->fork_num] = 1;
			table->forks[(i + 1) % table->fork_num] = 1;
		}
		if (table->philos[i]->time_to_sleep > 0)
		{
			printf("philosopher %d is sleeping\n", i);
			usleep(table->philos[i]->time_to_sleep);
		}
		else
			printf("philosopher %d is thinking\n", i);
		num_of_times_eaten++;
		i++;
	}
}

// not using threads yet...
int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc != 5)
	{
		printf("USAGE: ./philo number_of_philosophers time_to_die time_to_eat\
			time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	table = init_table_and_philos(argv);
	philosophers(table);
	return (0);
}
