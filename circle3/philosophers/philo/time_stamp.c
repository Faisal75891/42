/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stamp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:35:46 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/14 22:15:50 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_difference(struct timeval last_time)
{
	struct timeval	now;
	long long		diff;

	gettimeofday(&now, NULL);
	diff = (now.tv_sec - last_time.tv_sec) * 1000;
	diff += (now.tv_usec - last_time.tv_usec) / 1000;
	return (diff);
}

unsigned long	time_stamp(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000LL + (now.tv_usec / 1000LL));
}

void	ft_usleep(unsigned long ms)
{
	unsigned long	start;

	start = time_stamp();
	while (time_stamp() - start < ms)
		usleep(500);
}
