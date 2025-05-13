/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:06:26 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/13 16:10:44 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	eat(t_philo *philo);
int			check_dead(t_philo *philo);

void	*routine_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("id: %d this is philo\n", philo->id);
	while (!check_dead(philo))
	{
		eat(philo);
		// think();
		// sleep_philo();
	}
	return (arg);
}

static void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->r_fork);
	else
		pthread_mutex_lock(philo->l_fork);
	print_log(philo->write_lock, philo, "has taken a fork");
	if (philo->table->num_of_philo == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->l_fork);
	else
		pthread_mutex_lock(philo->r_fork);
	print_log(philo->write_lock, philo, "has taken a fork");
	print_log(philo->write_lock, philo, "is eating");
	philo->last_meal_time = get_current_time() - philo->table->start;
	ft_usleep(philo->table->time_to_eat);
	philo->count_eat = philo->count_eat + 1;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

int	check_dead(t_philo *philo)
{
	if (philo->dead_flg)
		return (1);
	return (0);
}


// static void	sleep_philo()
// {
// 	// 指定した時間寝る
// }
