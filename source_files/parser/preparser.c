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

void	ft_alloc(t_prs *prs)
{
	int	i;

	prs->cub->doors_pos = (int **)malloc(sizeof(int *) * prs->cnt_doors);
	if (prs->cub->doors_pos == NULL)
		exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
	i = 0;
	while (i < prs->cnt_doors)
	{
		prs->cub->doors_pos[i] = (int *)malloc(sizeof(int) * 2);
		if (prs->cub->doors_pos[i] == NULL)
			exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
		i++;
	}
}

void	ft_coord(t_prs *prs, int i, int j)
{
	while (prs->map[i])
	{
		j = 0;
		while (prs->map[i][j])
		{
			if (prs->map[i][j] == 'N' || prs->map[i][j] == 'S'
				|| prs->map[i][j] == 'W' || prs->map[i][j] == 'E')
			{
				prs->cub->person->pos_x = i;
				prs->cub->person->pos_y = j;
			}
			else if (prs->map[i][j] == 'Y')
			{
				prs->cub->sprite_pos_x = i;
				prs->cub->sprite_pos_y = j;
			}
			else if (prs->map[i][j] == 'D')
			{
				prs->cub->doors_pos[prs->curr_door][0] = i;
				prs->cub->doors_pos[prs->curr_door++][1] = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_valid_cnt(t_prs *prs)
{
	if (prs->cnt_ewns != 1)
		exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
	if (prs->cnt_yoda > 1)
		exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
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
		exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
	prs->map[i] = NULL;
	prs->cnt_str_in_map = i - 1;
	prs->strlen = (int *)malloc(sizeof(int) * prs->cnt_str_in_map);
	i = -1;
	while (prs->map[++i])
			prs->strlen[i] = ft_dirty_strlen(prs->map[i], 0, prs);
}

void	ft_preparser(t_prs *prs, char *path)
{
	ft_create_lists(&prs, path);
	ft_get_path(prs);
	if (prs->preprs != NULL && prs->texture->check_cnt == 6)
	{
		ft_skip_endl(prs);
		ft_alloc_map(prs);
		ft_get_map(prs, 0);
		ft_valid_cnt(prs);
		ft_verticatl_checking(prs, 0, 0);
		ft_horizontal_checking(prs);
		ft_alloc(prs);
		ft_coord(prs, 0, 0);
		prs->cub->map = prs->map;
		printf("cart -- good");
	}
	else
		printf("КРАТА ГОВНО");
}
