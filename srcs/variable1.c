/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 01:39:08 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/27 22:46:55 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_init_player(t_player *p)
{
	p->x = 0;
	p->y = 0;
	p->life = LIFE_MAX;
	p->amo = 0;
	p->score = 0;
	p->mv_speed = 0.2;
	p->rot_speed = 0.08;
	p->is_firing = 0;
	p->t_held = SDL_FALSE;
	p->r_held = SDL_FALSE;
	p->a_held = SDL_FALSE;
	p->h_held = SDL_FALSE;
	p->mv_forward = SDL_FALSE;
	p->mv_backward = SDL_FALSE;
	p->rot_left = SDL_FALSE;
	p->rot_right = SDL_FALSE;
}

void	ft_init_variables1(t_wolf *w)
{
	w->dir = ft_vector(-1.0, 0.0);
	w->cam_plane = ft_vector(0, 0.66);
	w->ray_dir = ft_vector(0.0, 0.0);
	w->delta_dist = ft_vector(0.0, .0);
	w->side_dist = ft_vector(0.0, 0.0);
	w->sprite_pos = ft_vector(0.0, 0.0);
	w->map_pos = ft_point(12, 12);
	w->step = ft_point(0, 0);
	w->tile_p = ft_point(0, 0);
	w->sprite_pos = ft_vector(0.0, .0);
	w->sprite_trans = ft_vector(0.0, .0);
	w->d = 0;
	w->hit = 0;
	w->help = 0;
	w->side = 0;
	w->type = 0;
	w->w = RAY_W;
	w->h = RAY_H;
	w->weight = 0;
	w->per_wall_dist = .0;
	w->line_height = 0;
	w->frame_time = 0.0;
}

void	ft_init_variables3(t_wolf *w)
{
	w->tile_floor = ft_point(0, 0);
	w->sp_start = ft_point(0, 0);
	w->sp_end = ft_point(0, 0);
	w->sprite_size = ft_point(0, 0);
	w->c1 = 0xFFF0FF;
	w->c2 = 0xFDFFDD;
	w->c5[0] = ft_sdl_color(102, 0, 51, 255);
	w->c5[1] = ft_sdl_color(204, 204, 255, 255);
	w->c5[2] = ft_sdl_color(153, 255, 204, 255);
	w->c5[3] = ft_sdl_color(255, 153, 255, 255);
	w->c5[4] = ft_sdl_color(255, 255, 204, 255);
	w->c5[5] = ft_sdl_color(255, 204, 255, 255);
	w->pos[0].x = 180;
	w->pos[0].y = RAY_H + 100;
	w->pos[1].x = SCR_WIDTH - 255;
	w->pos[1].y = 35;
	w->pos[2].x = SCR_WIDTH / 2 + 25;
	w->pos[2].y = RAY_H + 100;
	w->pos[3].x = SCR_WIDTH / 2 + 170;
	w->pos[3].y = RAY_H + 100;
	w->pos[4].x = 80;
	w->pos[4].y = RAY_H + 100;
	w->pos[5].x = SCR_WIDTH / 2 - 180;
	w->pos[5].y = RAY_H + 100;
}

void	ft_init_guns(t_wolf *w)
{
	if ((w->me.img = (SDL_Texture **)malloc(NF_ME * N_ME * TEX_SIZE)))
	{
		w->me.img[0] = ft_load_image(w->ptr.renderer, "imgs/hud/knife_0.png");
		w->me.img[1] = ft_load_image(w->ptr.renderer, "imgs/hud/knife_1.png");
		w->me.img[2] = ft_load_image(w->ptr.renderer, "imgs/hud/knife_2.png");
		w->me.img[3] = ft_load_image(w->ptr.renderer, "imgs/hud/knife_3.png");
		w->me.img[4] = ft_load_image(w->ptr.renderer, "imgs/hud/knife_4.png");
		w->me.img[5] = ft_load_image(w->ptr.renderer, "imgs/hud/minigun_0.png");
		w->me.img[6] = ft_load_image(w->ptr.renderer, "imgs/hud/minigun_1.png");
		w->me.img[7] = ft_load_image(w->ptr.renderer, "imgs/hud/minigun_2.png");
		w->me.img[8] = ft_load_image(w->ptr.renderer, "imgs/hud/minigun_3.png");
		w->me.img[9] = ft_load_image(w->ptr.renderer, "imgs/hud/minigun_4.png");
		w->me.img[10] = ft_load_image(w->ptr.renderer, "imgs/hud/pistol_0.png");
		w->me.img[11] = ft_load_image(w->ptr.renderer, "imgs/hud/pistol_1.png");
		w->me.img[12] = ft_load_image(w->ptr.renderer, "imgs/hud/pistol_2.png");
		w->me.img[13] = ft_load_image(w->ptr.renderer, "imgs/hud/pistol_3.png");
		w->me.img[14] = ft_load_image(w->ptr.renderer, "imgs/hud/pistol_4.png");
		w->me.img[15] = ft_load_image(w->ptr.renderer, "imgs/hud/smg_0.png");
		w->me.img[16] = ft_load_image(w->ptr.renderer, "imgs/hud/smg_1.png");
		w->me.img[17] = ft_load_image(w->ptr.renderer, "imgs/hud/smg_2.png");
		w->me.img[18] = ft_load_image(w->ptr.renderer, "imgs/hud/smg_3.png");
		w->me.img[19] = ft_load_image(w->ptr.renderer, "imgs/hud/smg_4.png");
	}
	else
		ft_sdl_error();
}

void	ft_init_guns2(t_wolf *w)
{
	w->me.state = STATE_PAUSE;
	w->me.timer = 0;
	w->me.count = 0;
	w->me.frame_max = NF_ME;
	if (!(w->face.img = (SDL_Texture **)malloc(N_ME * sizeof(SDL_Texture *))))
		ft_error();
	w->face.img[0] = ft_load_image(w->ptr.renderer, "imgs/display/face1.png");
	w->face.img[1] = ft_load_image(w->ptr.renderer, "imgs/display/face2.png");
	w->face.img[2] = ft_load_image(w->ptr.renderer, "imgs/display/face3.png");
	w->face.state = STATE_MOVE;
	w->face.timer = 0;
	w->face.count = 0;
	w->face.frame_max = N_FACE;
	w->arm_img[0] = ft_load_image(w->ptr.renderer, "imgs/display/knife.png");
	w->arm_img[1] = ft_load_image(w->ptr.renderer, "imgs/display/minigun.png");
	w->arm_img[2] = ft_load_image(w->ptr.renderer, "imgs/display/pistol.png");
	w->arm_img[3] = ft_load_image(w->ptr.renderer, "imgs/display/smg.png");
	w->menu[0] = ft_load_image(w->ptr.renderer, "imgs/menu/menu_open.png");
	w->menu[1] = ft_load_image(w->ptr.renderer, "imgs/display/win.png");
	w->menu[2] = ft_load_image(w->ptr.renderer, "imgs/display/game_over.png");
}
