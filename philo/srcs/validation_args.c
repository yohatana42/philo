/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshiko <yoshiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:06:09 by yoshiko           #+#    #+#             */
/*   Updated: 2025/04/17 23:14:29 by yoshiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	is_num(char **argv);

bool	validation_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (true);
	if (!is_num(argv))
        return (true);
    if (ft_atoi(argv[1]) < 1)
        return (true);
    if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
        return (true);
    if (argc == 6)
    {
        if (ft_atoi(argv[5]) < 1)
            return (true);
    }
    return (false);
}

static bool	is_num(char **argv)
{
	int	i;
	int	num;

	i = 1;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (num < 0)
			return (false);
        i++;
	}
	return (true);
}