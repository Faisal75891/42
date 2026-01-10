/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:38:07 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/10 18:54:32 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// index: 0=thinking, 1=eating, 2=sleeping
void	change_state(t_philo *philo, char *state)
{
	if (ft_strcmp(state, "thinking") == 0)
	{
		//memset(philo->state, 0, 3);
		philo->state[0] = 1;
		philo->state[1] = 0;
		philo->state[2] = 0;
	}
	else if (ft_strcmp(state, "eating") == 0)
	{
		//memset(philo->state, 0, 3);
		philo->state[0] = 0;
		philo->state[1] = 1;
		philo->state[2] = 0;
	}
	else if (ft_strcmp(state, "sleeping") == 0)
	{
		philo->state[0] = 0;
		philo->state[1] = 0;
		philo->state[2] = 1;
	}
	else
		printf("bad state\n");
}

void	print_state(t_philo *philo)
{
	if (!philo)
		return ;
	if (philo->state[2] == 0 && philo->state[1] == 0 && philo->state[0] == 1)
		printf("%lu %d is thinking\n",time_stamp(), philo->id);
	else if (philo->state[2] == 0 && philo->state[1] == 1 && philo->state[0] == 0)
		printf("%lu %d is eating\n",time_stamp(), philo->id);
	else if (philo->state[2] == 1 && philo->state[1] == 0 && philo->state[0] == 0)
		printf("%lu %d is sleeping\n",time_stamp(), philo->id);
}
