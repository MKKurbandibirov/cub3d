/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:19:22 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/10 15:00:45 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	hooking(int keycode, t_cub *cub)
{
	if (keycode == EXIT_KEY)
	{
		cub_destroy(cub);
		exit(EXIT_SUCCESS);
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
		// raycasting(cub);
		// mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img_ptr, 0, 0);
		// mlx_loop_hook(cub->mlx_ptr, raycasting, cub)
		mlx_loop(cub->mlx->mlx_ptr);
		cub_destroy(cub);
	}
	return (0);
}
