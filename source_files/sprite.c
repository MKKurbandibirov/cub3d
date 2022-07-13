/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:26:41 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/13 18:23:47 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	size_computation(t_cub *cub)
{
	cub->sprite->draw_start_y = -cub->sprite->sprite_height / 2
		+ WIN_HEIGHT / 2;
	if (cub->sprite->draw_start_y < 0)
		cub->sprite->draw_start_y = 0;
	cub->sprite->draw_end_y = cub->sprite->sprite_height / 2 + WIN_HEIGHT / 2;
	if (cub->sprite->draw_end_y >= WIN_HEIGHT)
		cub->sprite->draw_end_y = WIN_HEIGHT - 1;
	cub->sprite->draw_start_x = -cub->sprite->sprite_width / 2
		+ cub->sprite->sprite_screen_x;
	if (cub->sprite->draw_start_x < 0)
		cub->sprite->draw_start_x = 0;
	cub->sprite->draw_end_x = cub->sprite->sprite_width / 2
		+ cub->sprite->sprite_screen_x;
	if (cub->sprite->draw_end_x >= WIN_WIDTH)
		cub->sprite->draw_end_x = WIN_WIDTH - 1;
}

void	drawing(t_cub *cub)
{
	int	stripe;
	int	y;
	int	d;
	int	color;

	stripe = cub->sprite->draw_start_x;
	// ft_bzero(cub->sprite->addr, TEX_HEIGHT + TEX_WIDTH * cub->sprite->bits_per_pixel / 8);
	while (stripe < cub->sprite->draw_end_x)
	{
		cub->sprite->tex_x = (int)(256 * (stripe - (-cub->sprite->sprite_width
						/ 2 + cub->sprite->sprite_screen_x))
				* cub->sprite->height / cub->sprite->sprite_width) / 256;
		if (cub->sprite->transform_y > 0 && stripe > 0 && stripe < WIN_WIDTH
			&& cub->sprite->transform_y < cub->sprite->z_buff[stripe])
		{
			y = cub->sprite->draw_start_y;
			while (y < cub->sprite->draw_end_y)
			{
				d = y * 256 - WIN_HEIGHT * 128
					+ cub->sprite->sprite_height * 128;
				cub->sprite->tex_y = (d * cub->sprite->height
						/ cub->sprite->sprite_height) / 256;
				color = (((unsigned char)cub->sprite->addr[cub->rays->tex_y * cub->sprite->line_length
							+ cub->sprite->tex_x * cub->sprite->bits_per_pixel / 8]) << 16
						| ((unsigned char)cub->sprite->addr[cub->sprite->tex_y * cub->sprite->line_length
							+ cub->sprite->tex_x * cub->sprite->bits_per_pixel / 8 + 1]) << 8
						| (unsigned char)cub->sprite->addr[cub->sprite->tex_y * cub->sprite->line_length
						+ cub->sprite->tex_x * cub->sprite->bits_per_pixel / 8 + 2]);
				// printf("%d\n", color);
				if ((color & 0x00FFFFFF) != 0)
				{
					// my_put_pixel(cub, stripe, y, 0x00FFFFFF);
					my_put_pixel(cub, stripe, y, color);	
				}
				else
				{
					printf("xaxaxa");
				}
				y++;
			}
		}
		stripe++;
	}
}

void	draw_sprite(t_cub *cub)
{
	double	inv_det;

	inv_det = 1.0 / (cub->person->plane_x * cub->person->dir_y
			- cub->person->plane_y * cub->person->dir_x);
	cub->sprite->sprite_x = cub->sprite->pos_x - cub->person->pos_x;
	cub->sprite->sprite_y = cub->sprite->pos_y - cub->person->pos_y;
	cub->sprite->transform_x = inv_det * (cub->person->dir_y
			* cub->sprite->sprite_x - cub->person->dir_x
			* cub->sprite->sprite_y);
	cub->sprite->transform_y = inv_det * (-cub->person->plane_y
			* cub->sprite->sprite_x + cub->person->plane_x
			* cub->sprite->sprite_y);
	cub->sprite->sprite_screen_x = (int)((WIN_WIDTH / 2)
			* (1 + cub->sprite->transform_x / cub->sprite->transform_y));
	cub->sprite->sprite_height = abs((int)(WIN_HEIGHT
				/ cub->sprite->transform_y));
	cub->sprite->sprite_width = abs((int)(WIN_HEIGHT
				/ cub->sprite->transform_y));
	size_computation(cub);
	drawing(cub);
}
