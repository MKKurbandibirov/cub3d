/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:42:36 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/08 17:07:03 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	map_free(int **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	cub_destroy(t_cub *cub)
{
	mlx_destroy_window(cub->mlx_ptr, cub->mlx_win);
	map_free(cub->map, cub->map_height);
	free(cub);
}
