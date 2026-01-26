/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:30:58 by fbaras            #+#    #+#             */
/*   Updated: 2026/01/14 22:51:35 by fbaras           ###   ########.fr       */
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
// philo data
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

// mutex data
typedef struct s_mutexes
{
	pthread_mutex_t	*fork_mutexes;
	pthread_mutex_t	num_of_times_eaten_mutex;
	pthread_mutex_t	terminate_mutex;
	pthread_mutex_t	last_eaten_mutex;
	pthread_mutex_t	printing_mutex;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	state_mutex;
}	t_mutexes;

// table data
typedef struct s_table
{
	t_philo			**philos;
	int				philos_num;
	int				fork_num;
	int				num_of_times_to_eat;
	int				terminate_flag;
	int				start_flag;
	unsigned long	starting_time;
	t_mutexes		*mutexes;
}	t_table;

typedef struct s_thread_args
{
	t_table		*table;
	int			index;
	pthread_t	*threads;
}	t_thread_args;

// free_philo
void			free_philos(t_philo **table);
void			free_forks(pthread_mutex_t *fork_mutexes, int fork_num);
t_mutexes		*clean_up(t_mutexes *mutexes, int level, int fork_num);
void			free_table(t_table *table);

// init_philo
t_philo			**init_philos(int philos_num, char **argv);
t_table			*init_table_and_philos(char **argv, int optional);
t_philo			*init_philo(char **argv, int id);
int				*init_forks(int fork_num);
pthread_mutex_t	*init_fork_mutex(int fork_num);
t_mutexes		*init_mutexes(int fork_num);

// utils
int				ft_atoi(char *s);
int				ft_strcmp(char *s1, char *s2);

// shared state helpers
int				get_terminate_flag(t_table *table);
void			set_terminate_flag(t_table *table, int value);
void			set_last_eaten_now(t_table *table, int index);
struct timeval	get_last_eaten(t_table *table, int index);
int				get_num_times_eaten(t_table *table, int index);
void			increment_num_times_eaten(t_table *table, int index);
int				get_state(t_table *table, int i);
int				finished_eating(t_table *table, int i);


// states
void			print_state(t_table *table, int i);
void			change_state(t_table *table, int i, char *state);

// taking forks
void			put_fork(t_table *table, int index);
int				take_fork(t_table *table, int index);

// actions
int				philo_eat(t_table *table, int i);
void			philo_sleep(t_table *table, int i);
void			philo_die(t_table *table, int i);

// time
unsigned long	time_stamp(void);
long long		time_difference(struct timeval then);

// routines
void			*create_philo(void *args);
void			*monitor_philos(void *args);

#endif
