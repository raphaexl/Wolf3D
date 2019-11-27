/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:58:25 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/26 14:04:52 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		ft_sprite_sort(int *order, double *dist, int n)
{
	int		size;
	int		swapped;
	t_point	p;

	size = n;
	swapped = 0;
	while (size > 1 || swapped)
	{
		size = (size * 10) / 13;
		if (size == 9 || size == 10)
			size = 11;
		if (size < 1)
			size = 1;
		swapped = 0;
		p.x = -1;
		while (++p.x < n - size)
		{
			p.y = p.x + size;
			if ((dist[p.x] < dist[p.y]) && (swapped = 1))
			{
				ft_swap(&dist[p.x], &dist[p.y], sizeof(double));
				ft_swap(&order[p.x], &order[p.y], sizeof(int));
			}
		}
	}
}

void		ft_wolf_sprite1(t_wolf *w)
{
	w->sprite_screen = (int)((w->w / 2) * (1 + w->sprite_trans.x /
				w->sprite_trans.y));
	w->sprite_size.y = abs((int)(w->h / w->sprite_trans.y));
	w->sp_start.y = -w->sprite_size.y / 2 + w->h / 2;
	w->sp_start.y = (w->sp_start.y < 0) ? 0 : w->sp_start.y;
	w->sp_end.y = w->sprite_size.y / 2 + w->h / 2;
	w->sp_end.y = w->sp_end.y >= w->h ? w->h - 1 : w->sp_end.y;
	w->sprite_size.x = abs((int)(w->h / w->sprite_trans.y));
	w->sp_start.x = -w->sprite_size.x / 2 + w->sprite_screen;
	w->sp_start.x = (w->sp_start.x < 0) ? 0 : w->sp_start.x;
	w->sp_end.x = w->sprite_size.x / 2 + w->sprite_screen;
	w->sp_end.x = w->sp_end.x >= w->w ? w->w - 1 : w->sp_end.x;
	w->temp = (w->sprite_size.y << 7) - (w->h << 7);
}

void		ft_wolf_sprite2(t_wolf *w, int texture)
{
	int		j;
	int		k;
	int		d;

	k = w->sp_start.x - 1;
	while (++k < w->sp_end.x)
	{
		w->tex_x = (int)((((k - (-w->sprite_size.x / 2 + w->sprite_screen))
						<< 8) * T_W / w->sprite_size.x) >> 8);
		if (k > 0 && k < w->w && w->sprite_trans.y < w->z_buffer[k])
		{
			j = w->sp_start.y - 1;
			while (++j < w->sp_end.y)
			{
				d = w->temp + (j << 8);
				w->tex_y = ((d * T_H / w->sprite_size.y) >> 8);
				w->color = w->tex2[texture].pixels[T_W * w->tex_y +
						w->tex_x];
				if ((w->color & 0x00FFFFFF) != TRANS_PARENCY)
					w->pixels[j * w->w + k] = w->color;
			}
		}
	}
}

void		ft_wolf_sprite_1(t_wolf *w)
{
	int			i;
	t_sprite	*p;

	i = -1;
	p = w->sprites;
	while (p && (++i < w->nb_sprites))
	{
		w->sprite_order[i] = i;
		w->sprite_dist[i] = (w->player.x - p->x) * (w->player.x - p->x) +
			(w->player.y - p->y) * (w->player.y - p->y);
		p = p->next;
	}
	ft_sprite_sort(w->sprite_order, w->sprite_dist, w->nb_sprites);
	ft_wolf_sprite_2(w);
}

void		ft_wolf_sprite_2(t_wolf *w)
{
	int			i;
	t_sprite	*p;

	i = -1;
	p = w->sprites;
	while (p && ++i < w->nb_sprites)
	{
		p = ft_sprites(w->sprites, w->sprite_order[i]);
		w->sprite_pos.x = p->x - w->player.x;
		w->sprite_pos.y = p->y - w->player.y;
		w->inv_det = 1.0 / (w->cam_plane.x * w->dir.y - w->dir.x *
				w->cam_plane.y);
		w->sprite_trans.x = w->inv_det * (w->dir.y * w->sprite_pos.x -
				w->dir.x * w->sprite_pos.y);
		w->sprite_trans.y = w->inv_det * (-w->cam_plane.y * w->sprite_pos.x
				+ w->cam_plane.x * w->sprite_pos.y);
		ft_wolf_sprite1(w);
		if (w->sprite_trans.y > 0)
			ft_wolf_sprite2(w, p->texture);
	}
}
