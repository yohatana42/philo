/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:56:49 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/12 17:28:51 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	typedef struct	s_philo
{
	pthread_t		thread;
	int				id;
	int				count_eat;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	int				dead_flg;
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
*/
void	clean_all(t_table *table)
{
	if (pthread_mutex_destroy(&table->write_lock) != 0)
		print_message("failed: mutex destroy\n", NULL);
	clean_fork(table->forks, table);
}

void	clean_fork(pthread_mutex_t *forks, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		if (pthread_mutex_destroy(&forks[i]) != 0)
			print_message("failed: mutex destroy\n", NULL);
		i++;
	}
}

// void	clean_philos(t_philo *philos)
// {

// }
