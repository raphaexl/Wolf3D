/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:29:16 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/26 20:44:31 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

t_sprite	ft_sprite(double x, double y, int tex)
{
	t_sprite	p;

	p.x = x;
	p.y = y;
	p.texture = tex;
	return (p);
}

t_font		ft_font(const char *message, const char *font_file, int font_size)
{
	t_font	f;

	f.mes = (char *)message;
	f.file = (char *)font_file;
	f.size = font_size;
	return (f);
}

SDL_Color	ft_sdl_color(Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
	SDL_Color c;

	c.a = a;
	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

SDL_Texture	*ft_get_render_text(SDL_Renderer *rend, t_font f, SDL_Color color)
{
	TTF_Font		*font;
	SDL_Surface		*surface;
	SDL_Texture		*texture;

	font = NULL;
	surface = NULL;
	texture = NULL;
	font = TTF_OpenFont(f.file, f.size);
	ERR_CHECK(surface = TTF_RenderText_Blended(font, f.mes, color));
	ERR_CHECK(texture = SDL_CreateTextureFromSurface(rend, surface));
	SDL_FreeSurface(surface);
	if (!font)
		perror(TTF_GetError());
	TTF_CloseFont(font);
	return (texture);
}

void		ft_render_draw_img(SDL_Renderer *ren, SDL_Texture *img, t_point p,\
		SDL_Rect *pos)
{
	SDL_Rect	src;

	src.x = p.x;
	src.y = p.y;
	src.w = pos->w;
	src.h = pos->h;
	if (ren && img)
		ERR_CHECK(SDL_RenderCopy(ren, img, &src, pos) == 0);
}
