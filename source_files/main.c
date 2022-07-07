/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:19:22 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/07 16:58:58 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	main(void)
{
	t_cub	*cub;

	cub = cub_init();
	print_map(cub);
	if (cub == NULL)
		print_err("[ERROR]: MLX initialization error");
	mlx_loop(cub->mlx_ptr);
	cub_destroy(cub);
}
