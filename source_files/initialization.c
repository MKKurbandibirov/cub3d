/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:26:17 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/14 16:48:41 by nfarfetc         ###   ########.fr       */
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
			else if (i == 10 && j == 10)
				cub->map[i][j] = WALL;
			else
				cub->map[i][j] = FLOOR;
			j++;
		}
		i++;
	}
}

static char	**get_map(int length, int width)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * length);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		map[i] = (char *)malloc(sizeof(char) * width);
		if (map[i] == NULL)
		{
			map_free(map, i);
			return (NULL);
		}
		i++;
	}
	return (map);
}

t_sprite	**set_sprites(t_cub *cub)
{
	t_sprite	**sprite;

	sprite = (t_sprite **)malloc(sizeof(t_sprite *) * 12);
	if (sprite == NULL)
		return (NULL);
	sprite[0] = sprite_init("textures/1.xpm", cub); /*Change after parsing*/
	sprite[1] = sprite_init("textures/2.xpm", cub);
	sprite[2] = sprite_init("textures/3.xpm", cub);
	sprite[3] = sprite_init("textures/4.xpm", cub);
	sprite[4] = sprite_init("textures/5.xpm", cub);
	sprite[5] = sprite_init("textures/6.xpm", cub);
	sprite[6] = sprite_init("textures/7.xpm", cub);
	sprite[7] = sprite_init("textures/8.xpm", cub);
	sprite[8] = sprite_init("textures/8.xpm", cub);
	sprite[9] = sprite_init("textures/12.xpm", cub);
	sprite[10] = sprite_init("textures/11.xpm", cub);
	sprite[11]= NULL;
	return (sprite);
}

t_cub	*cub_init(char *map_path)
{
	t_cub	*cub;

	cub = (t_cub *)malloc(sizeof(t_cub));
	if (cub == NULL)
		return (NULL);
	cub->curr_spr = 0;
	cub->start = clock();
	cub->map_height = 50; /*Change after parsing*/
	cub->map_width = 50; /*Change after parsing*/
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
	cub->sprite = set_sprites(cub);
	if (cub->sprite == NULL)
		return (NULL);
	cub->person = person_init();
	if (set_textures(cub) == NULL || cub->person == NULL)
		return (NULL);
	return (cub);
}
