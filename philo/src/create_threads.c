/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:21:03 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/20 10:02:14 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	all_thread_join(t_table *table, t_monitor *monitor);

int	create_threads(t_table *table)
{
	int			i;

	i = 0;
	if (pthread_create(&table->monitor->thread, \
						NULL, &routine_monitor, table) != 0)
	{
		print_message("failed: thread create\n", table);
		return (1);
	}
	while (i < table->num_of_philo)
	{
		if (pthread_create(&table->philos[i]->thread, NULL, \
							&routine_philo, table->philos[i]) != 0)
		{
			print_message("failed: thread create\n", table);
			return (1);
		}
		i++;
	}
	table->start = get_current_time();
	table->is_ready = true;
	return (all_thread_join(table, table->monitor));
}

static int	all_thread_join(t_table *table, t_monitor *monitor)
{
	int	i;

	if (pthread_join(monitor->thread, NULL) != 0)
	{
		print_message("failed: thread join\n", table);
	}
	i = 0;
	while (i < table->num_of_philo)
	{
		if (pthread_join(table->philos[i]->thread, NULL) != 0)
		{
			print_message("failed: thread join\n", table);
			return (1);
		}
		i++;
	}
	return (0);
}
