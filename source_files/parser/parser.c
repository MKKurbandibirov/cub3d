/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:35:34 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/08 16:59:40 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/parser.h"

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
	while (prs->cnt_doors)
		free(prs->cub->doors_pos[--prs->cnt_doors]);
	free(prs->cub->doors_pos);
	if (key > 0)
		free(prs->strlen);
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
