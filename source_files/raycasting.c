/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:09:40 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/10 15:10:36 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	draw(t_cub *cub, t_texture *tex, int x)
{
	int		r;
	int		g;
	int		b;
	double	step;
	double	tex_pos;

	step = 1.0 * TEX_HEIGHT / cub->rays->line_height;
	tex_pos = (cub->rays->draw_start - WIN_HEIGHT / 2
			+ cub->rays->line_height / 2) * step;
	while (cub->rays->draw_start++ < cub->rays->draw_end)
	{
		cub->rays->tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		r = (unsigned int)tex->addr[cub->rays->tex_y * tex->line_lenght
			+ cub->rays->tex_x * tex->bits_per_pixel / 8];
		g = (unsigned int)tex->addr[cub->rays->tex_y * tex->line_lenght
			+ cub->rays->tex_x * tex->bits_per_pixel / 8 + 1];
		b = (unsigned int)tex->addr[cub->rays->tex_y * tex->line_lenght
			+ cub->rays->tex_x * tex->bits_per_pixel / 8 + 2];
		my_put_pixel(cub, x, cub->rays->draw_start, (r << 16 | g << 8 | b));
	}
}

void	raycasting(t_cub *cub)
{
	int	x;

	while (1)
	{
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
			
			x++;
		}
	}
}
