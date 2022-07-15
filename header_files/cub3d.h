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

# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"

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

typedef struct s_person
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	int		mouse_x;
}	t_person;

typedef struct s_rays
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
}	t_rays;

typedef struct s_texture
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		type;
	char	*path;
	int		tex_height;
	int		tex_width;
}	t_texture;

typedef struct s_sprite
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*path;  /*Change after parsing*/
	int		height;
	int		width;
	int		pos_x; /*Change after parsing*/
	int		pos_y; /*Change after parsing*/
	double	sprite_x;
	double	sprite_y;
	double	transform_x;
	double	transform_y;
	int		draw_start_x;
	int		draw_end_x;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_height;
	int		sprite_width;
	int		sprite_screen_x;
	int		tex_x;
	int		tex_y;
	double	z_buff[WIN_WIDTH];
}	t_sprite;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_mlx;

typedef struct s_cub
{
	time_t		start;
	time_t		end;
	int			map_height;
	int			map_width;
	char		**map; /*Change after parsing*/
	t_mlx		*mlx;
	t_rays		*rays;
	t_person	*person;
	t_texture	*no_tex;
	t_texture	*so_tex;
	t_texture	*we_tex;
	t_texture	*ea_tex;
	t_texture	*door;
	t_sprite	**sprite;
	int			curr_spr;
	int			**doors_pos; /*Change after parsing*/
}	t_cub;

/*---------------- Initialization ----------------*/
t_cub		*cub_init(void);
void		*set_textures(t_cub *cub);
t_person	*person_init(int dir);
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

#endif