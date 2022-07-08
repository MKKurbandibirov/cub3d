/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:26:17 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/08 15:30:14 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

/* Chanege after parsing */
static void	fill_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->map_length)
	{
		j = 0;
		while (j < cub->map_width)
		{
			if (i == 0 || i == cub->map_length - 1
				|| j == 0 || j == cub->map_width - 1)
				cub->map[i][j] = WALL;
			else
				cub->map[i][j] = FLOOR;
			j++;
		}
		i++;
	}
}

static int	**get_map(int length, int width)
{
	int	**map;
	int	i;

	map = (int **)malloc(sizeof(int *) * length);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		map[i] = (int *)malloc(sizeof(int) * width);
		if (map[i] == NULL)
		{
			map_free(map, i);
			return (NULL);
		}
		i++;
	}
	return (map);
}

t_rays	*rays_init(t_cub *cub)
{
	t_rays	*rays;

	rays = (t_rays *)malloc(sizeof(t_rays));
	if (rays == NULL)
		return (NULL);
	rays->pos_x = 50; /*Change after parsing*/
	rays->pos_y = 50; /*Change after parsing*/
	rays->dir_x = -1;
	rays->dir_y = 0;
	rays->plane_x = 0;
	rays->plane_y = 0.66;
	rays->camera_x = 0;
	rays->ray_dir_x = 0;
	rays->ray_dir_y = 0;
}

t_cub	*cub_init(char *map_path)
{
	t_cub	*cub;

	cub = (t_cub *)malloc(sizeof(t_cub));
	if (cub == NULL)
		return (NULL);
	cub->mlx_ptr = mlx_init();
	if (cub->mlx_ptr == NULL)
		return (NULL);
	cub->mlx_win = mlx_new_window(cub->mlx_ptr,
			WIN_LENGTH, WIN_WIDTH, "CUB_3D");
	if (cub->mlx_win == NULL)
		return (NULL);
	cub->map_length = 100; /*Change after parsing*/
	cub->map_width = 100; /*Change after parsing*/
	cub->map = get_map(cub->map_length, cub->map_width);
	if (cub->map == NULL)
		return (NULL);
	cub->map_path = map_path;
	fill_map(cub);
	cub->rays = rays_init(cub);
	return (cub);
}
