/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:22:30 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/12 17:24:22 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_message(char *str, t_table *table)
{
	if (table)
	{
		//
		pthread_mutex_lock(&table->write_lock);
	}
	write(2, str, ft_strlen(str));
	if (table)
	{
		//
		pthread_mutex_unlock(&table->write_lock);
	}
}
