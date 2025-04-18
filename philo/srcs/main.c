/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshiko <yoshiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:56:46 by yohatana          #+#    #+#             */
/*   Updated: 2025/04/16 22:25:47 by yoshiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	return_error(char *str);

/*
	memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
*/

/*
	 哲学者の数：
	 	哲学者の数とフォークの数。
	time_to_die (in millisecond):
		最後の食事またはシミュレーション開始からtime_to_dieミリ秒以内に食事を開始しなかった場合、その哲学者は死ぬ。
	time_to_eat (ミリ秒)： 
		哲学者が食事をするまでの時間。その間、2本のフォークを持つ必要がある。
	time_to_sleep （ミリ秒）： 
		哲学者が睡眠に費やす時間。
	number_of_times_each_philosopher_must_eat (オプション引数)： 
		すべての哲学者が すべての哲学者が少なくともnumber_of_times_each_philosopher_must_eat
		回以上食べた場合、シミュレーションは停止します。指定がない場合、哲学者が死亡した時点でシミュレーションは停止します。

*/
// まずは2人で
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_table	*table;

	table = NULL;
	// validation
	if (validation_args(argc, argv))
		return (return_error("invalid argument\n"));

	// create struct
	create_struct_table(argv, table);
	if (!table)
		return (return_error("failed create struct table\n"));

	// diner start
	// start_dinner(table);

	// clean up
	free_table(table);

	return (0);
}

static int	return_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}