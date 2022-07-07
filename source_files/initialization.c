/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:26:17 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/07 16:54:27 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

/* Chanege after parsing*/
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
			if (i == 0 || i == cub->map_length - 1 || j == 0 || j == cub->map_width - 1)
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

t_cub	*cub_init(void)
{
	t_cub	*cub;

	cub = (t_cub *)malloc(sizeof(t_cub));
	if (cub == NULL)
		return (NULL);
	cub->mlx_ptr = mlx_init();
	if (cub->mlx_ptr == NULL)
		return (NULL);
	cub->mlx_win = mlx_new_window(cub->mlx_ptr, 1920, 1080, "CUB_3D");
	if (cub->mlx_win == NULL)
		return (NULL);
	cub->map_length = 100; /*Change after parsing*/
	cub->map_width = 100; /*Change after parsing*/
	cub->map = get_map(cub->map_length, cub->map_width);
	if (cub->map == NULL)
		return (NULL);
	fill_map(cub);
	return (cub);
}
