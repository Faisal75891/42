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

// time difference of then until now
// returns time in ms
// long long	time_difference(struct timeval then)
// {
// 	struct timeval now;
	
// 	gettimeofday(&now, NULL);
// 	return (now.tv_sec - then.tv_sec) * 1000000 + now.tv_usec - then.tv_usec;
// }

long long	time_difference(struct timeval then)
{
    struct timeval now;
    long long seconds;
    long long microseconds;
    
    gettimeofday(&now, NULL);
    seconds = now.tv_sec - then.tv_sec;
    microseconds = now.tv_usec - then.tv_usec;
    
    if (microseconds < 0)
    {
        seconds--;
        microseconds += 1000000;
    }
    
    return (seconds * 1000 + microseconds / 1000);
}
unsigned long	time_stamp(void)
{
	struct timeval now;
	
	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000LL + (now.tv_usec / 1000LL));
}

// int	main(void)
// {
// 	struct timeval then;

// 	gettimeofday(&then, NULL);
// 	sleep(1);
// 	printf("%lld\n", time_difference(then));
// 	printf("%lu\n", time_stamp());
// }