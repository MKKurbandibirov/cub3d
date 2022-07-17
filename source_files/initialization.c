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

t_sprite	**set_sprites(t_cub *cub)
{
	int			i;
	t_sprite	**sprite;

	if (cub->cnt_texture_sp == 0)
		return (NULL);
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
	cub->mlx = t_mlx_init();
	if (cub->mlx == NULL)
		return (NULL);
	if (cub->cnt_texture_sp > 0)
		cub->curr_spr = 0;
	else
		cub->curr_spr = -1;
	cub->start = clock();
	cub->rays = (t_rays *)malloc(sizeof(t_rays));
	if (cub->rays == NULL)
		return (NULL);
	cub->sprite = NULL;
	cub->sprite = set_sprites(cub);
	if (cub->cnt_texture_sp > 0 && cub->sprite == NULL)
		return (NULL);
	cub->person = person_init(cub->direction, cub->user_pos_x, cub->user_pos_y);
	if (set_textures(cub) == NULL || cub->person == NULL)
		return (NULL);
	return (cub);
}
