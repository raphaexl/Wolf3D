/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 01:37:04 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/27 11:27:39 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_place_sprites(t_sprite **s, t_map *m)
{
	int		p;
	int		i;
	int		j;

	i = 1;
	while (++i < m->h - 2)
	{
		j = 1;
		while (++j < m->w - 2)
		{
			if ((!m->tab[i][j]) && (!m->tab[i - 1][j]) && (!m->tab[i][j - 1])
					&& (!m->tab[i][j + 1]) && !(m->tab[i + 1][j]))
			{
				p = ft_randint(2, 100);
				if (p < 20)
				{
					ft_push_back_sprites(s, ft_create_sprites(ft_vector(i, j),\
								ft_randint(71, 119)));
				}
				i += ft_randint(1, 2);
				j += ft_randint(1, 2);
			}
		}
	}
}

void	ft_load_sprites(t_wolf *w)
{
	w->sprites = NULL;
	w->sprite_dist = (double *)malloc(256 * sizeof(double));
	w->sprite_order = (int *)malloc(256 * sizeof(int));
}

void	ft_init_variables2(t_wolf *w)
{
	w->me_arm = 0;
	w->wall_x = 0.0;
	w->tile_num = 0;
	w->ps = ft_point(0, 0);
	w->pd = ft_point(0, 0);
	w->inv_det = 0.0;
	w->tex_y = 0;
	w->temp = 0;
	w->tex_x = 0;
	w->sprite_screen = 0;
	ft_init_variables3(w);
}
