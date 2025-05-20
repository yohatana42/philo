/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:06:26 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/20 10:20:51 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	eat(t_philo *philo);
static void	sleep_philo(t_philo *philo);
static void	think(t_philo *philo);
static int	check_dead(t_philo *philo);

void	*routine_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->table->is_ready != true)
		;
	while (!check_dead(philo))
	{
		eat(philo);
		sleep_philo(philo);
		think(philo);
	}
	return (arg);
}

static void	eat(t_philo *philo)
{
	if (check_dead(philo))
		return ;
	take_first_fork(philo);
	if (philo->table->num_of_philo == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		ft_usleep(philo->table->time_to_die);
		return ;
	}
	take_second_fork(philo);
	print_log(philo->write_lock, philo, "is eating");
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->last_meal_time = get_current_time() - philo->table->start;
	philo->count_eat = philo->count_eat + 1;
	if (philo->count_eat == philo->table->num_of_philo_must_eat)
		philo->full = true;
	pthread_mutex_unlock(&philo->table->meal_lock);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

static int	check_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->dead_lock);
	if (philo->table->monitor->is_someone_died == true)
	{
		pthread_mutex_unlock(&philo->table->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->dead_lock);
	return (0);
}

static void	sleep_philo(t_philo *philo)
{
	if (!check_dead(philo))
	{
		print_log(philo->write_lock, philo, "is sleeping");
		ft_usleep(philo->table->time_to_sleep);
	}
}

static void	think(t_philo *philo)
{
	if (!check_dead(philo))
	{
		print_log(philo->write_lock, philo, "is thinking");
	}
}
