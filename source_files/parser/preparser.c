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

char	*ft_curr_word(char *s)
{
	int		i;
	char	*curr;
	char	prev_c;

	prev_c = '0';
	while(s[i] && !ft_isspace(s))
}

int	ft_search_settings(char	*s, t_prs **prs)
{
	int	i;
	int	status;

	if (!s)
		return (-1);
	i = 0;
	if (ft_search_parties(s))
	{
		while (s[i])
		{
			status = ft_status(&s[i]);
			if (status == -1)
				return (-2);
			i += 2;
			i += ft_skip_space(&s[i]);
			if (!s[i] || s[i] == '\n')
				return (-2);
			if ((*prs)->texture->massiv[status] == NULL)
			{
				(*prs)->texture->massiv[status] = ft_strdup(&s[i]);
				(*prs)->texture->check_cnt += 1;
			}
			else
				return (-2);
			i++;
		}
	}
	return (0);
}

void	ft_create_lists(t_prs **prs, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_strerr("Problems reading a file\n");
		exit(EXIT_FAILURE); //TODO СДЕЛАТЬ НОРМАЛЬНЫЙ ВЫХОД С ОЧИСТКОЙ ПАМЯТИ
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_pushback_p(&(*prs)->preprs, line, *prs);
		line = get_next_line(fd);
	}
}

void	ft_preparser(t_prs *prs, char *path)
{
	t_plist	*curr;

	ft_create_lists(&prs, path);
	curr = prs->preprs;
	while (curr)
	{
		ft_search_settings(curr->data, &prs);
		curr = curr->next;
	}
}
