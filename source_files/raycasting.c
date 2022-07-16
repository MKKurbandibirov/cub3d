/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:20:04 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/16 20:19:55 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static void	set_south(t_cub *cub, int x)
{
	if (cub->map[cub->rays->map_x][cub->rays->map_y] == DOOR)
		draw(cub, cub->door, x);
	else
		draw(cub, cub->so_tex, x);
}

static void	set_north(t_cub *cub, int x)
{
	if (cub->map[cub->rays->map_x][cub->rays->map_y] == DOOR)
		draw(cub, cub->door, x);
	else
		draw(cub, cub->no_tex, x);
}

static void	set_east(t_cub *cub, int x)
{
	if (cub->map[cub->rays->map_x][cub->rays->map_y] == DOOR)
		draw(cub, cub->door, x);
	else
		draw(cub, cub->ea_tex, x);
}

static void	set_west(t_cub *cub, int x)
{
	if (cub->map[cub->rays->map_x][cub->rays->map_y] == DOOR)
		draw(cub, cub->door, x);
	else
		draw(cub, cub->we_tex, x);
}

void	raycasting(t_cub *cub, int i)
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
			set_south(cub, x);
		else if (cub->rays->side == 0 && cub->rays->ray_dir_x < 0)
			set_north(cub, x);
		else if (cub->rays->side == 1 && cub->rays->ray_dir_y > 0)
			set_east(cub, x);
		else if (cub->rays->side == 1 && cub->rays->ray_dir_y < 0)
			set_west(cub, x);
		if (i != -1)
			cub->sprite[i]->z_buff[x] = cub->rays->perp_wall_dist;
		x++;
	}
}
