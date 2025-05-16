/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:46:07 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/16 18:41:23 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_someone_dead(t_table *table);
static int	is_all_philo_full(t_table *table);

void	*routine_monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (table->is_ready != true)
		;
	while (1)
	{
		if (is_someone_dead(table) || is_all_philo_full(table))
		{
			table->dead_flg = true;
			pthread_mutex_lock(&table->meal_lock);
			pthread_mutex_lock(&table->dead_lock);
			break ;
		}
	}
	pthread_mutex_unlock(&table->meal_lock);
	pthread_mutex_unlock(&table->dead_lock);
	return (arg);
}

static int	is_someone_dead(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		pthread_mutex_lock(&table->meal_lock);
		if ((get_current_time() - table->start) - table->philos[i].last_meal_time \
			>= (size_t)table->time_to_die && table->philos[i].eating)
		{
			table->philos[i].dead_flg = true;
			table->dead_flg = true;
			print_log(&table->write_lock, &table->philos[i], "died");
			pthread_mutex_unlock(&table->meal_lock);
			return (1);
		}
		pthread_mutex_unlock(&table->meal_lock);
		i++;
	}
	return (0);
}

static int	is_all_philo_full(t_table *table)
{
	int	i;
	int	count_full;

	i = 0;
	count_full = 0;
	pthread_mutex_lock(&table->meal_lock);
	while (i < table->num_of_philo)
	{
		if (table->philos[i].full == true)
			count_full++;
		i++;
	}
	pthread_mutex_unlock(&table->meal_lock);
	if (count_full == table->num_of_philo)
		return (1);
	return (0);
}
