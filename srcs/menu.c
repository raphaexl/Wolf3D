/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 07:20:03 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/27 22:46:33 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		ft_play_chunck(Mix_Chunk *chunk, int channal)
{
	if (Mix_Playing(channal))
		Mix_HaltChannel(channal);
	else if (Mix_Paused(channal))
	{
		Mix_Resume(channal);
	}
	else
		Mix_PlayChannel(channal, chunk, 0);
}

void		ft_play_music(Mix_Music *mus, int nb_time)
{
	if (Mix_PlayingMusic())
		Mix_HaltMusic();
	else if (Mix_PausedMusic())
	{
		Mix_ResumeMusic();
	}
	else
		Mix_PlayMusic(mus, nb_time);
}

void		ft_wolf_free1(t_wolf *w)
{
	int		i;

	i = -1;
	while (++i < N_ITEMS)
	{
		if (w->item[i])
			SDL_DestroyTexture(w->item[i]);
		w->item[i] = NULL;
	}
	i = -1;
	while (++i < N_ME)
	{
		if (w->arm_img[i])
			SDL_DestroyTexture(w->arm_img[i]);
		w->arm_img[i] = NULL;
	}
	i = -1;
	while (++i < MENU_ITEMS)
	{
		if (w->menu[i])
			SDL_DestroyTexture(w->menu[i]);
		w->menu[i] = NULL;
	}
	if (w->pixels)
		free(w->pixels);
}

void		ft_wolf_free2(t_wolf *w)
{
	int		i;

	i = -1;
	while (++i < N_ME * NF_ME)
	{
		if (w->me.img[i])
			SDL_DestroyTexture(w->me.img[i]);
		w->me.img[i] = NULL;
	}
	i = -1;
	while (++i < N_FACE)
	{
		if (w->face.img[i])
			SDL_DestroyTexture(w->face.img[i]);
		w->face.img[i] = NULL;
	}
	if (w->bg)
		SDL_DestroyTexture(w->bg);
	w->bg = NULL;
	if (w->fps)
		SDL_DestroyTexture(w->fps);
	w->fps = NULL;
	w->pixels = NULL;
}
