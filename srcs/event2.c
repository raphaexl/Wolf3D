/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 01:30:21 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/27 22:42:45 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_process_event2(t_wolf *w)
{
	if (w->player.mv_forward)
	{
		if (!w->map.tab[(int)(w->player.x + w->dir.x * w->player.mv_speed)]\
				[(int)(w->player.y)])
			w->player.x += w->dir.x * w->player.mv_speed;
		if (!w->map.tab[(int)(w->player.x)][(int)(w->player.y + \
					w->dir.y * w->player.mv_speed)])
			w->player.y += w->dir.y * w->player.mv_speed;
		w->player.mv_forward = FALSE;
	}
	if (w->player.mv_backward)
	{
		if (!w->map.tab[(int)(w->player.x - w->dir.x * w->player.mv_speed)]\
				[(int)(w->player.y)])
			w->player.x -= w->dir.x * w->player.mv_speed;
		if (!w->map.tab[(int)(w->player.x)][(int)(w->player.y - \
					w->dir.y * w->player.mv_speed)])
			w->player.y -= w->dir.y * w->player.mv_speed;
		w->player.mv_backward = FALSE;
	}
}

void	ft_process_event3(t_wolf *w)
{
	if (w->player.rot_right)
	{
		ft_rotation2d(&w->dir.x, &w->dir.y, -w->player.rot_speed);
		ft_rotation2d(&w->cam_plane.x, &w->cam_plane.y, -w->player.rot_speed);
		w->player.rot_right = FALSE;
	}
	if (w->player.rot_left)
	{
		ft_rotation2d(&w->dir.x, &w->dir.y, w->player.rot_speed);
		ft_rotation2d(&w->cam_plane.x, &w->cam_plane.y, w->player.rot_speed);
		w->player.rot_left = FALSE;
	}
}

void	ft_process_event4(t_wolf *w)
{
	if (w->player.a_held)
	{
		w->me_arm = (++w->me_arm % N_ME);
		w->player.a_held = FALSE;
		Mix_PlayChannel(0, w->sd[w->me_arm], 0);
	}
}

void	ft_process_event5(t_wolf *w)
{
	if (w->player.is_firing)
	{
		if (w->me.state != STATE_MOVE)
		{
			w->me.state = STATE_MOVE;
			w->me.timer = TIME_BETWEEN_TWO_FRAMES;
			w->me.count = 0;
			ft_play_chunck(w->sd[w->me_arm + N_ME], 0);
		}
		w->player.is_firing = FALSE;
	}
}
