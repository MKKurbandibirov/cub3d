/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:19:22 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/15 16:06:18 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	(void)argv;
	if (argc == 2)
	{
		cub = cub_init();
		if (cub == NULL)
		{
			print_err("[ERROR]: MLX initialization error");
			cub_destroy(cub);
			return (1);
		}
		mlx_hook(cub->mlx->win_ptr, 2, 0, hooking, cub);
		mlx_hook(cub->mlx->win_ptr, 17, 0, on_destroy, cub);
		mlx_hook(cub->mlx->win_ptr, 6, 0, mouse_rotate, cub);
		mlx_loop_hook(cub->mlx->mlx_ptr, rendering, cub);
		mlx_loop(cub->mlx->mlx_ptr);
		cub_destroy(cub);
	}
	return (0);
}
