/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:19:22 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/07 18:26:18 by nfarfetc         ###   ########.fr       */
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
		print_map(cub);
		if (cub == NULL)
			print_err("[ERROR]: MLX initialization error");
		mlx_hook(cub->mlx_win, 2, 0, hooking, cub);
		mlx_hook(cub->mlx_win, 17, 0, on_destroy, cub);
		mlx_loop(cub->mlx_ptr);
		cub_destroy(cub);
	}
	return (0);
}
