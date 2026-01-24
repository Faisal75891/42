/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:13:01 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/14 22:24:57 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// need to malloc:
// philo; init values
t_philo	*init_philo(char **argv, int id)
{
	t_philo	*philo;

	philo = malloc (sizeof(t_philo));
	if (!philo)
		return (NULL);
	memset(philo->state, 0, sizeof(philo->state));
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->num_of_times_eaten = 0;
	philo->id = id;
	gettimeofday(&philo->last_eaten, NULL);
	return (philo);
}

static void	quick_setup(t_table *table, char **argv, int optional)
{
	table->start_flag = FALSE;
	table->starting_time = time_stamp();
	table->philos_num = ft_atoi(argv[1]);
	table->fork_num = ft_atoi(argv[1]);
	if (!optional)
		table->num_of_times_to_eat = 5;
	else
		table->num_of_times_to_eat = ft_atoi(argv[5]);
	table->terminate_flag = FALSE;
}

// table->start_flag is in main.
t_table	*init_table_and_philos(char **argv, int optional)
{
	t_table	*table;

	table = malloc (sizeof(t_table));
	if (!table)
		return (NULL);
	quick_setup(table, argv, optional);
	table->philos = init_philos(table->philos_num, argv);
	if (!table->philos)
	{
		free(table);
		return (NULL);
	}
	table->mutexes = init_mutexes(table->fork_num);
	if (!table->mutexes)
	{
		free_philos(table->philos);
		free(table);
		return (NULL);
	}
	return (table);
}

t_philo	**init_philos(int philos_num, char **argv)
{
	t_philo	**philo;
	int		i;

	philo = malloc(sizeof(t_philo *) * (philos_num + 1));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < philos_num)
	{
		philo[i] = init_philo(argv, i);
		if (!philo[i])
		{
			free_philos(philo);
			return (NULL);
		}
		i++;
	}
	philo[i] = NULL;
	return (philo);
}
