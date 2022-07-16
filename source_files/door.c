/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:16:07 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/15 14:47:50 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	door_open(t_cub *cub, int keycode)
{
	int	i;
	int	diff_x;
	int	diff_y;

	i = 0;
	if (keycode == 49)
	{
		while (i < cub->cnt_door)
		{
			diff_x = abs((int)cub->person->pos_x - cub->doors_pos[i][0]);
			diff_y = abs((int)cub->person->pos_y - cub->doors_pos[i][1]);
			if (diff_x <= 2 && diff_y <= 2
				&& cub->map[cub->doors_pos[i][0]][cub->doors_pos[i][1]] != '0')
			{
				cub->map[cub->doors_pos[i][0]][cub->doors_pos[i][1]] = '0';
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	door_close(t_cub *cub, int keycode)
{
	int	i;
	int	diff_x;
	int	diff_y;

	i = 0;
	if (keycode == 49)
	{
		while (i < cub->cnt_door)
		{
			diff_x = abs((int)cub->person->pos_x - cub->doors_pos[i][0]);
			diff_y = abs((int)cub->person->pos_y - cub->doors_pos[i][1]);
			if (diff_x <= 2 && diff_y <= 2
				&& cub->map[cub->doors_pos[i][0]][cub->doors_pos[i][1]] == '0')
			{
				cub->map[cub->doors_pos[i][0]][cub->doors_pos[i][1]] = DOOR;
				return (1);
			}
			i++;
		}
	}
	return (0);
}
