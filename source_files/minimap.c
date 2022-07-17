/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 04:12:55 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/17 04:12:56 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	draw_square2(t_cub *cub, int x, int y, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i++ < SCALE)
	{
		j = 0;
		while (j++ < SCALE)
			my_put_pixel(cub, x + i, y + j, color);
	}
}

void	draw_square(t_cub *cub, int x, int y, char ch)
{
	int	color;

	if ((int)cub->person->pos_x == x && (int)cub->person->pos_y == y)
		color = 0x000000FF;
	else if ('1' == ch)
		color = 0x00FF0000;
	else if ('0' == ch)
		color = 0x00555555;
	else if ('D' == ch)
		color = 0x00FFFF00;
	else
		return ;
	draw_square2(cub, (y - (cub->person->pos_y - cub->default_y)) * SCALE,
		(x - (cub->person->pos_x - cub->default_x)) * SCALE, color);
}

void	draw_minimap(t_cub *cub, int i, int j)
{
	int		dif_x;
	int		dif_y;
	int		x;
	int		y;

	cub->default_x = 10;
	cub->default_y = 10;
	x = cub->person->pos_x;
	y = cub->person->pos_y;
	dif_x = abs(x + i);
	while (dif_x <= (10 + x))
	{
		j = -10;
		dif_y = abs(y + j);
		while (dif_y <= (10 + y))
		{
			if (cub->map[dif_x] && dif_x <= cub->str_in_map
				&& (int)(ft_strlen(cub->map[dif_x])) >= dif_y)
				draw_square(cub, dif_x, dif_y, cub->map[dif_x][dif_y]);
			dif_y = abs(y + (++j));
		}
		dif_x = abs(x + (++i));
	}
}
