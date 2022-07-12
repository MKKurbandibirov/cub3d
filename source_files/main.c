/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:19:22 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/12 11:06:30 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	rendering(t_cub *cub)
{
	ft_bzero(cub->mlx->addr, WIN_HEIGHT + WIN_WIDTH
		* (cub->mlx->bits_per_pixel / 8));
	raycasting(cub);
	mlx_put_image_to_window(cub->mlx->mlx_ptr,
		cub->mlx->win_ptr, cub->mlx->img_ptr, 0, 0);
	return (0);
}

int	on_destroy(t_cub *cub)
{
	cub_destroy(cub);
	exit(EXIT_SUCCESS);
}

int	hooking(int keycode, t_cub *cub)
{
	if (keycode == EXIT_KEY)
		on_destroy(cub);
	moving(cub, keycode);
	rotating(cub, keycode);
	return (0);
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
		mlx_hook(cub->mlx->win_ptr, 6, 0, mouse_rotate, cub);
		mlx_loop_hook(cub->mlx->mlx_ptr, rendering, cub);
		mlx_loop(cub->mlx->mlx_ptr);
		cub_destroy(cub);
	}
	return (0);
}
