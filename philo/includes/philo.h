/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:08:30 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/18 20:51:57 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <sys/time.h>
# include <sys/types.h>
# include <stdbool.h>

# define PHILO_MAX 250

typedef struct s_table		t_table;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				count_eat;
	size_t			last_meal_time;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*meal_lock;
	bool			full;
	t_table			*table;
}	t_philo;

typedef struct s_monitor
{
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*table_lock;
	bool			is_someone_died;
	pthread_t		thread;
}	t_monitor;

typedef struct s_table
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_philo_must_eat;
	size_t			start;
	t_philo			**philos;
	t_monitor		*monitor;
	pthread_mutex_t	**forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	table_lock;
	bool			is_ready;
	pthread_mutex_t	dead_lock;
}	t_table;

// check_valid_argv
int		check_valid_argv(char **argv);

// init
int		init_table(char **argv, t_table *table);

// create_threads
int		create_threads(t_table *table);

// clean
void	clean_all(t_table *table);
// void	clean_fork(pthread_mutex_t *forks, t_table *table);

// struct
int		create_struct(t_table *table, char **argv);
// void	free_struct(t_table *table, \
// 	pthread_mutex_t **forks, \
// 	t_philo **philos, \
// 	t_monitor *monitor);
void	free_struct(t_table *table);
void	free_philos(t_philo **philos);
void	free_forks(pthread_mutex_t **forks);

// routine
void	*routine_monitor(void *table);
void	*routine_philo(void *arg);

// utils
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
void	print_message(char *str, t_table *table);
void	ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
void	print_log(pthread_mutex_t *write_lock, t_philo *philo, char *str);

#endif
