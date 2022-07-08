/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:09:40 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/08 15:33:40 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	raycasting(t_cub *cub)
{
	int	x;

	while (1)
	{
		x = 0;
		while (x < cub->map_width)
		{
			cub->rays->camera_x = 2 * x / (double)cub->map_width - 1;
			cub->rays->ray_dir_x = cub->rays->dir_x
				+ cub->rays->plane_x * cub->rays->camera_x;
			cub->rays->ray_dir_y = cub->rays->dir_y
				+ cub->rays->plane_y * cub->rays->camera_x;
			
			x++;
		}
	}
}
