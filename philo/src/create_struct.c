/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:17:48 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/20 10:55:12 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	create_forks(t_table *table);
static int	create_monitor(t_table *table);
static int	create_philos(t_table *table);

int	create_struct(t_table *table, char **argv)
{
	// table = (t_table *)ft_calloc(sizeof(t_table), 1);
	// if (!table)
	// 	return (1);
	table->num_of_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->num_of_philo_must_eat = ft_atoi(argv[5]);
	else
		table->num_of_philo_must_eat = -1;
	if (create_forks(table))
		return (1);
	if (create_monitor(table))
	{
		free_struct(table);
		return (1);
	}
	if (create_philos(table))
	{
		free_struct(table);
		return (1);
	}
	return (0);
}

static int	create_forks(t_table *table)
{
	pthread_mutex_t	**fork_array;
	pthread_mutex_t	*fork;
	int				i;

	fork_array = (pthread_mutex_t **)ft_calloc(sizeof(pthread_mutex_t *), \
									table->num_of_philo + 1);
	if (!fork_array)
		return (1);
	i = 0;
	while (i < table->num_of_philo)
	{
		fork = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), 1);
		if (!fork)
		{
			free_forks(fork_array);
			return (1);
		}
		fork_array[i] = fork;
		i++;
	}
	fork_array[i] = NULL;
	table->forks = fork_array;
	return (0);
}

static int	create_philos(t_table *table)
{
	t_philo	**philos;
	t_philo	*philo;
	int		i;

	philos = (t_philo **)ft_calloc(sizeof(t_philo *), table->num_of_philo + 1);
	if (!philos)
		return (1);
	i = 0;
	while (i < table->num_of_philo)
	{
		philo = (t_philo *)ft_calloc(sizeof(t_philo), 1);
		if (!philo)
		{
			free_philos(philos);
			return (1);
		}
		philos[i] = philo;
		i++;
	}
	philos[i] = NULL;
	table->philos = philos;
	return (0);
}

static int	create_monitor(t_table *table)
{
	t_monitor	*monitor;

	monitor = ft_calloc(sizeof(t_monitor), 1);
	if (!monitor)
	{
		return (1);
	}
	table->monitor = monitor;
	return (0);
}
