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

void	ft_skip_endl(t_prs *prs)
{
	t_plist	*curr;

	curr = prs->preprs;
	while (curr && !ft_is_map(curr->data))
	{
		ft_search_settings(curr->data, &prs, 0, 0);
		ft_delelem(&prs->preprs, prs->preprs, prs);
		curr = curr->next;
	}
}

void	ft_alloc_map(t_prs *prs)
{
	if (prs->preprs == NULL)
		exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
	prs->map = (char **) malloc(sizeof(char *) * prs->len_lists + 1);
	if (!prs->map)
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
		ft_verticatl_checking(prs);
		ft_horizontal_checking(prs);
		printf("cart -- good");
	}
	else
		printf("КРАТА ГОВНО");
}
