/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:29:44 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/14 15:29:55 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/parser.h"

void	ft_horizontal_checking(t_prs *prs)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	while (prs->map[i])
	{
		start = 0;
		end = ft_strlen(prs->map[i]) - 1;
		while (prs->map[i][start] == ' ')
			start++;
		while (prs->map[i][end] == ' ')
			end--;
		if (end <= 1 || prs->map[i][end] != '1' || prs->map[i][start] != '1')
		{
			printf("OPEN CART");
			exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
		}
		i++;
	}
}

void	ft_verticatl_checking(t_prs *prs, int start, int end)
{
	int	i;

	i = 0;
	while (i < prs->max_len_str)
	{
		start = 0;
		end = prs->cnt_str_in_map;
		while (prs->map[start] && (prs->strlen[start] <= i
				|| (prs->map[start][i] && prs->map[start][i] == ' ')))
			start++;
		while (end != 0 && prs->map[end] && (prs->strlen[end] <= i
				|| (prs->map[end][i] && prs->map[end][i] == ' ')))
			end--;
		if (end == 0)
			printf("VERTICAL -- OK\n");
		else if (prs->map[end][i] != '1' || prs->map[start][i] != '1')
		{
			printf("OPEN CART");
			exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
		}
		i++;
	}
}