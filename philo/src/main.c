/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:08:22 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/12 17:36:19 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

// まずは一人で死ぬ哲学者を作ろう
// 二人で死ぬ哲学者
// 二人で生きる哲学者
// 三人で生きる哲学者、死ぬ哲学者
int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
	{
		write(2, "invalid args count\n", 20);
		return (1);
	}
	if (check_valid_argv(argv))
		return (1);
	if (init_table(argc, argv, &table))
	{
		write(2, "failed: init table data\n", 20);
		return (1);
	}
	create_threads(&table);
	// wait threads
	// start dinner
	clean_all(&table);
	return (0);
}
