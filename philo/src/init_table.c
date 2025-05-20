/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:35:43 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/20 10:54:54 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_forks(t_table *table);
static int	init_philos(t_table *table);
static int	init_monitor(t_table *table);

int	init_table(char **argv, t_table *table)
{
	printf("init table %p\n", table);
	(void)argv;
	table->is_ready = false;
	if (pthread_mutex_init(&table->write_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->table_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->dead_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->meal_lock, NULL) != 0)
		return (1);
	init_forks(table);
	init_philos(table);
	init_monitor(table);
	return (0);
}

static int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		if (pthread_mutex_init(table->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

static int	init_philos(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->num_of_philo)
	{
		table->philos[i]->id = i + 1;
		table->philos[i]->count_eat = 0;
		table->philos[i]->full = false;
		table->philos[i]->last_meal_time = 0;
		table->philos[i]->r_fork = table->forks[i];
		if (i == 0)
			table->philos[i]->l_fork = table->forks[table->num_of_philo - 1];
		else
			table->philos[i]->l_fork = table->forks[i - 1];
		table->philos[i]->write_lock = &table->write_lock;
		table->philos[i]->meal_lock = &table->meal_lock;
		table->philos[i]->table = table;
		i++;
	}
	return (0);
}

static int	init_monitor(t_table *table)
{
	table->monitor->write_lock = &table->write_lock;
	table->monitor->meal_lock = &table->meal_lock;
	table->monitor->dead_lock = &table->dead_lock;
	table->monitor->table_lock = &table->table_lock;
	table->monitor->is_someone_died = false;
	return (0);
}

/*
int	init_table(char **argv, t_table *table)
{
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];
	t_monitor		monitor;

	table->num_of_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->num_of_philo_must_eat = ft_atoi(argv[5]);
	else
		table->num_of_philo_must_eat = -1;
	table->is_ready = false;
	if (pthread_mutex_init(&table->write_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->table_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->dead_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->meal_lock, NULL) != 0)
		return (1);
	if (init_forks(forks, table))
		return (1);
	init_philos(philos, forks, table);
	init_monitor(&monitor, table);
	return (0);
}

static int	init_forks(pthread_mutex_t *forks, t_table *table)
{
	int	i;

	i = 0;
	table->forks = &forks;
	while (i < table->num_of_philo)
	{
		if (pthread_mutex_init(table->forks[i], NULL) != 0)
		{
			clean_all(table);
			return (1);
		}
		i++;
	}
	// table->forks = &forks;
	return (0);
}

static void	init_philos(t_philo *philos, \
						pthread_mutex_t *forks, \
						t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		philos[i].id = i + 1;
		philos[i].count_eat = 0;
		philos[i].last_meal_time = 0;
		philos[i].r_fork = &forks[i];
		if (i == 0)
			philos[i].l_fork = &forks[table->num_of_philo - 1];
		else
			philos[i].l_fork = &forks[i - 1];
		philos[i].write_lock = &table->write_lock;
		philos[i].meal_lock = &table->meal_lock;
		philos[i].full = false;
		philos[i].table = table;
		i++;
	}
	table->philos = &philos;
}

static void	init_monitor(t_monitor *monitor, t_table *table)
{
	monitor->write_lock = &table->write_lock;
	monitor->meal_lock = &table->meal_lock;
	monitor->dead_lock = &table->dead_lock;
	monitor->table_lock = &table->table_lock;
	monitor->is_someone_died = false;
	table->monitor = monitor;
}
*/
