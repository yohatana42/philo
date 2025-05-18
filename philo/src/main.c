/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:08:22 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/18 18:46:13 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_table			table;

	if (argc != 5 && argc != 6)
	{
		write(2, "invalid args count\n", 20);
		return (1);
	}
	if (check_valid_argv(argv))
		return (1);
	if (init_table(argv, &table))
	{
		write(2, "failed: init table data\n", 20);
		clean_all(&table);
		return (1);
	}
	// create_threads(&table);
	// clean_all(&table);
	return (0);
}
