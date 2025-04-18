/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshiko <yoshiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:09:34 by yohatana          #+#    #+#             */
/*   Updated: 2025/04/16 22:15:23 by yoshiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_bzero(void *s, size_t n);
static void	*ft_memset(void *b, int c, size_t len);

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if ((count != 0 && SIZE_MAX / count < size)
		|| (size != 0 && SIZE_MAX / size < count))
		return (NULL);
	if (count == 0 || size == 0)
	{
		result = malloc(1);
		if (result == NULL)
			return (NULL);
		return (result);
	}
	result = malloc(size * count);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size * count);
	return (result);
}

static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*p;

	a = c;
	i = 0;
	p = (unsigned char *)b;
	while (i < len)
	{
		*p = a;
		p++;
		i++;
	}
	return (b);
}