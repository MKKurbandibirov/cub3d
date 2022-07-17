/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:09:40 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/15 15:30:33 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static void	draw_floor_ceil(t_cub *cub, int x, int ceil, int floor)
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

static void	helper(t_cub *cub, t_texture *tex)
{
	cub->rays->tex_x = (int)(cub->rays->wall_x * (double)tex->tex_width);
	if (cub->rays->side == 0 && cub->rays->ray_dir_x < 0)
		cub->rays->tex_x = tex->tex_width - cub->rays->tex_x - 1;
	if (cub->rays->side == 1 && cub->rays->ray_dir_y > 0)
		cub->rays->tex_x = tex->tex_width - cub->rays->tex_x - 1;
}

void	draw(t_cub *cub, t_texture *tex, int x)
{
	double	step;
	double	tex_pos;
	int		y;

	y = cub->rays->draw_start;
	step = 1.0 * tex->tex_height / cub->rays->line_height;
	tex_pos = (cub->rays->draw_start - WIN_HEIGHT / 2
			+ cub->rays->line_height / 2) * step;
	helper(cub, tex);
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
	draw_floor_ceil(cub, x, cub->clr_c, cub->clr_f);
}
