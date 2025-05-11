/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:08:30 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/11 15:30:06 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct	s_philo
{
	pthread_t		thread;
	int				id;
	int				count_eat;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	l_fork;
}	t_philo;

typedef struct	s_table
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_philo_must_eat;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
}	t_table;

// check_valid_argv
int	check_valid_argv(char **argv);

#endif PHILO_H
