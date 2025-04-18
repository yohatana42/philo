/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct_table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshiko <yoshiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:02:40 by yoshiko           #+#    #+#             */
/*   Updated: 2025/04/16 22:13:59 by yoshiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_table *create_struct_table(char **argv, t_table *table)
{
    (void)argv;

    table = (t_table *)ft_calloc(sizeof(t_table), 1);
    if (!table)
        return (NULL);
    // table->philos = create_struct_philos(argv);
    // table->forks = create_struct_forks(argv);

    return (table);
}

void    free_table(t_table *table)
{
    if (!table)
        return ;
    // free_philos(table->philos);
    // free_forks(table->forks);
    free(table);
}