/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:39:53 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/07 19:10:42 by nfarfetc         ###   ########.fr       */
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

# define WIN_LENGTH 1920
# define WIN_WIDTH	1080

# define FLOOR 0
# define WALL 1
# define EMPTY -1

# define EXIT_KEY 53

typedef struct s_cub
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		map_length;
	int		map_width;
	int		pos_x;
	int		pos_y;
	int		**map;
	char	*map_path;
}	t_cub;

/* Initialization */
t_cub	*cub_init(char *map_path);

/* Destroing */
void	map_free(int **map, int length);
void	cub_destroy(t_cub *cub);

/* Utils */
void	print_err(char *str);
void	print_map(t_cub *cub);

#endif