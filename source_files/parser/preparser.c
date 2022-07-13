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

int	ft_wight_map(t_prs *prs)
{
	t_plist	*curr;
	int		old;
	int		cr;

	cr = -1;
	curr = prs->preprs;
	while (curr)
	{
		old = ft_strlen(curr->data);
		curr = curr->next;
		if (curr)
		{
			cr = ft_strlen(curr->data);
			if (cr != old)
				exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
		}
	}
	return (cr);
}

void	ft_get_param_and_init_map(t_prs *prs)
{
	int	i;

	if (prs->preprs == NULL)
		exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
	prs->h = prs->len_lists;
	prs->w = ft_wight_map(prs);
	if (prs->h < 3 || prs->w < 3)
		exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
	i = 0;
	prs->map = (int **) malloc(sizeof(int *) * prs->h);
	if (!prs->map)
		exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
	while (i < prs->h)
	{
		prs->map[i] = (int *)malloc(sizeof(int) * prs->w);
		if (!prs->map[i])
			exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
	}
}

void	ft_fill_map(t_prs *prs, int i, int j, char curr)
{
	if (curr == '1')
		prs->map[j][i] = WALL;
	else if (curr == '0')
		prs->map[j][i] = FLOOR;
	else if (curr == ' ')
		prs->map[j][i] = EMPTY;
	else if (prs->cnt_ewns < 1 && (curr == 'N'
			|| curr == 'E' || curr == 'W' || curr == 'S'))
	{
		prs->cnt_ewns++;
		if (curr == 'N')
			prs->map[j][i] = NORTH;
		else if (curr == 'E')
			prs->map[j][i] = EAST;
		else if (curr == 'W')
			prs->map[j][i] = WEST;
		else
			prs->map[j][i] = SOUTH;
	}
	else
		exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
}

//i -- w j -- h
void	ft_get_map(t_prs *prs, int i, int j)
{
	t_plist	*curr;

	curr = prs->preprs;
	while (curr)
	{
		i = 0;
		while (curr->data[i])
		{
			ft_fill_map(prs, i, j, curr->data[i]);
			i++;
		}
		j++;
		ft_delelem(&prs->preprs, prs->preprs, prs);
		curr = curr->next;
	}
}

void	ft_preparser(t_prs *prs, char *path)
{
	ft_create_lists(&prs, path);
	ft_get_path(prs);
	if (prs->preprs != NULL)
	{
		ft_skip_endl(prs);
		ft_get_param_and_init_map(prs);
		ft_get_map(prs, 0, 0);
	}
}
