/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:35:34 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/17 10:31:08 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/parser.h"

void	ft_valid_cnt(t_prs *prs)
{
	if (prs->cnt_ewns != 1 || prs->cnt_yoda > 1)
	{
		ft_strerr("[ERROR] Invalid .cub file\n");
		ft_prs_exit(prs, 1);
	}
}

static void	ft_init_prs(t_prs *prs, t_cub *cub)
{
	int	i;

	i = 0;
	prs->len_lists = 0;
	prs->cnt_ewns = 0;
	prs->cnt_doors = 0;
	prs->curr_door = 0;
	prs->cnt_yoda = 0;
	prs->cnt_str_in_map = 0;
	prs->max_len_str = 0;
	prs->cub = cub;
	prs->preprs = NULL;
	prs->map = NULL;
	prs->texture = (t_texture_prs *) malloc(sizeof(t_texture_prs));
	if (prs->texture == NULL)
		ft_free_allocated_err(prs, 0);
	prs->texture->lst = NULL;
	prs->texture->check_cnt = 0;
	prs->texture->cnt_lst = 0;
	while (i < 7)
		prs->texture->massiv[i++] = NULL;
}

static int	ft_validatede_path(char *path)
{
	char	*skip;
	char	*name;

	skip = ft_strrchr(path, '/');
	if (skip == NULL)
		skip = path;
	name = ft_strnstr(skip, ".cub", ft_strlen(skip));
	if (name == NULL || name == skip || name[4] != '\0')
	{
		ft_strerr("Incorrect map name\n");
		return (1);
	}
	return (0);
}

void	ft_prs_exit(t_prs *prs, int key)
{
	if (prs->map)
		free_split(prs->map);
	while (prs->preprs != NULL)
		ft_delelem(&prs->preprs, prs->preprs, prs);
	free_split(prs->cub->sprite_texture);
	free_split(prs->cub->wall_texture_path);
	if (key > 0)
	{
		while (prs->cnt_doors)
			free(prs->cub->doors_pos[--prs->cnt_doors]);
		free(prs->cub->doors_pos);
		free(prs->strlen);
	}
	free(prs->cub);
	exit(EXIT_FAILURE);
}

void	ft_parser(char *path, t_cub *cub)
{
	t_prs	*prs;

	prs = (t_prs *)malloc(sizeof(t_prs));
	if (prs == NULL || ft_validatede_path(path) || ft_access(path))
	{
		free(cub);
		exit(EXIT_FAILURE);
	}
	ft_init_prs(prs, cub);
	ft_preparser(prs, path);
	free(prs->strlen);
	free(prs);
}
