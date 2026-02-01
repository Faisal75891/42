/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:04:24 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/26 19:35:03 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_philo **philo)
{
	int	i;

	if (!philo)
		return ;
	i = 0;
	while (philo[i])
	{
		free(philo[i]);
		i++;
	}
	free (philo);
}

void	free_forks(pthread_mutex_t *fork_mutexes, int fork_num)
{
	int	i;

	if (!fork_mutexes || fork_num <= 0)
		return ;
	i = 0;
	while (i < fork_num)
	{
		pthread_mutex_destroy(&fork_mutexes[i]);
		i++;
	}
	free(fork_mutexes);
}

t_mutexes	*clean_up(t_mutexes *mutexes, int level, int fork_num)
{
	if (level >= 1)
		free_forks(mutexes->fork_mutexes, fork_num);
	if (level >= 2)
		pthread_mutex_destroy(&mutexes->last_eaten_mutex);
	if (level >= 3)
		pthread_mutex_destroy(&mutexes->num_of_times_eaten_mutex);
	if (level >= 4)
		pthread_mutex_destroy(&mutexes->printing_mutex);
	if (level >= 5)
		pthread_mutex_destroy(&mutexes->start_mutex);
	if (level >= 6)
		pthread_mutex_destroy(&mutexes->terminate_mutex);
	free(mutexes);
	return (NULL);
}

void	free_table(t_table *table)
{
	clean_up(table->mutexes, 6, table->fork_num);
	free_philos(table->philos);
	free(table);
}
