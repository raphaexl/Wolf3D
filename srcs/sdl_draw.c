/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:15:44 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/25 02:53:48 by onahiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		ft_sdl_draw_octant1(Uint32 *pixels, t_point p, t_point q, Uint32 c)
{
	t_point		dp;
	t_point		pincr;
	int			error;
	int			i;

	i = -1;
	pincr.x = p.x < q.x ? 1 : -1;
	pincr.y = p.y < q.y ? 1 : -1;
	dp.x = abs(q.x - p.x);
	dp.y = abs(q.y - p.y);
	error = dp.x / 2;
	while (++i <= dp.x)
	{
		p.x += pincr.x;
		error += dp.y;
		if (error > dp.x)
		{
			error -= dp.x;
			p.y += pincr.y;
		}
		ft_sdl_put_pixel(pixels, p.x, p.y, c);
	}
}

void		ft_sdl_draw_octant2(Uint32 *pixels, t_point p, t_point q, Uint32 c)
{
	t_point		dp;
	t_point		pincr;
	int			error;
	int			i;

	pincr.x = (p.x < q.x) ? 1 : -1;
	pincr.y = (p.y < q.y) ? 1 : -1;
	dp.x = abs(q.x - p.x);
	dp.y = abs(q.y - p.y);
	error = dp.y / 2;
	i = -1;
	while (++i <= dp.y)
	{
		p.y += pincr.y;
		error += dp.x;
		if (error > dp.y)
		{
			error -= dp.y;
			p.x += pincr.x;
		}
		ft_sdl_put_pixel(pixels, p.x, p.y, c);
	}
}

void		ft_sdl_draw_line(Uint32 *pixels, t_point p, t_point q, Uint32 c)
{
	ft_sdl_put_pixel(pixels, p.x, p.y, c);
	ft_sdl_put_pixel(pixels, q.x, q.y, c);
	if (abs(q.x - p.x) >= abs(q.y - p.y))
		ft_sdl_draw_octant1(pixels, p, q, c);
	else
		ft_sdl_draw_octant2(pixels, p, q, c);
}

void		ft_sdl_draw_disc(Uint32 *pixels, t_point co, int radius, Uint32 col)
{
	int		d;
	int		x;
	int		y;

	y = radius;
	d = 3 - (radius << 1);
	x = -1;
	while (y >= ++x)
	{
		ft_sdl_draw_line(pixels, ft_point(co.x - x, co.y - y), ft_point(co.x + 1
			+ x, co.y - y), col);
		ft_sdl_draw_line(pixels, ft_point(co.x - x, co.y + y), ft_point(co.x
			+ 1 + x, co.y + y), col);
		ft_sdl_draw_line(pixels, ft_point(co.x - y, co.y - x), ft_point(co.x + 1
			+ y, co.y - x), col);
		ft_sdl_draw_line(pixels, ft_point(co.x - y, co.y + x), ft_point(co.x + 1
			+ y, co.y + x), col);
		if (d < 0)
			d = d + (x << 2) + 6;
		else
		{
			d = d + ((x - y) << 2) + 10;
			--y;
		}
	}
}

void		ft_sdl_draw_rect(Uint32 *pixels, t_rect rect, Uint32 c)
{
	int		i;
	int		j;

	i = rect.y - 1;
	while (++i < rect.y + rect.h)
	{
		j = rect.x - 1;
		while (++j < rect.x + rect.w)
			ft_sdl_put_pixel(pixels, j, i, c);
	}
}
