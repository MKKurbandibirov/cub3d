/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:29:05 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/15 15:24:05 by nfarfetc         ###   ########.fr       */
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
		dst = cub->mlx->addr + (y * cub->mlx->line_length
				+ x * (cub->mlx->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
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
	if (keycode == MOUSE_HIDE && cub->key_mouse_hide == 0)
	{
		cub->key_mouse_hide = 1;
		mlx_mouse_hide();
	}
	else if (keycode == MOUSE_HIDE && cub->key_mouse_hide == 1)
	{
		cub->key_mouse_hide = 0;
		mlx_mouse_show();
	}
	moving(cub, keycode);
	rotating(cub, keycode);
	if (!door_open(cub, keycode))
		door_close(cub, keycode);
	return (0);
}

int	rendering(t_cub *cub)
{
	ft_bzero(cub->mlx->addr, WIN_HEIGHT + WIN_WIDTH
		* (cub->mlx->bits_per_pixel / 8));
	raycasting(cub, cub->curr_spr);
	cub->end = clock();
	if (cub->sprite != NULL)
	{
		draw_sprite(cub, cub->curr_spr);
		if ((cub->start - cub->end) % 4 == 0)
			cub->curr_spr = (cub->curr_spr + 1) % cub->cnt_texture_sp;
	}
	draw_minimap(cub, -10, -10);
	mlx_put_image_to_window(cub->mlx->mlx_ptr,
		cub->mlx->win_ptr, cub->mlx->img_ptr, 0, 0);
	return (0);
}
