/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:22:30 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/13 15:50:20 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_message(char *str, t_table *table)
{
	if (table)
		pthread_mutex_lock(&table->write_lock);
	write(2, str, ft_strlen(str));
	if (table)
		pthread_mutex_unlock(&table->write_lock);
}

void	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		write(2, "failed: gettimeofday\n", 22);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_log(pthread_mutex_t *write_lock, t_philo *philo, char *str)
{
	size_t	timestamp;

	pthread_mutex_lock(write_lock);
	timestamp = get_current_time() - philo->table->start;
	printf("%zu %d %s\n", timestamp, philo->id, str);
	pthread_mutex_unlock(write_lock);
}

/*
	時間を取得するやつ
	現在時刻（スタート）ー＞食事＆監視ー＞死ぬぜ！（現在時刻2）ー＞書き込むぜ！（現在時刻-現在時刻2）
														↑この瞬間はどうしても死んだ瞬間より遅れる
	こんな感じで使いたい

	table->start = スレッドがすべて作成された確認が取れた時間、モニターが仕事を開始する
	table->end = 哲学者が一人死ぬか、全員が規定回数まで食事した時間
	philo->left_meal_time = 食事を開始した時間

	死んでから何秒以内に書き込んだか確認する方法
	・死ぬまでの時間
	こいつが書き込まれた時間と、引数に設定した時間がどのくらいずれてるか
	これなんでそんなに差が出る可能性があるんだ・・・・・？モニターが動く回数は環境依存だと思ってたけどそうでもない？
	大幅に遅れる・早く出力されるのは時間の計算方法に問題があるとか？

	スレッドがすべて作成されるまで、シミュレーションをミューテックスでロックする必要がありそう
	最初からロックしておくー＞スレッドが揃うー＞ロックを解除、モニター起動、シミュレーション開始ー＞シミュレーションが終了する
	ー＞ミューテックスそのものが掃除される（ロックする必要はない）
*/
