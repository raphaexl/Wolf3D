/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 22:21:00 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/27 22:43:21 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		ft_wolf_rm_sprites(t_wolf *w)
{
	t_sprite	*p;

	p = w->sprites;
	while (p)
	{
		if (p->x < 0 || p->x > w->map.h - 1 || p->y < 0 || p->y > w->map.w - 1)
			p->remove = 1;
		if (w->map.tab[(int)p->x][(int)p->y])
			p->remove = 1;
		if ((int)w->player.x == (int)p->x && (int)w->player.y == (int)p->y)
		{
			p->remove = 1;
			w->player.score++;
			ft_play_chunck(w->sd[N_ME + 5], -1);
		}
		p = p->next;
	}
}

void		ft_draw_guns(t_wolf *w)
{
	static		long	count = 1;

	w->face.count = (SDL_GetTicks() / 1000) % N_FACE;
	if (!(count % LIFE_CHRONO))
		w->player.life = w->player.life ? w->player.life - 1 : w->player.life;
	if (w->me.state == STATE_MOVE)
		w->me.count = (SDL_GetTicks() / 100) % (NF_ME + 1);
	if (w->me.count == 5)
	{
		w->me.state = STATE_PAUSE;
		w->me.count = 0;
	}
	SDL_RenderCopy(w->ptr.renderer, w->me.img[w->me_arm * NF_ME
			+ w->me.count], NULL, &w->pos[6]);
	SDL_RenderCopy(w->ptr.renderer, w->face.img[w->face.count], NULL,
			&w->pos[7]);
	SDL_RenderCopy(w->ptr.renderer, w->arm_img[w->me_arm], NULL, &w->pos[8]);
	count++;
}

void		ft_wolf_draw2(t_wolf *w)
{
	int i;

	i = -1;
	SDL_RenderCopy(w->ptr.renderer, w->bg, NULL, &w->pos[9]);
	ft_clear_sprites(&w->sprites);
	w->nb_sprites = ft_length_sprites(w->sprites);
	w->item[0] = ft_get_render_text(w->ptr.renderer,
		ft_font(ft_itoa(w->player.score), "fonts/angelina.TTF", 64), w->c5[0]);
	w->item[1] = ft_get_render_text(w->ptr.renderer, ft_font(ft_strjoin("FPS: ",
		ft_itoa(1.0 / w->frame_time)), "fonts/angelina.TTF", 42), w->c5[1]);
	w->item[2] = ft_get_render_text(w->ptr.renderer,
		ft_font(ft_itoa(w->player.life), "fonts/angelina.TTF", 64), w->c5[2]);
	w->item[3] = ft_get_render_text(w->ptr.renderer,
		ft_font(ft_itoa(w->type), "fonts/angelina.TTF", 64), w->c5[3]);
	w->item[4] = ft_get_render_text(w->ptr.renderer,
		ft_font(ft_itoa(w->help), "fonts/angelina.TTF", 64), w->c5[4]);
	w->item[5] = ft_get_render_text(w->ptr.renderer,
		ft_font(ft_itoa(w->player.amo), "fonts/angelina.TTF", 64), w->c5[5]);
	while (++i < 6)
	{
		SDL_QueryTexture(w->item[i], NULL, NULL, &w->pos[i].w, &w->pos[i].h);
		SDL_RenderCopy(w->ptr.renderer, w->item[i], NULL, &w->pos[i]);
		SDL_DestroyTexture(w->item[i]);
		w->item[i] = NULL;
	}
}

int			ft_wolf_draw(t_wolf *w)
{
	w->x = -1;
	ft_clear_pixels(w->pixels);
	SDL_RenderClear(w->ptr.renderer);
	ft_update_renderer(&w->ptr, w->pixels);
	while (++w->x < w->w)
	{
		ft_wolf_dda_helper(w);
		ft_wolf_dda(w);
		ft_wolf_end(w);
	}
	ft_wolf_sprite_1(w);
	if (w->help)
		ft_draw_map(w);
	w->old_time = w->curr_time;
	w->curr_time = SDL_GetTicks();
	w->frame_time = (float)(w->curr_time - w->old_time) / 800.0;
	ft_wolf_draw2(w);
	ft_draw_guns(w);
	SDL_Delay(1);
	return (1);
}

void		ft_wolf_quit(t_wolf *w)
{
	int		i;

	i = -1;
	while (++i < NB_TILES)
	{
		free(w->tex2[i].pixels);
		w->tex2[i].pixels = NULL;
	}
	free(w->sprite_dist);
	free(w->sprite_order);
	if (w->sprites)
		ft_free_sprites(&w->sprites);
	w->sprites = NULL;
	i = -1;
	while (++i < N_SOUNDS)
		Mix_FreeChunk(w->sd[i]);
	i = -1;
	while (++i < N_MUSICS)
		Mix_FreeMusic(w->mus[i]);
	ft_wolf_free1(w);
	ft_wolf_free2(w);
	ft_sdl_quit(&w->ptr);
}
