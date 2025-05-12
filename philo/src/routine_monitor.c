/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:46:07 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/12 17:52:33 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine_monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	printf("this is monitor\n");
	// while (1)
	// {

	// }
	return (arg);
}
