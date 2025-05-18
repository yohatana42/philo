/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:56:49 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/18 19:08:25 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	clean_fork(t_table *table);

void	clean_all(t_table *table)
{
	if (pthread_mutex_destroy(&table->meal_lock) != 0)
		write(2, "failed: mutex destroy meal_lock\n", 33);
	if (pthread_mutex_destroy(&table->dead_lock) != 0)
		write(2, "failed: mutex destroy dead_lock\n", 33);
	if (pthread_mutex_destroy(&table->table_lock) != 0)
		write(2, "failed: mutex destroy table_lock\n", 34);
	if (pthread_mutex_destroy(&table->write_lock) != 0)
		write(2, "failed: mutex destroy write_lock\n", 34);
	clean_fork(table);
}

static void	clean_fork(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		if (pthread_mutex_destroy(table->forks[i]) != 0)
			write(2, "failed: mutex destroy fork\n", 28);
		i++;
	}
}
