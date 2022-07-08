/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:39:53 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/07 16:58:45 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define FLOOR 0
# define WALL 1
# define EMPTY -1

typedef struct s_cub
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		map_length;
	int		map_width;	
	int		**map;
}	t_cub;

/* Initialization */
t_cub	*cub_init(void);

/* Destroing */
void	map_free(int **map, int length);
void	cub_destroy(t_cub *cub);

/* Utils */
void	print_err(char *str);
void	print_map(t_cub *cub);

#endif
