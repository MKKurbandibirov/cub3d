/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:55:46 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/15 15:45:58 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static void	rotate_left(t_cub *cub)
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

static void	rotate_right(t_cub *cub)
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
	if (x >= 2459 || x <= -99)
		mlx_mouse_move(cub->mlx->win_ptr, WIN_HEIGHT / 2, WIN_WIDTH / 2);
	if (abs(x - cub->person->mouse_x) > 5)
	{
		if (x - cub->person->mouse_x > 0)
			rotate_right(cub);
		else
			rotate_left(cub);
		cub->person->mouse_x = x;
	}
	return (0);
}
