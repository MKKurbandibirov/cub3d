/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_computation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:44:33 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/15 15:17:20 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	direction_computation(t_cub *cub, int x)
{
	cub->person->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	cub->rays->ray_dir_x = cub->person->dir_x
		+ cub->person->plane_x * cub->person->camera_x;
	cub->rays->ray_dir_y = cub->person->dir_y
		+ cub->person->plane_y * cub->person->camera_x;
	cub->rays->map_x = (int)cub->person->pos_x;
	cub->rays->map_y = (int)cub->person->pos_y;
	cub->rays->delta_dist_x = fabs(1 / cub->rays->ray_dir_x);
	cub->rays->delta_dist_y = fabs(1 / cub->rays->ray_dir_y);
	cub->rays->hit = 0;
}

void	distance_computation(t_cub *cub)
{
	if (cub->rays->ray_dir_x < 0)
	{
		cub->rays->step_x = -1;
		cub->rays->side_dist_x = (cub->person->pos_x - cub->rays->map_x)
			* cub->rays->delta_dist_x;
	}
	else
	{
		cub->rays->step_x = 1;
		cub->rays->side_dist_x = cub->rays->delta_dist_x
			* (cub->rays->map_x + 1.0 - cub->person->pos_x);
	}
	if (cub->rays->ray_dir_y < 0)
	{
		cub->rays->step_y = -1;
		cub->rays->side_dist_y = (cub->person->pos_y - cub->rays->map_y)
			* cub->rays->delta_dist_y;
	}
	else
	{
		cub->rays->step_y = 1;
		cub->rays->side_dist_y = cub->rays->delta_dist_y
			* (cub->rays->map_y + 1.0 - cub->person->pos_y);
	}
}

void	dda_computation(t_cub *cub)
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
		if (cub->map[cub->rays->map_x][cub->rays->map_y] != '0')
			cub->rays->hit = 1;
	}
	if (cub->rays->side == 0)
		cub->rays->perp_wall_dist = cub->rays->side_dist_x
			- cub->rays->delta_dist_x;
	else
		cub->rays->perp_wall_dist = cub->rays->side_dist_y
			- cub->rays->delta_dist_y;
}

void	tex_computation(t_cub *cub)
{
	if (cub->rays->side == 0)
		cub->rays->wall_x = cub->person->pos_y
			+ cub->rays->perp_wall_dist * cub->rays->ray_dir_y;
	else
		cub->rays->wall_x = cub->person->pos_x
			+ cub->rays->perp_wall_dist * cub->rays->ray_dir_x;
	cub->rays->wall_x -= floor(cub->rays->wall_x);
	cub->rays->line_height = WIN_HEIGHT / cub->rays->perp_wall_dist;
	cub->rays->draw_start = -cub->rays->line_height / 2 + WIN_HEIGHT / 2;
	if (cub->rays->draw_start < 0)
		cub->rays->draw_start = 0;
	cub->rays->draw_end = cub->rays->line_height / 2 + WIN_HEIGHT / 2;
	if (cub->rays->draw_end >= WIN_HEIGHT)
		cub->rays->draw_end = WIN_HEIGHT - 1;
}
