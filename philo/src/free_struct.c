/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:25:18 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/18 19:53:47 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_struct(t_table *table)
{
	free_forks(table->forks);
	free_philos(table->philos);
	free(table->monitor);
}

void	free_forks(pthread_mutex_t **forks)
{
	int	i;

	i = 0;
	if (!forks)
		return ;
	while (forks[i])
	{
		free(forks[i]);
		i++;
	}
	free(forks);
}

void	free_philos(t_philo **philos)
{
	int	i;

	if (!philos)
		return ;
	i = 0;
	while (philos[i])
	{
		free(philos[i]);
		i++;
	}
	free(philos);
}
