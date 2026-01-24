/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:04:24 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/22 19:20:11 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_philo **table)
{
	int	i;

	if (!table)
		return ;
	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free (table);
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

