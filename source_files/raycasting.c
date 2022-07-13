/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:09:40 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/13 16:31:45 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	draw_floor_ceil(t_cub *cub, int x, int ceil, int floor)
{
	int	y;

	y = 0;
	while (y < cub->rays->draw_start)
	{
		my_put_pixel(cub, x, y, ceil);
		y++;
	}
	y = cub->rays->draw_end;
	while (y < WIN_HEIGHT)
	{
		my_put_pixel(cub, x, y, floor);
		y++;
	}
}

void	draw(t_cub *cub, t_texture *tex, int x)
{
	double	step;
	double	tex_pos;
	int		y;

	cub->rays->tex_x = (int)(cub->rays->wall_x * (double)tex->tex_width);
	if (cub->rays->side == 0 && cub->rays->ray_dir_x < 0)
		cub->rays->tex_x = tex->tex_width - cub->rays->tex_x - 1;
	if (cub->rays->side == 1 && cub->rays->ray_dir_y > 0)
		cub->rays->tex_x = tex->tex_width - cub->rays->tex_x - 1;
	y = cub->rays->draw_start;
	step = 1.0 * tex->tex_height / cub->rays->line_height;
	tex_pos = (cub->rays->draw_start - WIN_HEIGHT / 2
			+ cub->rays->line_height / 2) * step;
	while (y < cub->rays->draw_end)
	{
		cub->rays->tex_y = (int)tex_pos & (tex->tex_height - 1);
		tex_pos += step;
		my_put_pixel(cub, x, y,
			(((unsigned char)tex->addr[cub->rays->tex_y * tex->line_length
					+ cub->rays->tex_x * tex->bits_per_pixel / 8]) << 16
				| ((unsigned char)tex->addr[cub->rays->tex_y * tex->line_length
					+ cub->rays->tex_x * tex->bits_per_pixel / 8 + 1]) << 8
				| (unsigned char)tex->addr[cub->rays->tex_y * tex->line_length
				+ cub->rays->tex_x * tex->bits_per_pixel / 8 + 2]));
		y++;
	}
	/* Change after parsing */
	draw_floor_ceil(cub, x, 0x0095A7C0, 0x005D814E);
}

void	raycasting(t_cub *cub)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		direction_computation(cub, x);
		distance_computation(cub);
		dda_computation(cub);
		tex_computation(cub);
		if (cub->rays->side == 0 && cub->rays->ray_dir_x > 0)
			draw(cub, cub->so_tex, x);
		else if (cub->rays->side == 0 && cub->rays->ray_dir_x < 0)
			draw(cub, cub->no_tex, x);
		else if (cub->rays->side == 1 && cub->rays->ray_dir_y > 0)
			draw(cub, cub->ea_tex, x);
		else if (cub->rays->side == 1 && cub->rays->ray_dir_y < 0)
			draw(cub, cub->we_tex, x);
		cub->sprite->z_buff[x] = cub->rays->perp_wall_dist;
		x++;
	}
}
