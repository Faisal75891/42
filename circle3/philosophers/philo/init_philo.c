/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:13:01 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/10 18:57:35 by fbaras           ###   ########.fr       */
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

int	*init_forks(int fork_num)
{
	int	*forks;
	int	i;

	forks = malloc (sizeof(int) * fork_num);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < fork_num)
	{
		forks[i] = 1;
		i++;
	}
	return (forks);
}

pthread_mutex_t	*init_mutexes(int fork_num)
{
	int				i;
	pthread_mutex_t	*fork_mutexes;

	fork_mutexes = malloc (sizeof(pthread_mutex_t) * fork_num);
	if (!fork_mutexes)
		return (NULL);
	i = 0;
	while (i < fork_num)
	{
		if (pthread_mutex_init(&fork_mutexes[i], NULL) != 0)
		{
			free(fork_mutexes);
			return (NULL);
		}
		i++;
	}
	return (fork_mutexes);
}

t_table	*init_table_and_philos(char **argv, int optional)
{
	t_table	*table;

	table = malloc (sizeof(t_table));
	if (!table)
		return (NULL);
	table->philos_num = ft_atoi(argv[1]);
	table->fork_num = ft_atoi(argv[1]);
	if (!optional)
		table->num_of_times_to_eat = 5;
	else
		table->num_of_times_to_eat = ft_atoi(argv[5]);
	table->philos = init_philos(table->philos_num, argv);
	if (!table->philos)
		return (NULL);
	table->forks = init_forks(table->fork_num);
	if (!table->forks)
	{
		free_philos(table->philos);
		free(table);
		return (NULL);
	}
	table->fork_mutexes = init_mutexes(table->fork_num);
	if (!table->fork_mutexes)
	{
		free_philos(table->philos);
		free(table->forks);
		free(table);
		return (NULL);
	}
	table->terminate = 0;
	return (table);
}

t_philo	**init_philos(int philos_num, char **argv)
{
	t_philo	**table;
	int		i;

	table = malloc(sizeof(t_philo *) * (philos_num + 1));
	if (!table)
		return (NULL);
	i = 0;
	while (i < philos_num)
	{
		table[i] = init_philo(argv, i);
		if (!table[i])
		{
			free_philos(table);
			return (NULL);
		}
		i++;
	}
	table[i] = NULL;
	return (table);
}
