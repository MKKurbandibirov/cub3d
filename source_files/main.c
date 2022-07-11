/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:19:22 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/11 17:17:51 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	rendering(t_cub *cub)
{
	ft_bzero(cub->mlx->addr, WIN_HEIGHT + WIN_WIDTH * (cub->mlx->bits_per_pixel / 8));
	raycasting(cub);
	mlx_put_image_to_window(cub->mlx->mlx_ptr, cub->mlx->win_ptr, cub->mlx->img_ptr, 0, 0);
	return (0);
}

int	hooking(int keycode, t_cub *cub)
{
	if (keycode == EXIT_KEY)
	{
		cub_destroy(cub);
		exit(EXIT_SUCCESS);
	}
	if (keycode == FORWARD)
	{
		if (cub->map[(int)(cub->person->pos_x + cub->person->dir_x * MOVESPEED)][(int)cub->person->pos_y] == 0)
			cub->person->pos_x += cub->person->dir_x * MOVESPEED;
		if (cub->map[(int)cub->person->pos_x][(int)(cub->person->pos_y + cub->person->dir_y * MOVESPEED)] == 0)
			cub->person->pos_y += cub->person->dir_y * MOVESPEED;
	}
	if (keycode == BACKWARD)
	{
		if (cub->map[(int)(cub->person->pos_x - cub->person->dir_x * MOVESPEED)][(int)cub->person->pos_y] == 0)
			cub->person->pos_x -= cub->person->dir_x * MOVESPEED;
		if (cub->map[(int)cub->person->pos_x][(int)(cub->person->pos_y - cub->person->dir_y * MOVESPEED)] == 0)
			cub->person->pos_y -= cub->person->dir_y * MOVESPEED;
	}
	if (keycode == ROTATE_R)
	{
		double	old_dir_x;
		double	old_plane_x; 

		old_dir_x = cub->person->dir_x;
		old_plane_x = cub->person->plane_x;
		cub->person->dir_x = cub->person->dir_x * cos(-ROTATESPEED) - cub->person->dir_y * sin(-ROTATESPEED);
		cub->person->dir_y = old_dir_x * sin(-ROTATESPEED) + cub->person->dir_y * cos(-ROTATESPEED);
		cub->person->plane_x = cub->person->plane_x * cos(-ROTATESPEED) - cub->person->plane_y * sin(-ROTATESPEED);
		cub->person->plane_y = old_plane_x * sin(-ROTATESPEED) + cub->person->plane_y * cos(-ROTATESPEED);
	}
	if (keycode == ROTATE_L)
	{
		double	old_dir_x;
		double	old_plane_x; 

		old_dir_x = cub->person->dir_x;
		old_plane_x = cub->person->plane_x;
		cub->person->dir_x = cub->person->dir_x * cos(ROTATESPEED) - cub->person->dir_y * sin(ROTATESPEED);
		cub->person->dir_y = old_dir_x * sin(ROTATESPEED) + cub->person->dir_y * cos(ROTATESPEED);
		cub->person->plane_x = cub->person->plane_x * cos(ROTATESPEED) - cub->person->plane_y * sin(ROTATESPEED);
		cub->person->plane_y = old_plane_x * sin(ROTATESPEED) + cub->person->plane_y * cos(ROTATESPEED);
	}
	return (0);
}

int	on_destroy(t_cub *cub)
{
	cub_destroy(cub);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc == 2)
	{
		cub = cub_init(argv[1]);
		if (cub == NULL)
			print_err("[ERROR]: MLX initialization error");
		print_map(cub);
		mlx_hook(cub->mlx->win_ptr, 2, 0, hooking, cub);
		mlx_hook(cub->mlx->win_ptr, 17, 0, on_destroy, cub);
		mlx_loop_hook(cub->mlx->mlx_ptr, rendering, cub);
		mlx_loop(cub->mlx->mlx_ptr);
		cub_destroy(cub);
	}
	return (0);
}
