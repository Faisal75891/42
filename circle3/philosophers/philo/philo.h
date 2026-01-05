/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:30:58 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/05 19:17:10 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

// each philosopher can have 3 states
// 0=thinking, 1=eating, 2=sleeping
// all 0's=dead. maybe
typedef struct s_philo
{
	int	state[3];
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	num_of_times_eaten;
}	t_philo;

// The table has a list of all philosohphers
// number of forks and
// the forks that are in use
typedef struct s_table
{
	t_philo	**philos;
	int		philo_num;
	int		*forks;
	int		fork_num;
	int		num_of_times_to_eat;
}	t_table;

// free_philo
void	free_philos(t_philo **table);

// init_philo
t_philo	**init_philos(int philo_num, char **argv);
t_table	*init_table_and_philos(char **argv, int optional);
t_philo	*init_philo(char **argv);

// atoi
int		ft_atoi(char *s);
int		ft_strcmp(char *s1, char *s2);

// state
void	print_state(t_philo *philo, int index);
void	change_state(t_philo *philo, char *state);

// taking forks
int		take_fork(int *forks, int fork_num, int index);
void	put_fork(int *forks, int fork_num, int index);


#endif
