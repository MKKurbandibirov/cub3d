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

// /* Change after parsing */
// static void	fill_map(t_cub *cub)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < cub->map_height)
// 	{
// 		j = 0;
// 		while (j < cub->map_width)
// 		{
// 			if (i == 0 || i == cub->map_height - 1
// 				|| j == 0 || j == cub->map_width - 1)
// 				cub->map[i][j] = WALL;
// 			else if (i == 15 && j != 25 && j != 20)
// 				cub->map[i][j] = WALL;
// 			else if (i == 15 && j == 25)
// 				cub->map[i][j] = DOOR;
// 			else if (i == 15 && j == 20)
// 				cub->map[i][j] = DOOR;
// 			else
// 				cub->map[i][j] = FLOOR;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// static char	**get_map(int length, int width)
// {
// 	char	**map;
// 	int		i;

// 	map = (char **)malloc(sizeof(char *) * (length + 1));
// 	if (map == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < length)
// 	{
// 		map[i] = (char *)malloc(sizeof(char) * width);
// 		if (map[i] == NULL)
// 		{
// 			free_split(map);
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	map[i] = NULL;
// 	return (map);
// }

t_sprite	**set_sprites(t_cub *cub)
{
	int			i;
	t_sprite	**sprite;

	sprite = (t_sprite **)malloc(sizeof(t_sprite *) * cub->cnt_texture_sp);
	if (sprite == NULL)
		return (NULL);
	i = -1;
	while (cub->sprite_texture[++i])
		sprite[i] = sprite_init(cub->sprite_texture[i], cub);
	sprite[i] = NULL;
	return (sprite);
}

t_cub	*cub_init(char *argv)
{
	t_cub	*cub;

	cub = (t_cub *)malloc(sizeof(t_cub));
	if (cub == NULL)
		return (NULL);
	ft_parser(argv, cub);
	if (cub->cnt_texture_sp > 0)
		cub->curr_spr = 0;
	else
		cub->curr_spr = -1;
	cub->start = clock();
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
	cub->person = person_init(cub->direction);
	if (set_textures(cub) == NULL || cub->person == NULL)
		return (NULL);
	return (cub);
}
