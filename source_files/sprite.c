/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:26:41 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/15 15:07:05 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	size_computation(t_cub *cub, int i)
{
	cub->sprite[i]->draw_start_y = -cub->sprite[i]->sprite_height / 2
		+ WIN_HEIGHT / 2;
	if (cub->sprite[i]->draw_start_y < 0)
		cub->sprite[i]->draw_start_y = 0;
	cub->sprite[i]->draw_end_y = cub->sprite[i]->sprite_height
		/ 2 + WIN_HEIGHT / 2;
	if (cub->sprite[i]->draw_end_y >= WIN_HEIGHT)
		cub->sprite[i]->draw_end_y = WIN_HEIGHT - 1;
	cub->sprite[i]->draw_start_x = -cub->sprite[i]->sprite_width / 2
		+ cub->sprite[i]->sprite_screen_x;
	if (cub->sprite[i]->draw_start_x < 0)
		cub->sprite[i]->draw_start_x = 0;
	cub->sprite[i]->draw_end_x = cub->sprite[i]->sprite_width / 2
		+ cub->sprite[i]->sprite_screen_x;
	if (cub->sprite[i]->draw_end_x >= WIN_WIDTH)
		cub->sprite[i]->draw_end_x = WIN_WIDTH - 1;
}

void	draw_sprite_stripe(t_cub *cub, int i, int stripe)
{
	int	y;
	int	d;
	int	color;

	if (cub->sprite[i]->transform_y > 0 && stripe > 0 && stripe < WIN_WIDTH
		&& cub->sprite[i]->transform_y < cub->sprite[i]->z_buff[stripe])
	{
		y = cub->sprite[i]->draw_start_y;
		while (y < cub->sprite[i]->draw_end_y)
		{
			d = y * 256 - WIN_HEIGHT * 128
				+ cub->sprite[i]->sprite_height * 128;
			cub->sprite[i]->tex_y = (d * cub->sprite[i]->height
					/ cub->sprite[i]->sprite_height) / 256;
			color = (0 | ((uint16_t)cub->sprite[i]->addr[cub->sprite[i]->tex_y
						* cub->sprite[i]->line_length + cub->sprite[i]->tex_x
						* cub->sprite[i]->bits_per_pixel / 8 + 1]) << 8
					| (uint16_t)cub->sprite[i]->addr[cub->sprite[i]->tex_y
					* cub->sprite[i]->line_length + cub->sprite[i]->tex_x
					* cub->sprite[i]->bits_per_pixel / 8 + 2]);
			if (color != 0x00FFFFFF)
				my_put_pixel(cub, stripe, y, color);
			y++;
		}
	}
}

void	drawing(t_cub *cub, int i)
{
	int	stripe;

	stripe = cub->sprite[i]->draw_start_x;
	while (stripe < cub->sprite[i]->draw_end_x)
	{
		cub->sprite[i]->tex_x = (int)(256 * (stripe
					- (-cub->sprite[i]->sprite_width / 2
						+ cub->sprite[i]->sprite_screen_x))
				* cub->sprite[i]->height / cub->sprite[i]->sprite_width) / 256;
		if (cub->sprite != NULL)
			draw_sprite_stripe(cub, i, stripe);
		stripe++;
	}
}

void	draw_sprite(t_cub *cub, int i)
{
	double	inv_det;

	inv_det = 1.0 / (cub->person->plane_x * cub->person->dir_y
			- cub->person->plane_y * cub->person->dir_x);
	cub->sprite[i]->sprite_x = cub->sprite[i]->pos_x - cub->person->pos_x;
	cub->sprite[i]->sprite_y = cub->sprite[i]->pos_y - cub->person->pos_y;
	cub->sprite[i]->transform_x = inv_det * (cub->person->dir_y
			* cub->sprite[i]->sprite_x - cub->person->dir_x
			* cub->sprite[i]->sprite_y);
	cub->sprite[i]->transform_y = inv_det * (-cub->person->plane_y
			* cub->sprite[i]->sprite_x + cub->person->plane_x
			* cub->sprite[i]->sprite_y);
	cub->sprite[i]->sprite_screen_x = (int)((WIN_WIDTH / 2)
			* (1 + cub->sprite[i]->transform_x / cub->sprite[i]->transform_y));
	cub->sprite[i]->sprite_height = abs((int)(WIN_HEIGHT
				/ cub->sprite[i]->transform_y));
	cub->sprite[i]->sprite_width = abs((int)(WIN_HEIGHT
				/ cub->sprite[i]->transform_y));
	size_computation(cub, i);
	drawing(cub, i);
}
