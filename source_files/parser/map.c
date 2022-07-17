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

int	ft_is_analog_zero(char c)
{
	if (c == 'Y' || c == '0' || c == 'N' || c == 'S' || c == 'W'
		|| c == 'E' || c == 'D')
		return (1);
	return (0);
}

static void	ft_horiz_err(t_prs *prs)
{
	ft_strerr("[ERROR] (HORIZ) Invalid .cub file\n");
	ft_prs_exit(prs, 0);
}

static void	ft_vert_err(t_prs *prs)
{
	ft_strerr("[ERROR] (VERT) Invalid .cub file\n");
	ft_prs_exit(prs, 0);
}

void	ft_horizontal_checking(t_prs *prs, int i, int j)
{
	char	prev;

	while (prs->map[i])
	{
		j = 0;
		while (prs->map[i][j] == ' ')
			j++;
		if (prs->map[i][j] && prs->map[i][j] != '1')
			ft_horiz_err(prs);
		prev = prs->map[i][j];
		while (prs->map[i][j])
		{
			if ((ft_is_analog_zero(prs->map[i][j]) && prev == ' ')
				|| (prs->map[i][j] == ' ' && ft_is_analog_zero(prev)))
				ft_horiz_err(prs);
			prev = prs->map[i][j];
			j++;
		}
		if (ft_is_analog_zero(prev))
		{
			ft_strerr("[ERROR] (HORIZ) Invalid .cub file\n");
			ft_prs_exit(prs, 0);
		}
		i++;
	}
}

void	ft_verticatl_checking(t_prs *prs, int j, char prev, int i)
{
	while (i < prs->max_len_str)
	{
		j = 0;
		while (prs->map[j] && (prs->strlen[j] <= i
				|| (prs->map[j][i] && prs->map[j][i] == ' ')))
			j++;
		if (prs->map[j][i] && prs->map[j][i] != '1')
			ft_vert_err(prs);
		prev = prs->map[j][i];
		while (prs->map[j])
		{
			while (prs->map[j] && prs->strlen[j] < i)
				j++;
			if (prs->map[j] && ((prs->map[j][i] == ' '
					&& ft_is_analog_zero(prev))
				|| (ft_is_analog_zero(prs->map[j][i]) && prev == ' ')))
				ft_vert_err(prs);
			if (prs->map[j] && prs->strlen[j] >= i)
				prev = prs->map[j][i];
			j++;
		}
		if (prs->map[j] == NULL && ft_is_analog_zero(prev))
			ft_vert_err(prs);
		i++;
	}
}
