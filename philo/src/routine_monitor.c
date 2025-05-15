/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:46:07 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/15 15:03:49 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_dead(t_table *table);

void	*routine_monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	printf("table %p\n", table);
	printf("this is monitor\n");
	while (1)
	{
		printf("monitor loop\n");
		if (check_dead(table))
		{
			printf("who dead!\n");
			break ;
		}
	}
	return (arg);
}

// ここでセグフォしてる
// おそらく開始時刻とか設定してない＆last_meal_timeがNULL
static int	check_dead(t_table *table)
{
	int	i;

	i = 0;
	printf("monitor check_dead\n");
	printf("table %p\n", table);
	printf("table->num_of_philo %d\n", table->num_of_philo);
	while (i < table->num_of_philo)
	{
		printf("last meal %zu\n", table->philos[i].last_meal_time);
		if (table->start - table->philos[i].last_meal_time > (size_t)table->time_to_die)
		{
			table->philos[i].dead_flg = 1;
		}
		if (table->philos[i].dead_flg)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
