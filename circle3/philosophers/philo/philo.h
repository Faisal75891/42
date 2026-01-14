/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:30:58 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/14 18:27:31 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

// each philosopher can have 3 states
// 0=thinking, 1=eating, 2=sleeping
// all 0's=dead. maybe
typedef struct s_philo
{
	int				state[3];
	int				id;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				num_of_times_eaten;
	struct timeval	last_eaten;
}	t_philo;

// The table has a list of all philosohphers
// number of forks and
// the forks that are in use
typedef struct s_table
{
	t_philo			**philos;
	int				philos_num;
	int				*forks;
	pthread_mutex_t	*fork_mutexes;
	int				fork_num;
	int				num_of_times_to_eat;
	int				terminate;
}	t_table;

typedef struct s_thread_args
{
	t_table		*table;
	int			index;
	pthread_t	*threads;
}	t_thread_args;

// free_philo
void			free_philos(t_philo **table);

// init_philo
t_philo			**init_philos(int philos_num, char **argv);
t_table			*init_table_and_philos(char **argv, int optional);
t_philo			*init_philo(char **argv, int id);
int				*init_forks(int fork_num);
pthread_mutex_t	*init_mutexes(int fork_num);

// utils
int				ft_atoi(char *s);
int				ft_strcmp(char *s1, char *s2);

// states
void			print_state(t_philo *philo);
void			change_state(t_philo *philo, char *state);

// taking forks
void			put_fork(int *forks, int fork_num, int index,
					pthread_mutex_t *fork_mutexes);
int				take_fork(int *forks, int fork_num, int index,
					pthread_mutex_t *fork_mutexes);

// actions
int				philo_eat(t_philo *philo, int *forks, int fork_num,
					pthread_mutex_t *fork_mutexes);
void			philo_sleep(t_philo *philo);
void			philo_die(int i);

// time
unsigned long	time_stamp(void);
long long		time_difference(struct timeval then);

// routines
void			*create_philo(void *args);
void			*monitor_philos(void *args);

#endif
