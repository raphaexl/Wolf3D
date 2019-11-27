/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 05:44:42 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/27 22:43:38 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_process_event0(t_wolf *w, t_input *in)
{
	if (in->keys[SDL_SCANCODE_T])
	{
		if (!w->player.t_held)
		{
			w->player.t_held = TRUE;
			w->type = ++w->type % 3;
			Mix_PlayChannel(-1, w->sd[N_ME + 4], 0);
		}
	}
	if (in->keys[SDL_SCANCODE_H])
	{
		if (!w->player.h_held)
		{
			w->player.h_held = TRUE;
			w->help = w->help ? FALSE : TRUE;
			Mix_PlayChannel(-1, w->sd[N_ME + 4], 0);
		}
	}
}

void	ft_process_event1(t_wolf *w, t_input *in)
{
	if (in->keys[SDL_SCANCODE_UP])
		w->player.mv_forward = w->player.mv_forward ? FALSE : TRUE;
	if (in->keys[SDL_SCANCODE_DOWN])
		w->player.mv_backward = w->player.mv_backward ? FALSE : TRUE;
	if (in->keys[SDL_SCANCODE_LEFT])
		w->player.rot_left = w->player.rot_left ? FALSE : TRUE;
	if (in->keys[SDL_SCANCODE_RIGHT])
		w->player.rot_right = w->player.rot_right ? FALSE : TRUE;
	if (in->keys[SDL_SCANCODE_SPACE])
		w->player.is_firing = (w->player.is_firing) ? FALSE : TRUE;
	if (in->keys[SDL_SCANCODE_A])
		w->player.a_held = TRUE;
	ft_rotation2d(&w->dir.x, &w->dir.y, -(in->mousexrel * 1.0 / 1000.0));
	ft_rotation2d(&w->cam_plane.x, &w->cam_plane.y,
		-(in->mousexrel * 1.0 / 1000.0));
}

void	ft_process_event6(t_wolf *w, t_input *in)
{
	if (in->keys[SDL_SCANCODE_T])
	{
		w->player.t_held = 0;
		w->type = w->type;
	}
	if (in->keys[SDL_SCANCODE_A])
		w->player.a_held = 0;
	if (in->keys[SDL_SCANCODE_H])
		w->player.h_held = 0;
	if (in->keys[SDL_SCANCODE_UP])
		w->player.mv_forward = 0;
	if (in->keys[SDL_SCANCODE_UP])
		w->player.mv_backward = 0;
	if (in->keys[SDL_SCANCODE_LEFT])
		w->player.rot_left = 0;
	if (in->keys[SDL_SCANCODE_RIGHT])
		w->player.rot_right = 0;
	if (in->keys[SDL_SCANCODE_SPACE])
		w->player.is_firing = FALSE;
}

void	ft_wolf_key(t_wolf *w, t_input *key)
{
	ft_process_event0(w, key);
	ft_process_event1(w, key);
	ft_wolf_rm_sprites(w);
	ft_process_event2(w);
	ft_process_event3(w);
	ft_process_event4(w);
	ft_process_event5(w);
	ft_process_event6(w, key);
}
