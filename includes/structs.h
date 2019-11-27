/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:38:52 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/26 21:39:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <SDL2/SDL.h>
# include <SDL2_mixer/SDL_mixer.h>
# include <SDL2_ttf/SDL_ttf.h>
# include <SDL2_image/SDL_image.h>

# define TRUE 1
# define FALSE 0
# define MAX_SIZE 1048
# define SCR_WIDTH 1094
# define SCR_HEIGHT 1024
# define RAY_W 1024
# define RAY_H 820
# define NB_SPRITES 19
# define NB_TEXT 120
# define N_SOUNDS 14
# define N_MUSICS 4
# define NB_TILES 120
# define WALL_MAX_INDEX 70
# define TRANS_PARENCY 0x000000
# define N_POS 10
# define N_FACE 3
# define N_ME 4
# define NF_ME 5
# define N_ITEMS 6
# define LIFE_CHRONO 100
# define STATE_MOVE 1
# define TIME_BETWEEN_TWO_FRAMES 2
# define FRAME_LIMIT 2
# define STATE_PAUSE 0
# define FPS 60
# define MENU_WAIT_TIMER 400
# define MENU_ITEMS 3
# define LIFE_MAX 100
# define SET(n, min, max) ((n < min) ? (min) : (n > max) ? (max) : (n))
# define ERR_CHECK(cond) if (!(cond)) perror(SDL_GetError());
# define U32_SIZE  sizeof(Uint32)
# define TEX_SIZE sizeof(SDL_Texture *)

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef	struct		s_vect2d
{
	double	x;
	double	y;
}					t_vect2d;

typedef	struct		s_rect
{
	int		x;
	int		y;
	int		w;
	int		h;
}					t_rect;

typedef struct		s_input
{
	SDL_bool		quit;
	SDL_bool		keys[SDL_NUM_SCANCODES];
	int				mousexrel;
}					t_input;

typedef	struct		s_font
{
	char	*mes;
	char	*file;
	int		size;
}					t_font;

typedef	struct		s_ptr
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
}					t_ptr;

typedef	struct		s_img
{
	Uint32			*pixels;
}					t_img;

typedef	struct		s_map
{
	int				tab[MAX_SIZE][MAX_SIZE];
	int				w;
	int				h;
}					t_map;

typedef struct		s_player
{
	SDL_bool		is_firing;
	SDL_bool		t_held;
	SDL_bool		a_held;
	SDL_bool		h_held;
	SDL_bool		r_held;
	SDL_bool		mv_forward;
	SDL_bool		mv_backward;
	SDL_bool		rot_right;
	SDL_bool		rot_left;
	int				score;
	int				life;
	int				amo;
	double			x;
	double			y;
	double			mv_speed;
	double			rot_speed;
}					t_player;

typedef struct		s_sprite
{
	double				x;
	double				y;
	int					remove;
	int					texture;
	struct s_sprite		*next;
}					t_sprite;

typedef	struct		s_animated
{
	SDL_Texture		**img;
	Uint32			frame_max;
	int				timer;
	int				state;
	Uint32			count;
}					t_animated;

typedef struct		s_wolf
{
	SDL_Texture		*item[N_ITEMS];
	SDL_Texture		*fps;
	t_animated		me;
	t_animated		face;
	SDL_Texture		*arm_img[N_ME];
	SDL_Texture		*menu[MENU_ITEMS];
	int				me_arm;
	SDL_Texture		*bg;
	Mix_Chunk		*sd[N_SOUNDS];
	Mix_Music		*mus[N_MUSICS];
	SDL_Color		c5[N_ITEMS];
	Uint32			*pixels;
	SDL_Rect		pos[N_POS];
	t_img			tex1[NB_TILES];
	t_img			tex2[NB_TILES];
	t_map			map;
	t_ptr			ptr;
	t_player		player;
	t_sprite		*sprites;
	t_vect2d		dir;
	t_vect2d		cam_plane;
	t_vect2d		ray_dir;
	t_vect2d		delta_dist;
	t_vect2d		side_dist;
	t_vect2d		p_floor;
	t_vect2d		cur_floor;
	t_vect2d		sprite_pos;
	t_vect2d		sprite_trans;
	t_point			ps;
	t_point			pd;
	t_point			tile_p;
	t_point			tile_floor;
	t_point			map_pos;
	t_point			step;
	t_point			sprite_size;
	t_point			sp_start;
	t_point			sp_end;
	double			wall_x;
	double			weight;
	double			per_wall_dist;
	double			cam_x;
	double			frame_time;
	double			z_buffer[RAY_W];
	double			*sprite_dist;
	int				*sprite_order;
	int				nb_sprites;
	double			inv_det;
	int				x;
	int				d;
	int				help;
	int				type;
	SDL_bool		restart;
	SDL_bool		game_over;
	Uint32			color;
	Uint32			c1;
	Uint32			c2;
	Uint32			c3;
	Uint32			curr_time;
	Uint32			frame_limit;
	Uint32			old_time;
	int				hit;
	int				side;
	int				line_height;
	int				tile_num;
	int				w;
	int				h;
	int				temp;
	int				sprite_screen;
	int				tex_x;
	int				tex_y;
}					t_wolf;

#endif
