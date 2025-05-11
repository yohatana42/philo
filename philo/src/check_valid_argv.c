/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:29:02 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/11 16:29:24 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_arg_content(char **argv);

int	check_valid_argv(char **argv)
{
	if (check_arg_content(argv))
		return (1);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
		return (write(2, "invalid num of philo\n", 22), 1);
	if (ft_atoi(argv[2]) < 60)
		return (write(2, "invalid time to die\n", 21), 1);
	if (ft_atoi(argv[3]) < 60)
		return (write(2, "invalid time to eat\n", 21), 1);
	if (ft_atoi(argv[4]) < 60)
		return (write(2, "invalid time to sleep\n", 23), 1);
	if (argv[5])
	{
		if (ft_atoi(argv[5]) < 0)
		{
			write(2, "invalid num of times each philo must eat\n", 42);
			return (1);
		}
	}
	return (0);
}

static int	check_arg_content(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(2, "invalid character\n", 19);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
