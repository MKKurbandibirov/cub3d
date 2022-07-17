/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:42:36 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/17 10:36:12 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	free_textures(t_cub *cub)
{
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->no_tex->img_ptr);
	free(cub->no_tex);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->so_tex->img_ptr);
	free(cub->so_tex);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->ea_tex->img_ptr);
	free(cub->ea_tex);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->we_tex->img_ptr);
	free(cub->we_tex);
	if (cub->cnt_door > 0)
	{
		mlx_destroy_image(cub->mlx->mlx_ptr, cub->door->img_ptr);
		free(cub->door);
	}
}

void	free_sprites(t_cub *cub)
{
	int	i;

	if (cub->sprite != NULL)
	{
		i = 0;
		while (i < cub->cnt_texture_sp)
		{
			mlx_destroy_image(cub->mlx->mlx_ptr, cub->sprite[i]->img_ptr);
			free(cub->sprite[i]);
			i++;
		}
		free(cub->sprite);
	}
}

void	cub_destroy(t_cub *cub)
{
	int	i;

	free(cub->person);
	free(cub->rays);
	free_split(cub->map);
	if (cub->cnt_door > 0)
	{
		i = 0;
		while (i < cub->cnt_door)
		{
			free(cub->doors_pos[i]);
			i++;
		}
		free(cub->doors_pos);
	}
	free_split(cub->wall_texture_path);
	free_textures(cub);
	free_sprites(cub);
	free_split(cub->sprite_texture);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->mlx->img_ptr);
	mlx_destroy_window(cub->mlx->mlx_ptr, cub->mlx->win_ptr);
	free(cub->mlx);
	free(cub);
}
