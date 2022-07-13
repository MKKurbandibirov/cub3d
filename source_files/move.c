/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:19:58 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/13 15:36:57 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	moving(t_cub *cub, int keycode)
{
	if (keycode == FORWARD)
	{
		if (cub->map[(int)(cub->person->pos_x + cub->person->dir_x
				* MOVESPEED)][(int)cub->person->pos_y] == 0)
			cub->person->pos_x += cub->person->dir_x * MOVESPEED;
		if (cub->map[(int)cub->person->pos_x][(int)(cub->person->pos_y
			+ cub->person->dir_y * MOVESPEED)] == 0)
			cub->person->pos_y += cub->person->dir_y * MOVESPEED;
	}
	if (keycode == BACKWARD)
	{
		if (cub->map[(int)(cub->person->pos_x - cub->person->dir_x
				* MOVESPEED)][(int)cub->person->pos_y] == 0)
			cub->person->pos_x -= cub->person->dir_x * MOVESPEED;
		if (cub->map[(int)cub->person->pos_x][(int)(cub->person->pos_y
			- cub->person->dir_y * MOVESPEED)] == 0)
			cub->person->pos_y -= cub->person->dir_y * MOVESPEED;
	}
	if (keycode == RIGHT)
	{
		if (cub->map[(int)(cub->person->pos_x + sin(cub->person->dir_x)
				* MOVESPEED)][(int)cub->person->pos_y] == 0)
			cub->person->pos_x += sin(cub->person->dir_x) * MOVESPEED;
		if (cub->map[(int)cub->person->pos_x][(int)(cub->person->pos_y
			+ sin(cub->person->dir_y) * MOVESPEED)] == 0)
			cub->person->pos_y += cos(cub->person->dir_y) * MOVESPEED;
	}
	if (keycode == LEFT)
	{
		if (cub->map[(int)(cub->person->pos_x - cos(cub->person->dir_x)
				* MOVESPEED)][(int)cub->person->pos_y] == 0)
			cub->person->pos_x -= cos(cub->person->dir_x) * MOVESPEED;
		if (cub->map[(int)cub->person->pos_x][(int)(cub->person->pos_y
			- sin(cub->person->dir_y) * MOVESPEED)] == 0)
			cub->person->pos_y -= sin(cub->person->dir_y) * MOVESPEED;
	}
}

void	rotate_left(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->person->dir_x;
	old_plane_x = cub->person->plane_x;
	cub->person->dir_x = cub->person->dir_x * cos(ROTATESPEED)
		- cub->person->dir_y * sin(ROTATESPEED);
	cub->person->dir_y = old_dir_x * sin(ROTATESPEED)
		+ cub->person->dir_y * cos(ROTATESPEED);
	cub->person->plane_x = cub->person->plane_x * cos(ROTATESPEED)
		- cub->person->plane_y * sin(ROTATESPEED);
	cub->person->plane_y = old_plane_x * sin(ROTATESPEED)
		+ cub->person->plane_y * cos(ROTATESPEED);
}

void	rotate_right(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->person->dir_x;
	old_plane_x = cub->person->plane_x;
	cub->person->dir_x = cub->person->dir_x * cos(-ROTATESPEED)
		- cub->person->dir_y * sin(-ROTATESPEED);
	cub->person->dir_y = old_dir_x * sin(-ROTATESPEED)
		+ cub->person->dir_y * cos(-ROTATESPEED);
	cub->person->plane_x = cub->person->plane_x * cos(-ROTATESPEED)
		- cub->person->plane_y * sin(-ROTATESPEED);
	cub->person->plane_y = old_plane_x * sin(-ROTATESPEED)
		+ cub->person->plane_y * cos(-ROTATESPEED);
}

void	rotating(t_cub *cub, int keycode)
{
	if (keycode == ROTATE_R)
		rotate_right(cub);
	if (keycode == ROTATE_L)
		rotate_left(cub);
}

int	mouse_rotate(int x, int y, t_cub *cub)
{
	(void)y;
	if (x > 0 && x < WIN_WIDTH && abs(x - cub->person->mouse_x) > 5)
	{
		if (x - cub->person->mouse_x > 0)
			rotate_right(cub);
		else
			rotate_left(cub);
		cub->person->mouse_x = x;
	}
	return (0);
}
