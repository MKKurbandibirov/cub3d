/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dity_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:56:38 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/15 18:56:40 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/parser.h"

char	*ft_strtrim_v1(char *s1, char *set)
{
	size_t	size;

	if (!s1)
		return ((void *)0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size = ft_strlen(s1);
	while (size && ft_strchr(set, s1[size]))
		size--;
	return (ft_substr(s1, 0, size + 1));
}

int	ft_dirty_strlen(char *s, int i, t_prs *prs)
{
	while (s[i])
	{
		if (s[i] == 'N' || s[i] == 'S' || s[i] == 'W' || s[i] == 'E')
		{
			prs->cnt_ewns++;
			if (prs->cnt_ewns <= 1 && s[i] == 'N')
				prs->cub->direction = NORTH;
			else if (prs->cnt_ewns < 1 && s[i] == 'S')
				prs->cub->direction = SOUTH;
			else if (prs->cnt_ewns < 1 && s[i] == 'W')
				prs->cub->direction = WEST;
			else if (prs->cnt_ewns < 1 && s[i] == 'E')
				prs->cub->direction = EAST;
		}
		else if (s[i] == 'D')
			prs->cnt_doors++;
		else if (s[i] == 'Y')
			prs->cnt_yoda++;
		i++;
	}
	if (i > prs->max_len_str)
		prs->max_len_str = i;
	return (i);
}

void	ft_alloc_map(t_prs *prs)
{
	if (prs->preprs == NULL)
	{
		ft_strerr("[ERROR] Invalid .cub file\n");
		ft_prs_exit(prs, 0);
	}
	prs->map = (char **) malloc(sizeof(char *) * prs->len_lists + 1);
	if (!prs->map)
		ft_free_allocated_err(prs, 0);
}

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
