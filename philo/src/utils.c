/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:22:30 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/20 14:26:23 by yohatana         ###   ########.fr       */
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

	pthread_mutex_lock(&philo->table->dead_lock);
	if (philo->table->monitor->is_someone_died == true)
	{
		pthread_mutex_unlock(&philo->table->dead_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->table->dead_lock);
	pthread_mutex_lock(write_lock);
	timestamp = get_current_time() - philo->table->start;
	printf("%zu %d %s\n", timestamp, philo->id, str);
	pthread_mutex_unlock(write_lock);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;
	int	str1_len;
	int	str2_len;

	i = 0;
	if (str1 == NULL)
		str1_len = 0;
	else
		str1_len = (int)ft_strlen(str1);
	if (str2 == NULL)
		str2_len = 0;
	else
		str2_len = (int)ft_strlen(str2);
	if (str1_len != str2_len)
		return (1);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}
