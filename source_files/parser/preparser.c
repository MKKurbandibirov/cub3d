/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:15:14 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/17 10:08:59 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/parser.h"

void	ft_alloc_sp(t_prs *prs, int i)
{
	prs->cub->sprite_texture = (char **)malloc(sizeof(char *)
			* prs->texture->cnt_lst + 1);
	if (prs->cub->sprite_texture == NULL)
		ft_free_allocated_err(prs, 1);
	while (i < prs->texture->cnt_lst)
	{
		prs->cub->sprite_texture[i++] = ft_strdup(prs->texture->lst->data);
		if (i == prs->texture->cnt_lst)
			break ;
		prs->texture->lst = prs->texture->lst->next;
	}
	prs->cub->sprite_texture[i] = NULL;
}

void	ft_alloc(t_prs *prs, int i)
{
	if (prs->cnt_doors > 0)
	{
		prs->cub->doors_pos = (int **)malloc(sizeof(int *) * prs->cnt_doors);
		if (prs->cub->doors_pos == NULL)
			ft_free_allocated_err(prs, 1);
	}
	while (i < prs->cnt_doors)
	{
		prs->cub->doors_pos[i] = (int *)malloc(sizeof(int) * 2);
		if (prs->cub->doors_pos[i] == NULL)
			ft_free_allocated_err(prs, 1);
		i++;
	}
	if (prs->texture->cnt_lst != 0)
		ft_alloc_sp(prs, 0);
}

void	ft_coord(t_prs *prs, int i, int j)
{
	while (prs->map[++i])
	{
		j = -1;
		while (prs->map[i][++j])
		{
			if (prs->map[i][j] == 'N' || prs->map[i][j] == 'S'
				|| prs->map[i][j] == 'W' || prs->map[i][j] == 'E')
			{
				prs->cub->user_pos_x = i;
				prs->cub->user_pos_y = j;
				prs->map[i][j] = '0';
			}
			else if (prs->map[i][j] == 'Y')
			{
				prs->cub->sprite_pos_x = i;
				prs->cub->sprite_pos_y = j;
				prs->map[i][j] = '0';
			}
			else if (prs->map[i][j] == 'D')
			{
				prs->cub->doors_pos[prs->curr_door][0] = i;
				prs->cub->doors_pos[prs->curr_door++][1] = j;
			}
		}
	}
}

void	ft_get_map(t_prs *prs, int i)
{
	t_plist	*curr;

	curr = prs->preprs;
	while (curr && ft_is_map(curr->data))
	{		
		prs->map[i] = ft_strtrim_v1(curr->data, "\n");
		i++;
		ft_delelem(&prs->preprs, prs->preprs, prs);
		curr = curr->next;
	}
	if (curr != NULL)
	{
		ft_strerr("[ERROR] Invalid .cub file\n");
		ft_prs_exit(prs, 0);
	}
	if (prs->map[i] != NULL)
		prs->map[i] = NULL;
	prs->cnt_str_in_map = i;
	prs->strlen = (int *)malloc(sizeof(int) * prs->cnt_str_in_map);
	if (prs->strlen == NULL)
		ft_free_allocated_err(prs, 0);
	i = -1;
	while (prs->map[++i])
			prs->strlen[i] = ft_dirty_strlen(prs->map[i], 0, prs);
}

void	ft_preparser(t_prs *prs, char *path)
{
	ft_create_lists(&prs, path);
	ft_get_path(prs);
	if (prs->preprs != NULL && prs->texture->check_cnt >= 6)
	{
		ft_skip_endl(prs);
		ft_alloc_map(prs);
		ft_get_map(prs, 0);
		ft_valid_cnt(prs);
		ft_horizontal_checking(prs, 0, 0);
		ft_verticatl_checking(prs, 0, 'H', 0);
		ft_alloc(prs, 0);
		ft_broadcast_settings(prs, 0);
		prs->cub->str_in_map = prs->cnt_str_in_map;
		if (prs->texture->cnt_lst)
		{
			prs->texture->lst = ft_firs_lst(prs->texture->lst);
			while (prs->texture->lst)
				ft_delelem_sp(&prs->texture->lst, prs->texture->lst);
		}
	}
	else
	{
		ft_strerr("[ERROR] Invalid .cub file\n");
		ft_prs_exit(prs, 0);
	}
}
