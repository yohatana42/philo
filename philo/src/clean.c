/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:56:49 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/18 11:56:30 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clean_all(t_table *table)
{
	if (pthread_mutex_destroy(&table->meal_lock) != 0)
		write(2, "failed: mutex destroy\n", 23);
	if (pthread_mutex_destroy(&table->dead_lock) != 0)
		write(2, "failed: mutex destroy\n", 23);
	if (pthread_mutex_destroy(&table->table_lock) != 0)
		write(2, "failed: mutex destroy\n", 23);
	if (pthread_mutex_destroy(&table->write_lock) != 0)
		write(2, "failed: mutex destroy\n", 23);
	clean_fork(table->forks, table);
}

void	clean_fork(pthread_mutex_t *forks, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		if (pthread_mutex_destroy(&forks[i]) != 0)
			write(2, "failed: mutex destroy\n", 23);
		i++;
	}
}
