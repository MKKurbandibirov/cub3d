/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:30:29 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/17 09:56:56 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

t_texture	*texture_init(char *path, t_mlx *mlx)
{
	t_texture	*tex;

	tex = (t_texture *)malloc(sizeof(t_texture));
	if (tex == NULL)
		return (NULL);
	tex->path = path;
	tex->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			tex->path, &tex->tex_width, &tex->tex_height);
	if (tex->img_ptr == NULL)
		return (NULL);
	tex->addr = mlx_get_data_addr(tex->img_ptr,
			&tex->bits_per_pixel, &tex->line_length, &tex->endian);
	if (tex->addr == NULL)
		return (NULL);
	return (tex);
}

t_mlx	*t_mlx_init(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (mlx == NULL)
		return (NULL);
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (NULL);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "CUB_3D");
	if (mlx->win_ptr == NULL)
		return (NULL);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->img_ptr == NULL)
		return (NULL);
	mlx->addr = mlx_get_data_addr(mlx->img_ptr,
			&mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
	if (mlx->addr == NULL)
		return (NULL);
	return (mlx);
}

t_sprite	*sprite_init(char *path, t_cub *cub)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (sprite == NULL)
		return (NULL);
	sprite->path = path;
	sprite->pos_x = cub->sprite_pos_x;
	sprite->pos_y = cub->sprite_pos_y;
	sprite->img_ptr = mlx_xpm_file_to_image(cub->mlx->mlx_ptr,
			path, &sprite->width, &sprite->height);
	if (sprite->img_ptr == NULL)
		return (NULL);
	sprite->addr = mlx_get_data_addr(sprite->img_ptr, &sprite->bits_per_pixel,
			&sprite->line_length, &sprite->endian);
	if (sprite->addr == NULL)
		return (NULL);
	return (sprite);
}

void	*set_textures(t_cub *cub)
{
	cub->no_tex = texture_init(cub->wall_texture_path[0], cub->mlx);
	if (cub->no_tex == NULL)
		return (NULL);
	cub->so_tex = texture_init(cub->wall_texture_path[1], cub->mlx);
	if (cub->so_tex == NULL)
		return (NULL);
	cub->ea_tex = texture_init(cub->wall_texture_path[2], cub->mlx);
	if (cub->ea_tex == NULL)
		return (NULL);
	cub->we_tex = texture_init(cub->wall_texture_path[3], cub->mlx);
	if (cub->we_tex == NULL)
		return (NULL);
	if (cub->cnt_door > 0)
	{
		cub->door = texture_init(cub->wall_texture_path[4], cub->mlx);
		if (cub->door == NULL)
			return (NULL);
	}
	return (cub);
}
