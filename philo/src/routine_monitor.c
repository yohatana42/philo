/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:46:07 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/12 18:16:14 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine_monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	printf("this is monitor\n");
	// philoのデッドフラグを確認していく
	// while (1)
	// {

	// }
	return (arg);
}
