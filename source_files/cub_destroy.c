/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:42:36 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/07 16:57:15 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	map_free(int **map, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	cub_destroy(t_cub *cub)
{
	mlx_destroy_window(cub->mlx_ptr, cub->mlx_win);
	map_free(cub->map, cub->map_length);
	free(cub);
}
