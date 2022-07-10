/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:42:36 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/10 14:38:49 by nfarfetc         ###   ########.fr       */
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

void	free_textures(t_cub *cub)
{
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->no_tex->img_ptr);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->so_tex->img_ptr);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->ea_tex->img_ptr);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->we_tex->img_ptr);
}

void	cub_destroy(t_cub *cub)
{
	free(cub->person);
	free(cub->rays);
	free_textures(cub);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->mlx->img_ptr);
	mlx_destroy_window(cub->mlx->mlx_ptr, cub->mlx->win_ptr);
	free(cub->mlx);
	map_free(cub->map, cub->map_height);
	free(cub);
}
