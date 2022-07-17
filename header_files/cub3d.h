/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:39:53 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/15 15:22:30 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCALE 10
# define MOUSE_HIDE 35

# define WIN_HEIGHT 1200
# define WIN_WIDTH 1800

# define NORTH 2
# define SOUTH 3
# define WEST 4
# define EAST 5

# define MOVESPEED 0.1
# define ROTATESPEED 0.1
# define FORWARD 13
# define BACKWARD 1
# define LEFT 0
# define RIGHT 2
# define ROTATE_L 123
# define ROTATE_R 124

# define FLOOR '0'
# define WALL '1'
# define EMPTY ' '
# define DOOR 'D'
# define SPRITE 'S'

# define EXIT_KEY 53

# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "struct.h"
# include "parser.h"

/*---------------- Initialization ----------------*/
t_cub		*cub_init(char *argv);
void		*set_textures(t_cub *cub);
t_person	*person_init(int dir, int x, int y);
t_mlx		*t_mlx_init(void);
t_texture	*texture_init(char *path, t_mlx *mlx);
t_sprite	*sprite_init(char *path, t_cub *cub);

/*------------------ Destroing -------------------*/
void		map_free(char **map, int length);
void		cub_destroy(t_cub *cub);

/*-------------------- Utils ---------------------*/
void		print_err(char *str);
void		my_put_pixel(t_cub *cub, int x, int y, int color);
int			rendering(t_cub *cub);
int			on_destroy(t_cub *cub);
int			hooking(int keycode, t_cub *cub);

/*------------------ Raycasting ------------------*/
void		raycasting(t_cub *cub, int i);
void		tex_computation(t_cub *cub);
void		dda_computation(t_cub *cub);
void		distance_computation(t_cub *cub);
void		direction_computation(t_cub *cub, int x);
void		draw(t_cub *cub, t_texture *tex, int x);

/*--------------- Moving/Rotating ----------------*/
void		moving(t_cub *cub, int keycode);
void		rotating(t_cub *cub, int keycode);
int			mouse_rotate(int x, int y, t_cub *cub);

/*------------------- Sprites --------------------*/
void		draw_sprite(t_cub *cub, int i);

/*-------------------- Doors ---------------------*/
int			door_open(t_cub *cub, int keycode);
int			door_close(t_cub *cub, int keycode);

void		draw_minimap(t_cub *cub, int i, int j);

#endif
