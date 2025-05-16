/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:35:43 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/16 17:02:01 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_forks(pthread_mutex_t *forks, t_table *table);
static void	init_philos(t_philo *philos, \
						pthread_mutex_t *forks, \
						t_table *table);

int	init_table(int argc, char **argv, t_table *table)
{
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	(void)argc;
	table->num_of_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->num_of_philo_must_eat = ft_atoi(argv[5]);
	else
		table->num_of_philo_must_eat = -1;
	table->dead_flg = false;
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
	{
		clean_all(table);
		return (1);
	}
	init_philos(philos, forks, table);
	return (0);
}

static int	init_forks(pthread_mutex_t *forks, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			clean_all(table);
			return (1);
		}
		i++;
	}
	table->forks = forks;
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
		philos[i].dead_flg = false;
		philos[i].full = false;
		philos[i].table = table;
		i++;
	}
	table->philos = philos;
}
