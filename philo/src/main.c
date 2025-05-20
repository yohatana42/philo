/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:08:22 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/20 12:38:11 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_table			*table;

	table = (t_table *)ft_calloc(sizeof(t_table), 1);
	if (!table)
		return (write(2, "failed: create struct\n", 23), 1);
	if (check_valid_argv(argc, argv))
		return (1);
	if (create_struct(table, argv))
	{
		free_struct(table);
		write(2, "failed: create struct\n", 23);
		return (1);
	}
	if (init_table(argv, table))
	{
		write(2, "failed: init table data\n", 20);
		clean_all(table);
		free_struct(table);
		return (1);
	}
	create_threads(table);
	clean_all(table);
	free_struct(table);
	return (0);
}
