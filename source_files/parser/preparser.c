/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:15:14 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/12 10:42:17 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/parser.h"

void	ft_delelem_sp(t_plist **head, t_plist *delElem)
{
	if (*head == NULL || delElem == NULL)
		return ;
	if (*head == delElem)
		*head = delElem->next;
	if (delElem->next != NULL)
		delElem->next->prev = delElem->prev;
	if (delElem->prev != NULL)
		delElem->prev->next = delElem->next;
	free(delElem->data);
	free(delElem);
}

void	ft_alloc(t_prs *prs, int i)
{

	prs->cub->doors_pos = (int **)malloc(sizeof(int *) * prs->cnt_doors);
	if (prs->cub->doors_pos == NULL)
		ft_free_allocated_err(prs, 1);
	while (i < prs->cnt_doors)
	{
		prs->cub->doors_pos[i] = (int *)malloc(sizeof(int) * 2);
		if (prs->cub->doors_pos[i] == NULL)
			ft_free_allocated_err(prs, 1);
		i++;
	}
	if (prs->texture->cnt_lst != 0)
	{
		i = 0;
		prs->cub->sprite_texture = (char **)malloc(sizeof(char *)
				* prs->texture->cnt_lst + 1);
		if (prs->cub->sprite_texture == NULL)
			ft_free_allocated_err(prs, 1);
		while (i < prs->texture->cnt_lst)
		{
			prs->cub->sprite_texture[i++] = ft_strdup(prs->texture->lst->data);
			ft_delelem_sp(&prs->texture->lst, prs->texture->lst);
		}
		prs->cub->sprite_texture[i] = NULL;
	}
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

void	ft_valid_cnt(t_prs *prs)
{
	if (prs->cnt_ewns != 1 || prs->cnt_yoda > 1)
	{
		ft_strerr("[ERROR] Invalid .cub file\n");
		ft_prs_exit(prs, 1);
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
	prs->map[i] = NULL;
	prs->cnt_str_in_map = i - 1;
	prs->strlen = (int *)malloc(sizeof(int) * prs->cnt_str_in_map);
	if (prs->strlen == NULL)
		ft_free_allocated_err(prs, 0);
	i = -1;
	while (prs->map[++i])
			prs->strlen[i] = ft_dirty_strlen(prs->map[i], 0, prs);
}

int	ft_get_color(char *s, t_prs *prs)
{
	int		color;
	int		cnt;
	char	**splt;

	splt = ft_split(s, ',');
	cnt = 0;
	while (splt[cnt])
		cnt++;
	if (cnt != 3)
	{
		ft_strerr("[ERROR] Invalid .cub file\n");
		ft_prs_exit(prs, 1);
	}
	color = 0x00000000;
	color += ft_atoi(splt[0]) << 16;
	color += ft_atoi(splt[1]) << 8;
	color += ft_atoi(splt[2]);
	free_split(splt);
	return (color);
}

void	ft_broadcast_settings(t_prs *prs, int i)
{
	ft_coord(prs, -1, -1);
	prs->cub->cnt_door = prs->cnt_doors;
	prs->cub->map = prs->map;
	prs->cub->cnt_texture_sp = prs->texture->cnt_lst;
	if (prs->cnt_doors > 0)
		prs->cub->wall_texture_path = (char **)malloc(sizeof(char *) * 6);
	else
		prs->cub->wall_texture_path = (char **)malloc(sizeof(char *) * 5);
	if (prs->cub->wall_texture_path == NULL)
		ft_free_allocated_err(prs, 1);
	i = -1;
	while (++i < 4)
		prs->cub->wall_texture_path[i] = ft_strdup(prs->texture->massiv[i]);
	if (prs->cnt_doors > 0)
	{
		prs->cub->wall_texture_path[4] = ft_strdup(prs->texture->massiv[6]);
		prs->cub->wall_texture_path[5] = NULL;
	}
	else
		prs->cub->wall_texture_path[4] = NULL;
	prs->cub->clr_c = ft_get_color(prs->texture->massiv[4], prs);
	prs->cub->clr_f = ft_get_color(prs->texture->massiv[5], prs);
	free_split(prs->texture->massiv);
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
		ft_verticatl_checking(prs, 0, 0);
		ft_horizontal_checking(prs);
		ft_alloc(prs, 0);
		ft_broadcast_settings(prs, 0);
	}
	else
	{
		ft_strerr("[ERROR] Invalid .cub file\n");
		ft_prs_exit(prs, 0);
	}
}
