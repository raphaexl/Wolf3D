/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:28:08 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/26 20:44:36 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_sdl_put_pixel(Uint32 *pixels, int x, int y, int color)
{
	if (y >= 0 && y < RAY_H && x >= 0 && x < RAY_W)
		pixels[y * RAY_W + x] = color;
}

int		ft_rgb_color(unsigned int r, unsigned int g, unsigned int b)
{
	return (b + (g << 8) + (r << 16));
}

void	ft_setrgb_color(SDL_Color *col, Uint32 color)
{
	col->b = color % 256;
	col->g = (color / 256) % 256;
	col->r = (color / (256 * 256));
	col->a = 255;
}

int		ft_sdl_error(void)
{
	ft_putendl(SDL_GetError());
	return (-1);
}

void	ft_delay(unsigned int frame_limit)
{
	unsigned int		ticks;

	ticks = SDL_GetTicks();
	if (frame_limit < ticks)
		return ;
	if (frame_limit > ticks + FRAME_LIMIT)
		SDL_Delay(FRAME_LIMIT);
	else
		SDL_Delay(frame_limit - ticks);
}
