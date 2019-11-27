/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:54:50 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/26 21:37:42 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_wolf_load3(t_wolf *w)
{
	w->tex1[10].pixels = ft_load_pixels("imgs/ceiling/row-1-col-1.png");
	w->tex1[11].pixels = ft_load_pixels("imgs/ceiling/row-1-col-2.png");
	w->tex1[15].pixels = ft_load_pixels("imgs/ceiling/row-1-col-3.png");
	w->tex1[12].pixels = ft_load_pixels("imgs/ceiling/row-1-col-5.png");
	w->tex1[13].pixels = ft_load_pixels("imgs/ceiling/row-1-col-6.png");
}

void	ft_wolf_load1(t_wolf *w)
{
	ft_init_guns(w);
	ft_init_guns2(w);
	SDL_QueryTexture(w->me.img[0], NULL, NULL, &w->pos[6].w, &w->pos[6].h);
	w->pos[6].w += 200;
	w->pos[6].h += 200;
	w->pos[6].x = RAY_W / 2 - w->pos[6].w / 2;
	w->pos[6].y = RAY_H - w->pos[6].h + 20;
	SDL_QueryTexture(w->face.img[0], NULL, NULL, &w->pos[7].w, &w->pos[7].h);
	w->pos[7].x = RAY_W / 2 - w->pos[7].w / 2;
	w->pos[7].y = RAY_H + 55;
	SDL_QueryTexture(w->arm_img[0], NULL, NULL, &w->pos[8].w, &w->pos[8].h);
	w->pos[8].x = SCR_WIDTH - (40 + w->pos[8].w);
	w->pos[8].y = RAY_H + 55;
	w->bg = ft_load_image(w->ptr.renderer, "imgs/display/cadre.png");
	SDL_QueryTexture(w->bg, NULL, NULL, &w->pos[9].w, &w->pos[9].h);
	w->pos[9].x = 0;
	w->pos[9].y = 0;
}

void	ft_load_sound(t_wolf *w)
{
	ERR_CHECK(w->sd[0] = Mix_LoadWAV("audios/Knife.wav"));
	ERR_CHECK(w->sd[1] = Mix_LoadWAV("audios/Thud.wav"));
	ERR_CHECK(w->sd[2] = Mix_LoadWAV("audios/toggle.wav"));
	ERR_CHECK(w->sd[3] = Mix_LoadWAV("audios/select.wav"));
	ERR_CHECK(w->sd[N_ME] = Mix_LoadWAV("audios/knife_throw.wav"));
	ERR_CHECK(w->sd[N_ME + 1] = Mix_LoadWAV("audios/GatlingGun.wav"));
	ERR_CHECK(w->sd[N_ME + 2] = Mix_LoadWAV("audios/Pistol.wav"));
	ERR_CHECK(w->sd[N_ME + 3] = Mix_LoadWAV("audios/MachineGun.wav"));
	ERR_CHECK(w->sd[N_ME + 4] = Mix_LoadWAV("audios/Key.wav"));
	ERR_CHECK(w->sd[N_ME + 5] = Mix_LoadWAV("audios/Pickup.wav"));
	ERR_CHECK(w->sd[N_ME + 6] = Mix_LoadWAV("audios/BossSpeak1.wav"));
	ERR_CHECK(w->sd[N_ME + 7] = Mix_LoadWAV("audios/AllRight.wav"));
	ERR_CHECK(w->sd[N_ME + 8] = Mix_LoadWAV("audios/PlayerDies.wav"));
	ERR_CHECK(w->sd[N_ME + 9] = Mix_LoadWAV("audios/win.wav"));
	ERR_CHECK(w->mus[0] = Mix_LoadMUS("audios/lvl1.mp3"));
	ERR_CHECK(w->mus[1] = Mix_LoadMUS("audios/lvl2.mp3"));
	ERR_CHECK(w->mus[2] = Mix_LoadMUS("audios/lvl3.mp3"));
	ERR_CHECK(w->mus[3] = Mix_LoadMUS("audios/menu.mp3"));
}

int		ft_wolf_init(t_wolf *w, char *file)
{
	ft_init_variables1(w);
	ft_init_variables2(w);
	ft_init_player(&w->player);
	ft_read_file(&w->map, file);
	ft_load_sprites(w);
	ft_load_walls1(w->tex2);
	ft_load_walls2(w->tex2);
	ft_load_walls3(w->tex2);
	ft_load_objects1(w->tex2);
	ft_load_objects2(w->tex2);
	ft_wolf_load2(w);
	ft_wolf_load3(w);
	ft_load_walls_1(w->tex1);
	ft_load_walls_2(w->tex1);
	ft_load_walls_3(w->tex1);
	ft_load_objects_1(w->tex1);
	ft_load_objects_2(w->tex1);
	ft_sdl_init(&w->ptr, SCR_WIDTH, SCR_HEIGHT, "42 WOLF3D");
	ft_wolf_load1(w);
	ft_get_free_pos(&w->map, &w->player.x, &w->player.y);
	w->pixels = ft_create_pixels(RAY_W, RAY_H);
	ft_load_sound(w);
	ft_memset(w->pixels, 0x000000, sizeof(Uint32) * RAY_W * RAY_H);
	w->frame_limit = SDL_GetTicks() + 16;
	return (0);
}

void	ft_wolf_load2(t_wolf *w)
{
	int		i;
	int		j;

	i = -1;
	while ((++i < NB_TEXT) || !(i = -1))
		w->tex1[i].pixels = ft_create_pixels(T_W, T_H);
	while ((++i < T_H) && (j = -1))
	{
		while (++j < T_W)
		{
			w->c1 = (i * 256 / T_W) ^ (j * 256 / T_H);
			w->c2 = j * 256 / T_W;
			w->c3 = j * 128 / T_H + i * 128 / T_W;
			w->tex1[0].pixels[i * T_W + j] = N1 * (i != j && i != T_W - j);
			w->tex1[1].pixels[i * T_W + j] = w->c3 + 256 * w->c3 + N2 * w->c3;
			w->tex1[2].pixels[i * T_W + j] = 256 * w->c3 + N2 * w->c3;
			w->tex1[3].pixels[i * T_W + j] = w->c1 + 256 * w->c1 + N2 * w->c1;
			w->tex1[4].pixels[i * T_W + j] = 256 * w->c1;
			w->tex1[5].pixels[i * T_W + j] = N2 * 192 * (i % 16 && j % 16);
			w->tex1[6].pixels[i * T_W + j] = N2 * w->c2;
			w->tex1[7].pixels[i * T_W + j] = 128 + 256 * 128 + N2 * 128;
			w->tex1[8].pixels[i * T_W + j] = 0x0000FF;
			w->tex1[9].pixels[i * T_W + j] = 0x00001F;
		}
	}
}
