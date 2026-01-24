/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 22:22:41 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/24 22:22:41 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*init_fork_mutex(int fork_num)
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
			while (--i >= 0)
				pthread_mutex_destroy(&fork_mutexes[i]);
			free(fork_mutexes);
			return (NULL);
		}
		i++;
	}
	return (fork_mutexes);
}

// need to norminette
t_mutexes	*init_mutexes(int fork_num)
{
	t_mutexes	*mutexes;

	mutexes = malloc (sizeof(t_mutexes));
	if (!mutexes)
		return (NULL);
	mutexes->fork_mutexes = init_fork_mutex(fork_num);
	if (!mutexes->fork_mutexes)
		return (NULL);
	if (pthread_mutex_init(&mutexes->last_eaten_mutex, NULL) != 0)
		return (clean_up(mutexes, 1, fork_num));
	if (pthread_mutex_init(&mutexes->num_of_times_eaten_mutex, NULL) != 0)
		return (clean_up(mutexes, 2, fork_num));
	if (pthread_mutex_init(&mutexes->printing_mutex, NULL) != 0)
		return (clean_up(mutexes, 3, fork_num));
	if (pthread_mutex_init(&mutexes->start_mutex, NULL) != 0)
		return (clean_up(mutexes, 4, fork_num));
	if (pthread_mutex_init(&mutexes->terminate_mutex, NULL) != 0)
		return (clean_up(mutexes, 5, fork_num));
	if (pthread_mutex_init(&mutexes->state_mutex, NULL) != 0)
		return (clean_up(mutexes, 6, fork_num));
	return (mutexes);
}
