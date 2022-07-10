/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:39:53 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/10 15:10:06 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define WIN_HEIGHT 1920
# define WIN_WIDTH	1080

# define TEX_HEIGHT 64
# define TEX_WIDTH 64

# define NORTH 2
# define SOUTH 3
# define WEST 4
# define EAST 5

# define FLOOR 0
# define WALL 1
# define EMPTY -1

# define EXIT_KEY 53

typedef	struct s_person
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
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
	int		line_lenght;
	int		endian;
	int		type;
	char	*path;
	int		tex_height;
	int		tex_width;
}	t_texture;

typedef	struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
}	t_mlx;

typedef struct s_cub
{
	int			map_height;
	int			map_width;
	int			**map;
	char		*map_path;
	t_mlx		*mlx;
	t_rays		*rays;
	t_person	*person;
	t_texture	*no_tex;
	t_texture	*so_tex;
	t_texture	*we_tex;
	t_texture	*ea_tex;
}	t_cub;

/*---------------- Initialization ----------------*/
t_cub		*cub_init(char *map_path);
void		*set_textures(t_cub *cub);
t_person	*person_init(void);
t_mlx		*t_mlx_init(void);
t_texture	*texture_init(int type, char *path, t_mlx *mlx);

/*------------------ Destroing -------------------*/
void		map_free(int **map, int length);
void		cub_destroy(t_cub *cub);

/*-------------------- Utils ---------------------*/
void		print_err(char *str);
void		print_map(t_cub *cub);
void		my_put_pixel(t_cub *cub, int x, int y, int color);

/*------------------ Raycasting ------------------*/
void		raycasting(t_cub *cub);
void		tex_computation(t_cub *cub);
void		dda_computation(t_cub *cub);
void		distance_computation(t_cub *cub);
void		direction_computation(t_cub *cub, int x);

#endif