/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:26:29 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/14 23:09:41 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_threads(t_table *table, pthread_t *th, pthread_t *monitor)
{
	(void)th;
	(void)table;
	if (pthread_join(*monitor, NULL) != 0)
	{
		printf("joined threads.\n");
		return ;
	}
}

// calls ¨create_philo¨ function
// and ¨monitor_philos¨ function
static void	start_and_join_threads(t_thread_args *args, t_table *table,
	pthread_t *th, pthread_t *monitor)
{
	int	i;

	i = 0;
	while (i < table->philos_num)
	{
		args[i].table = table;
		args[i].index = i;
		args[i].threads = th;
		if (pthread_create(&th[i], NULL, &create_philo, (void *)&args[i]) != 0)
		{
			write(2, "couldn't start thread\n", 23);
			return ;
		}
		i++;
	}
	args[i].table = table;
	args[i].index = i;
	args[i].threads = th;
	if (pthread_create(monitor, NULL, &monitor_philos, (void *)&args[i]) != 0)
		return ;
	set_start_flag(table, TRUE);
	wait_threads(table, th, monitor);
}

// mallocs threads
// mallocs args which will hold all values.
// calls start and join threads() 
void	philo(t_table *table)
{
	pthread_t		*th;
	pthread_t		*monitor;
	t_thread_args	*args;

	th = malloc (sizeof(pthread_t) * table->philos_num);
	if (!th)
		return ;
	args = malloc (sizeof(t_thread_args) * (table->philos_num + 1));
	if (!args)
	{
		free(th);
		return ;
	}
	monitor = malloc (sizeof(pthread_t));
	if (!monitor)
	{
		free(th);
		free(args);
		return ;
	}
	start_and_join_threads(args, table, th, monitor);
	free(th);
	free(monitor);
	free(args);
}

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
		return (1);
	}
	philo(table);
	free_table(table);
	return (0);
}
