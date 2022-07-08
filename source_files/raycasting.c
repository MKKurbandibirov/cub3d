/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:09:40 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/08 17:35:40 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static void	inter_init(t_cub *cub, int x)
{
	cub->rays->camera_x = 2 * x / (double)cub->map_width - 1;
	cub->rays->ray_dir_x = cub->rays->dir_x
		+ cub->rays->plane_x * cub->rays->camera_x;
	cub->rays->ray_dir_y = cub->rays->dir_y
		+ cub->rays->plane_y * cub->rays->camera_x;
	cub->rays->map_x = (int)cub->rays->pos_x;
	cub->rays->map_y = (int)cub->rays->pos_y;
	if (cub->rays->ray_dir_x == 0)
		cub->rays->delta_dist_x = 1e30;
	else
		cub->rays->delta_dist_x = abs(1 / cub->rays->ray_dir_x);
	if (cub->rays->ray_dir_y == 0)
		cub->rays->delta_dist_y = 1e30;
	else
		cub->rays->delta_dist_y = abs(1 / cub->rays->ray_dir_y);
	cub->rays->hit = 0;
}

static void	choose_distance(t_cub *cub)
{
	if (cub->rays->ray_dir_x < 0)
	{
		cub->rays->step_x = -1;
		cub->rays->side_dist_x = (cub->rays->pos_x - cub->rays->map_x)
			* cub->rays->delta_dist_x;
	}
	else
	{
		cub->rays->step_x = 1;
		cub->rays->side_dist_x = cub->rays->delta_dist_x
			* (cub->rays->map_x + 1.0 - cub->rays->pos_x);
	}
	if (cub->rays->ray_dir_y < 0)
	{
		cub->rays->step_y = -1;
		cub->rays->side_dist_y = (cub->rays->pos_y - cub->rays->map_y)
			* cub->rays->delta_dist_y;
	}
	else
	{
		cub->rays->step_y = 1;
		cub->rays->side_dist_y = cub->rays->delta_dist_y
			* (cub->rays->map_y + 1.0 - cub->rays->pos_y);
	}
}

static void	dda_alg(t_cub *cub)
{
	while (cub->rays->hit == 0)
	{
		if (cub->rays->side_dist_x < cub->rays->side_dist_y)
		{
			cub->rays->side_dist_x += cub->rays->delta_dist_x;
			cub->rays->map_x += cub->rays->step_x;
			cub->rays->side = 0;
		}
		else
		{
			cub->rays->side_dist_y += cub->rays->delta_dist_y;
			cub->rays->map_y += cub->rays->step_y;
			cub->rays->side = 1;
		}
		if (cub->map[cub->rays->map_x][cub->rays->map_y] > 0)
			cub->rays->hit = 1;
	}
	if (cub->rays->side == 0)
		cub->rays->perp_wall_dist = cub->rays->side_dist_x
			- cub->rays->delta_dist_x;
	else
		cub->rays->perp_wall_dist = cub->rays->side_dist_y
			- cub->rays->side_dist_y;
}

void	raycasting(t_cub *cub)
{
	int	x;

	while (1)
	{
		x = 0;
		while (x < cub->map_width)
		{
			inter_init(cub, x);
			choose_distance(cub);
			dda_alg(cub);
			cub->rays->line_height = cub->map_height
				/ cub->rays->perp_wall_dist;
			cub->rays->draw_start = -cub->rays->line_height
				/ 2 + cub->map_height / 2;
			if (cub->rays->draw_start < 0)
				cub->rays->draw_start = 0;
			cub->rays->draw_end = cub->rays->line_height
				/ 2 + cub->map_height / 2;
			if (cub->rays->draw_end >= cub->map_height)
				cub->rays->draw_end = cub->map_height - 1;
			x++;
		}
	}
}
