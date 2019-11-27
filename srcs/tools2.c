/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:42:49 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/25 02:59:21 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

t_point		ft_point(int x, int y)
{
	t_point		p;

	p.x = x;
	p.y = y;
	return (p);
}

t_vect2d	ft_vector(double x, double y)
{
	t_vect2d	p;

	p.x = x;
	p.y = y;
	return (p);
}

double		ft_random(void)
{
	static int	initialized = 0;

	if (!initialized)
	{
		initialized = 1;
		srand(time(NULL));
	}
	return ((double)rand() / ((double)RAND_MAX));
}

int			ft_randint(int min, int max)
{
	static int	initialized = 0;

	if (!initialized)
	{
		initialized = 1;
		srand(time(NULL));
	}
	return ((rand() % (max - min)) + min);
}

void		ft_free_sprites(t_sprite **s)
{
	t_sprite	*p;

	p = *s;
	while (p)
	{
		*s = (*s)->next;
		free(p);
		p = *s;
	}
}
