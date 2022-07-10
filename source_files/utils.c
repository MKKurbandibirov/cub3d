/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:29:05 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/10 15:08:49 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	print_err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

void	my_put_pixel(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		dst = cub->mlx->addr + (y * cub->mlx->line_lenght
				+ x * (cub->mlx->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	print_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < cub->map_width)
		{
			printf("%d", cub->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("Length:\t%d\nWidth:\t%d\n", cub->map_height, cub->map_width);
}
