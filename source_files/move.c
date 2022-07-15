/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:19:58 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/15 14:59:55 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static void	move_forward(t_cub *cub)
{
	if (cub->map[(int)(cub->person->pos_x + cub->person->dir_x
			* MOVESPEED)][(int)cub->person->pos_y] == '0')
		cub->person->pos_x += cub->person->dir_x * MOVESPEED;
	if (cub->map[(int)cub->person->pos_x][(int)(cub->person->pos_y
		+ cub->person->dir_y * MOVESPEED)] == '0')
		cub->person->pos_y += cub->person->dir_y * MOVESPEED;
}

static void	move_backward(t_cub *cub)
{
	if (cub->map[(int)(cub->person->pos_x - cub->person->dir_x
			* MOVESPEED)][(int)cub->person->pos_y] == '0')
		cub->person->pos_x -= cub->person->dir_x * MOVESPEED;
	if (cub->map[(int)cub->person->pos_x][(int)(cub->person->pos_y
		- cub->person->dir_y * MOVESPEED)] == '0')
		cub->person->pos_y -= cub->person->dir_y * MOVESPEED;
}

static void	move_left(t_cub *cub)
{
	if (cub->map[(int)(cub->person->pos_x - cub->person->dir_y
			* MOVESPEED)][(int)cub->person->pos_y] == '0')
		cub->person->pos_x -= (cub->person->dir_y * MOVESPEED);
	if (cub->map[(int)cub->person->pos_x][(int)(cub->person->pos_y
		+ cub->person->dir_x * MOVESPEED)] == '0')
		cub->person->pos_y += cub->person->dir_x * MOVESPEED;
}

static void	move_right(t_cub *cub)
{
	if (cub->map[(int)(cub->person->pos_x + cub->person->dir_y
			* MOVESPEED)][(int)cub->person->pos_y] == '0')
		cub->person->pos_x += (cub->person->dir_y * MOVESPEED);
	if (cub->map[(int)cub->person->pos_x][(int)(cub->person->pos_y
		- cub->person->dir_x * MOVESPEED)] == '0')
		cub->person->pos_y -= cub->person->dir_x * MOVESPEED;
}

void	moving(t_cub *cub, int keycode)
{
	if (keycode == FORWARD)
		move_forward(cub);
	if (keycode == BACKWARD)
		move_backward(cub);
	if (keycode == LEFT)
		move_left(cub);
	if (keycode == RIGHT)
		move_right(cub);
}
