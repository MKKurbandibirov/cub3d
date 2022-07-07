/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:29:05 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/07 16:41:34 by nfarfetc         ###   ########.fr       */
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

void	print_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->map_length)
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
	printf("Length:\t%d\nWidth:\t%d\n", cub->map_length, cub->map_width);
}
