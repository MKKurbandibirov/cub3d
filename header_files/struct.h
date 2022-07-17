/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 04:49:14 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/17 04:49:15 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

typedef struct s_plist	t_plist;

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
	char	*path;
	int		height;
	int		width;
	int		pos_x;
	int		pos_y;
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
	char		**map;
	t_mlx		*mlx;
	t_rays		*rays;
	t_person	*person;
	t_texture	*no_tex;
	t_texture	*so_tex;
	t_texture	*we_tex;
	t_texture	*ea_tex;
	t_texture	*door;
	t_sprite	**sprite;
	char		**sprite_texture;
	char		**wall_texture_path;
	int			clr_f;
	int			user_pos_x;
	int			user_pos_y;
	int			default_x;
	int			default_y;
	int			direction;
	int			clr_c;
	int			key_mouse_hide;
	int			cnt_texture_sp;
	int			sprite_pos_x;
	int			sprite_pos_y;
	int			curr_spr;
	int			cnt_door;
	int			str_in_map;
	int			**doors_pos;
}	t_cub;

typedef struct s_texture_prs
{
	char		*massiv[8];
	t_plist		*lst;
	int			cnt_lst;
	int			check_cnt;
}	t_texture_prs;

typedef struct s_plist
{
	int				id;
	char			*data;
	t_plist			*next;
	t_plist			*prev;
}	t_plist;

typedef struct s_prs
{
	char			**map;
	int				*strlen;
	int				max_len_str;
	t_texture_prs	*texture;
	t_plist			*preprs;
	int				len_lists;
	int				cnt_str_in_map;
	int				cnt_ewns;
	int				cnt_doors;
	int				cnt_yoda;
	int				sprite_pos_x;
	int				sprite_pos_y;
	int				curr_door;
	t_cub			*cub;
}	t_prs;
#endif
