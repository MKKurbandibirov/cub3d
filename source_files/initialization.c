/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:26:17 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/15 14:43:35 by nfarfetc         ###   ########.fr       */
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
			else if (i == 15 && j != 25 && j != 20)
				cub->map[i][j] = WALL;
			else if (i == 15 && j == 25)
				cub->map[i][j] = DOOR;
			else if (i == 15 && j == 20)
				cub->map[i][j] = DOOR;
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

	map = (char **)malloc(sizeof(char *) * (length + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		map[i] = (char *)malloc(sizeof(char) * width);
		if (map[i] == NULL)
		{
			free_split(map);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
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

// int	**door_pos_init()

t_cub	*cub_init(void)
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
	fill_map(cub); /*Change after parsing*/
	cub->mlx = t_mlx_init();
	if (cub->mlx == NULL)
		return (NULL);
	cub->rays = (t_rays *)malloc(sizeof(t_rays));
	if (cub->rays == NULL)
		return (NULL);
	cub->sprite = NULL;
	cub->sprite = set_sprites(cub);
	if (cub->sprite == NULL)
		return (NULL);
	cub->person = person_init(EAST);
	if (set_textures(cub) == NULL || cub->person == NULL)
		return (NULL);
	/* Change after parsing */
	cub->doors_pos = malloc(sizeof(int *) * 2);
	cub->doors_pos[0] = malloc(sizeof(int) * 2);
	cub->doors_pos[0][0] = 15;
	cub->doors_pos[0][1] = 25;
	cub->doors_pos[1] = malloc(sizeof(int) * 2);
	cub->doors_pos[1][0] = 15;
	cub->doors_pos[1][1] = 20;
	return (cub);
}
