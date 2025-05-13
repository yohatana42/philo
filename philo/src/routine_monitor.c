/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:46:07 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/13 16:17:52 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_dead(t_table *table);

void	*routine_monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
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
	printf("check_dead\n");
	while (i < table->num_of_philo)
	{
		if (table->philos[i].last_meal_time > (size_t)table->time_to_die)
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
