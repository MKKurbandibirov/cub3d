/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:26:17 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/10 14:38:15 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

/* Change after parsing */
static void	fill_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < cub->map_width)
		{
			if (i == 0 || i == cub->map_height - 1
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

t_cub	*cub_init(char *map_path)
{
	t_cub	*cub;

	cub = (t_cub *)malloc(sizeof(t_cub));
	if (cub == NULL)
		return (NULL);
	cub->map_height = 100; /*Change after parsing*/
	cub->map_width = 100; /*Change after parsing*/
	cub->map = get_map(cub->map_height, cub->map_width);
	if (cub->map == NULL)
		return (NULL);
	cub->map_path = map_path;
	fill_map(cub); /*Change after parsing*/
	cub->mlx = t_mlx_init();
	if (cub->mlx == NULL)
		return (NULL);
	cub->rays = (t_rays *)malloc(sizeof(t_rays));
	if (cub->rays == NULL)
		return (NULL);
	cub->person = person_init();
	if (cub->person == NULL)
		return (NULL);
	if (set_textures(cub) == NULL)
		return (NULL);
	return (cub);
}
