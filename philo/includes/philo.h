/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshiko <yoshiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:57:40 by yohatana          #+#    #+#             */
/*   Updated: 2025/04/17 22:52:46 by yoshiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct s_table   t_table;

typedef struct s_fork
{
    int fork_id;
    pthread_mutex_t fork;
}   t_fork;

typedef struct s_philo
{
    int     id;
    int     eat_count;
    bool    full;
    long    last_eat_time;
    pthread_t   thread_id;
    t_fork  *right_fork;
    t_fork  *left_fork;
    t_table *table;
}   t_philo;

typedef struct s_table
{
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep; 
    long    num_of_times_must_eat;
    long    start_time;
    long    end_time;
    pthread_t       *philos;
    pthread_mutex_t *forks;
}   t_table;

// validation
bool	validation_args(int argc, char **argv);

// create_struct_table
t_table *create_struct_table(char **argv, t_table *table);
void    free_table(t_table *table);

// utils
size_t	ft_strlen(const char *s);
int 	ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);

#endif
