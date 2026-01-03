/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:04:24 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/03 22:05:33 by fbaras           ###   ########.fr       */
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
