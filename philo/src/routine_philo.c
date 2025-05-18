/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:06:26 by yohatana          #+#    #+#             */
/*   Updated: 2025/05/18 20:56:15 by yohatana         ###   ########.fr       */
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

	printf("this is philo\n");
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
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->r_fork);
	else
	{
		ft_usleep(1);
		pthread_mutex_lock(philo->l_fork);
	}
	print_log(philo->write_lock, philo, "has taken a fork");
	if (philo->table->num_of_philo == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		ft_usleep(philo->table->time_to_die);
		return ;
	}
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->l_fork);
	else
		pthread_mutex_lock(philo->r_fork);
	print_log(philo->write_lock, philo, "has taken a fork");
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
