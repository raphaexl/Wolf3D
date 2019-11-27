/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:58:34 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/26 10:58:38 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_wolf_type1(t_wolf *w)
{
	ft_get_wolfcolor(&w->map, w->map_pos.x, w->map_pos.y, &w->color);
	if (w->side == 1)
		w->color = (w->color >> 1) & 8355711;
	ft_sdl_draw_line(w->pixels, w->ps, w->pd, w->color);
}

void	ft_wolf_type2(t_wolf *w)
{
	t_point p;

	w->tile_p.x = SET((int)(w->wall_x * (double)T_W), 0, T_W - 1);
	if (!w->side && w->ray_dir.x > 0)
		w->tile_p.x = T_W - w->tile_p.x - 1;
	if (w->side == 1 && w->ray_dir.y < 0)
		w->tile_p.x = T_W - w->tile_p.x - 1;
	p.y = w->ps.y - 1;
	w->tile_num = SET(w->map.tab[w->map_pos.x][w->map_pos.y] - 1, 0, 60);
	p.x = w->x;
	while (++p.y <= w->pd.y)
	{
		w->d = (p.y << 8) - (w->h << 7) + (w->line_height << 7);
		w->tile_p.y = SET(((w->d * T_H) / w->line_height) >> 8, 0, T_W - 1);
		if (w->type == 1)
			w->color = w->tex1[w->tile_num].pixels[w->tile_p.y * T_W +
				w->tile_p.x];
		else
			w->color = w->tex2[w->tile_num + ((SDL_GetTicks() / 100) % 66)].
			pixels[w->tile_p.y * T_W + w->tile_p.x];
		if (w->side == 1)
			w->color = (w->color >> 1) & 8355711;
		w->pixels[p.y * w->w + p.x] = w->color;
	}
}

void	ft_draw_map(t_wolf *w)
{
	int		i;
	int		j;
	t_point	pos;
	t_rect	rect;

	i = -1;
	rect.w = 10;
	rect.h = 10;
	pos.x = (int)w->player.y * 10 + w->player.y * 2.0 + 20;
	pos.y = (int)w->player.x * 10 + w->player.x * 2.0 + 10;
	ft_sdl_draw_disc(w->pixels, pos, 10, 0xFFFF00);
	ft_sdl_draw_line(w->pixels, ft_point(pos.x, pos.y),
			ft_point((pos.x + 5 + w->dir.y * 30.0),
				(pos.y + 5 + w->dir.x * 30.0)), 0xFF0000);
	while (++i < w->map.h)
	{
		j = -1;
		while (++j < w->map.w)
		{
			rect.x = j * rect.w + j * 2.0 + 20;
			rect.y = i * rect.h + i * 2.0 + 10;
			if (w->map.tab[i][j])
				ft_sdl_draw_rect(w->pixels, rect, 0xFF00FFFF);
		}
	}
}
