/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:13:01 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/05 17:49:30 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// need to malloc:
// philo; init values
t_philo	*init_philo(char **argv)
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
	return (philo);
}

// fork's array; sets all to 1
// creates philo table.
t_table	*init_table_and_philos(char **argv, int optional)
{
	t_table	*table;

	table = malloc (sizeof(t_table));
	if (!table)
		return (NULL);
	table->philo_num = ft_atoi(argv[1]);
	table->fork_num = ft_atoi(argv[1]);
	table->philos = init_philos(table->philo_num, argv);
	if (!table->philos)
		return (NULL);
	table->forks = malloc (sizeof(int) * table->fork_num);
	if (!table->forks)
	{
		free_philos(table->philos);
		return (NULL);
	}
	memset(table->forks, 1, table->fork_num);
	if (!argv[5] || !optional)
		table->num_of_times_to_eat = 5;
	else
		table->num_of_times_to_eat = ft_atoi(argv[5]);
	return (table);
}

t_philo	**init_philos(int philo_num, char **argv)
{
	t_philo	**table;
	int		i;

	table = malloc(sizeof(t_philo *) * philo_num);
	if (!table)
		return (NULL);
	i = 0;
	while (i < philo_num)
	{
		table[i] = init_philo(argv);
		if (!table[i])
		{
			free_philos(table);
			return (NULL);
		}
		i++;
	}
	return (table);
}
