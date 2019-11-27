/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:25:42 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/26 21:21:01 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		ft_sdl_init(t_ptr *ptr, int width, int height, const char *title)
{
	ERR_CHECK(SDL_Init(SDL_INIT_EVERYTHING) == 0);
	ERR_CHECK(TTF_Init() == 0);
	ERR_CHECK(IMG_Init(IMG_INIT_PNG) != 0);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	Mix_Init(MIX_INIT_MP3);
	ERR_CHECK(ptr->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN));
	ERR_CHECK(ptr->renderer = SDL_CreateRenderer(ptr->window, -1,\
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
	ERR_CHECK(ptr->texture = SDL_CreateTexture(ptr->renderer, \
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, RAY_W, RAY_H));
	Mix_AllocateChannels(32);
	return (0);
}

void	ft_clear_pixels(Uint32 *pixels)
{
	int		i;

	i = -1;
	while (++i < T_W * T_H)
		pixels[i] = 0x000000;
}

int		ft_update_renderer(t_ptr *p, Uint32 *px)
{
	SDL_Rect	pos;

	pos.x = 20;
	pos.y = 20;
	pos.w = RAY_W;
	pos.h = RAY_H;
	SDL_UpdateTexture(p->texture, NULL, px, RAY_W * U32_SIZE);
	ft_render_draw_img(p->renderer, p->texture, ft_point(0, 0), &pos);
	return (0);
}

void	ft_sdl_quit(t_ptr *ptr)
{
	if (ptr->texture)
		SDL_DestroyTexture(ptr->texture);
	ptr->texture = NULL;
	if (ptr->window)
		SDL_DestroyWindow(ptr->window);
	ptr->window = NULL;
	if (ptr->renderer)
		SDL_DestroyRenderer(ptr->renderer);
	ptr->renderer = NULL;
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}
