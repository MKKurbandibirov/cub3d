/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:19:23 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/16 20:19:25 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/parser.h"

void	ft_get_path(t_prs *prs)
{
	t_plist	*curr;

	curr = prs->preprs;
	while (curr && !ft_is_map(curr->data))
	{
		ft_search_settings(curr->data, &prs, 0, 0);
		ft_delelem(&prs->preprs, prs->preprs, prs);
		curr = curr->next;
	}
	ft_check_all_access(prs);
}

void	ft_free_serch_helper(t_prs **prs)
{
	ft_strerr("[ERROR] Invalid .cub file\n");
	ft_prs_exit(*prs, 0);
}

void	ft_free_allocated_err(t_prs *prs, int key)
{
	ft_strerr("[ERROR] Allocated memory\n");
	ft_prs_exit(prs, key);
}

static int	ft_get_color(char *s, t_prs *prs)
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
