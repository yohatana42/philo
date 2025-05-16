/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:21:03 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/16 18:00:25 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	all_thread_join(t_table *table, pthread_t *monitor);

int	create_threads(t_table *table)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	if (pthread_create(&monitor, NULL, &routine_monitor, table) != 0)
	{
		print_message("failed: thread create\n", table);
		return (1);
	}
	while (i < table->num_of_philo)
	{
		if (pthread_create(&table->philos[i].thread, NULL, \
							&routine_philo, &table->philos[i]) != 0)
		{
			print_message("failed: thread create\n", table);
			return (1);
		}
		i++;
	}
	table->start = get_current_time();
	table->is_ready = true;
	return (all_thread_join(table, &monitor));
}

static int	all_thread_join(t_table *table, pthread_t *monitor)
{
	int	i;

	if (pthread_join(*monitor, NULL) != 0)
	{
		print_message("failed: thread join\n", table);
	}
	i = 0;
	while (i < table->num_of_philo)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
		{
			print_message("failed: thread join\n", table);
			return (1);
		}
		i++;
	}
	return (0);
}
