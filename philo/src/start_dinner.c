/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:18:42 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/15 14:32:24 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	wait_all_threads(t_table *table);

void	start_dinner(t_table *table)
{
	(void)table;
	printf("start dinner\n");
	// すべてのスレッドを待つ
	wait_all_threads(table);
	table->start = get_current_time();
	// 開始時刻の設定
	// 死ぬか満足したら終わる
}

// table->table_lock
static int	wait_all_threads(t_table *table)
{
	(void)table;
	printf("wait all\n");
	return (0);
}
