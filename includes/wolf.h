/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:00:35 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/26 21:22:38 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define T_W 64
# define T_H 64
# define N1 16646144
# define N2 65536

# include "structs.h"
# include "libft.h"
# include <sys/stat.h>
# include <math.h>
# include <time.h>
# include <fcntl.h>

int			ft_randint(int min, int max);
void		ft_update_event(t_input *in);
void		ft_freesplitted(char **tab);
void		ft_wolf_free1(t_wolf *w);
void		ft_wolf_free2(t_wolf *w);
void		ft_play_chunck(Mix_Chunk *chunck, int channal);
void		ft_play_music(Mix_Music *music, int nb_time);
void		ft_process_menu1(t_wolf *w, t_input *quit);
void		ft_wolf_game(t_wolf *w, t_input *quit);
void		ft_place_sprites(t_sprite **s, t_map *m);
void		ft_load_sprites(t_wolf *w);
void		ft_init_player(t_player *p);
void		ft_init_variables1(t_wolf *w);
void		ft_init_guns(t_wolf *w);
void		ft_init_variables2(t_wolf *w);
void		ft_init_guns2(t_wolf *w);
void		ft_debug (void);
void		ft_debug2(t_sprite *sp, t_map *m);
t_sprite	*ft_create_sprites(t_vect2d pos, int texture);
void		ft_push_back_sprites(t_sprite **s, t_sprite *nw);
void		ft_pop_front_sprites(t_sprite **s);
void		ft_pop_back_sprites(t_sprite **s);
void		ft_free_sprites(t_sprite **s);
int			ft_length_sprites(t_sprite *s);
void		ft_print_sprites(t_sprite *s);
void		ft_clear_sprites(t_sprite **s);
t_sprite	*ft_sprites(t_sprite *s, int indice);

t_font		ft_font(const char *message, const char *font_file, int font_size);
void		ft_swap(void *const a, void *const b, size_t size);
void		ft_put_pixels(SDL_Surface *s, int x, int y, Uint32 pixel);
Uint32		ft_get_pixels(SDL_Surface *s, int x, int y);
SDL_Texture	*ft_load_image(SDL_Renderer *renderer, char *file_name);
SDL_Texture	*ft_get_render_text(SDL_Renderer *rend, t_font f, SDL_Color color);
void		ft_render_draw_img(SDL_Renderer	*rend, SDL_Texture *img, t_point p,\
		SDL_Rect	*q);
void		ft_delay(unsigned int frame_limt);
SDL_Color	ft_sdl_color(Uint32 r, Uint32 g, Uint32 b, Uint32 a);
Uint32		*ft_load_pixels(char *file_name);
Uint32		*ft_create_pixels(int w, int h);

int			ft_sdl_error(void);
void		ft_sdl_put_pixel(Uint32 *pixels, int x, int y, int color);
void		ft_clear_pixels(Uint32 *pixels);

int			ft_rgb_color(unsigned int r, unsigned int g, unsigned int b);
t_point		ft_point(int x, int y);
t_vect2d	ft_vector(double x, double y);
void		ft_get_free_pos(t_map *m, double *x, double *y);

void		ft_init_variables1(t_wolf *w);
void		ft_init_variables2(t_wolf *w);
void		ft_wolf_load1(t_wolf *w);
void		ft_wolf_load2(t_wolf *w);
int			ft_wolf_init(t_wolf *f, char *file);
void		ft_wolf_dda_helper(t_wolf *w);
void		ft_wolf_dda(t_wolf *w);
void		ft_wolf_end(t_wolf *w);
void		ft_wolf_cell_floorh(t_wolf *w);
void		ft_wolf_cell_floor(t_wolf *w);
void		ft_draw_map(t_wolf *w);
void		ft_draw(t_wolf *w);
void		ft_wolf_rm_sprites(t_wolf	*w);
int			ft_wolf_draw(t_wolf *w);
void		ft_wolf_type1(t_wolf *w);
void		ft_wolf_type2(t_wolf *w);
void		ft_process_event0(t_wolf *w, t_input *in);
void		ft_process_event1(t_wolf *w, t_input *in);
void		ft_process_event2(t_wolf *w);
void		ft_process_event3(t_wolf *w);
void		ft_process_event4(t_wolf *w);
void		ft_process_event5(t_wolf *w);
void		ft_process_event6(t_wolf *w, t_input *in);
void		ft_wolf_key(t_wolf *f, t_input *key);
void		ft_wolf_quit(t_wolf *f);
void		ft_delay(unsigned int frame_limit);
void		ft_init_variables2(t_wolf *w);
void		ft_init_variables3(t_wolf *w);

void		ft_sdl_draw_octant1(Uint32 *pixels, t_point p, t_point q, Uint32 c);
void		ft_sdl_draw_octant2(Uint32 *pixels, t_point p, t_point q, Uint32 c);
void		ft_sdl_draw_line(Uint32 *pixels, t_point p1, t_point p2, Uint32 c);
void		ft_sdl_draw_disc(Uint32 *pixels, t_point co, int rad, Uint32 col);
void		ft_sdl_draw_rect(Uint32 *pixels, t_rect rect, Uint32 color);

int			ft_sdl_init(t_ptr *ptr, int width, int height, const char *title);
int			ft_update_renderer(t_ptr *ptr, Uint32 *pixel);

void		ft_rotation2d(double *x, double *y, double angle);
void		ft_get_wolfcolor(t_map *m, int x, int y, Uint32 *color);

void		ft_wolf_sprite_1(t_wolf *w);
void		ft_wolf_sprite_2(t_wolf *w);
void		ft_sprite_sort(int *order, double *dist, int n);

void		ft_load_walls1(t_img *text);
void		ft_load_walls2(t_img *text);
void		ft_load_walls3(t_img *text);
void		ft_load_walls_1(t_img *text);
void		ft_load_walls_2(t_img *text);
void		ft_load_walls_3(t_img *text);

void		ft_load_objects1(t_img *text);
void		ft_load_objects2(t_img *text);
void		ft_load_objects_1(t_img *text);
void		ft_load_objects_2(t_img *text);
void		ft_init_guns1(t_wolf *w);
void		ft_init_guns2(t_wolf *w);

void		ft_fill_map(t_map *m, char *line, int y);
void		ft_read_file(t_map *m, char *file_name);
void		ft_error(void);
void		ft_sdl_quit(t_ptr *ptr);
#endif
