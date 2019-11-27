/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:54:55 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/26 14:03:46 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		ft_process_menu1(t_wolf *w, t_input *in)
{
	int			count;
	SDL_Rect	dest;

	dest.x = 0;
	dest.y = 0;
	dest.w = SCR_WIDTH;
	dest.h = SCR_HEIGHT;
	count = 1;
	ft_place_sprites(&w->sprites, &w->map);
	w->nb_sprites = ft_length_sprites(w->sprites);
	w->player.amo = w->nb_sprites;
	while (++count % MENU_WAIT_TIMER && !(in->quit))
	{
		ft_update_event(in);
		SDL_RenderCopy(w->ptr.renderer, w->menu[0], NULL, &dest);
		SDL_RenderPresent(w->ptr.renderer);
		SDL_Delay(1);
	}
	ft_play_music(w->mus[w->type], -1);
	w->restart = SDL_FALSE;
	w->game_over = SDL_FALSE;
}

void		ft_process_game_win(t_wolf *w, t_input *in)
{
	int			count;
	SDL_Rect	dest;

	dest.x = 0;
	dest.y = 0;
	dest.w = SCR_WIDTH;
	dest.h = SCR_HEIGHT;
	count = 1;
	Mix_HaltMusic();
	ft_play_chunck(w->sd[N_SOUNDS - 1], 3);
	ft_free_sprites(&w->sprites);
	while ((++count % (2 * MENU_WAIT_TIMER) || Mix_Playing(-1)) && !(in->quit))
	{
		ft_update_event(in);
		SDL_RenderCopy(w->ptr.renderer, w->menu[1], NULL, &dest);
		SDL_RenderPresent(w->ptr.renderer);
		SDL_Delay(1);
	}
	w->game_over = SDL_FALSE;
	w->type = ++(w->type) % 3;
	w->player.life = LIFE_MAX;
	w->player.score = 0;
	ft_process_menu1(w, in);
}

void		ft_process_game_loose(t_wolf *w, t_input *in)
{
	int			count;
	SDL_Rect	dest;

	dest.x = 0;
	dest.y = 0;
	dest.w = SCR_WIDTH;
	dest.h = SCR_HEIGHT;
	count = 1;
	Mix_HaltMusic();
	ft_play_chunck(w->sd[N_SOUNDS - 2], -1);
	ft_free_sprites(&w->sprites);
	while ((++count % (2 * MENU_WAIT_TIMER) || Mix_Playing(-1)) && !(in->quit))
	{
		ft_update_event(in);
		SDL_RenderCopy(w->ptr.renderer, w->menu[2], NULL, &dest);
		SDL_RenderPresent(w->ptr.renderer);
		SDL_Delay(5);
	}
	w->restart = SDL_FALSE;
	w->player.life = LIFE_MAX;
	w->player.score = 0;
	ft_process_menu1(w, in);
}

void		ft_wolf_game(t_wolf *w, t_input *in)
{
	w->game_over = (!w->player.life);
	w->restart = !(w->nb_sprites);
	if (w->restart)
	{
		w->restart = 0;
		ft_process_game_win(w, in);
	}
	else if (w->game_over)
	{
		w->game_over = SDL_FALSE;
		ft_process_game_loose(w, in);
	}
}

int			main(int argc, char *argv[])
{
	t_wolf		w;
	t_input		in;

	if (argc != 2 && write(1, "usage: ./wolf3d map_file\n", 25))
		return (EXIT_FAILURE);
	if (ft_wolf_init(&w, argv[1]))
	{
		ft_wolf_quit(&w);
		return (EXIT_FAILURE);
	}
	ft_memset(&in, SDL_FALSE, sizeof(t_input));
	ft_process_menu1(&w, &in);
	while (!in.quit && !w.game_over)
	{
		ft_wolf_game(&w, &in);
		ft_wolf_key(&w, &in);
		if (ft_wolf_draw(&w))
			ft_update_event(&in);
		SDL_RenderPresent(w.ptr.renderer);
		ft_delay(w.frame_limit);
	}
	ft_wolf_quit(&w);
	return (EXIT_SUCCESS);
}
