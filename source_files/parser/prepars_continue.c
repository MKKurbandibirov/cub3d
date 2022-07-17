/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepars_continue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:41:41 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/12 10:42:38 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/parser.h"

int	ft_status(char *s)
{
	if (!s || !*s)
		return (-1);
	if (s[0] && s[1] && s[2] && (s[2] == ' ' || s[2] == '\t')
		&& s[0] == 'N' && s[1] == 'O')
		return (0);
	else if (s[0] && s[1] && s[2] && (s[2] == ' ' || s[2] == '\t')
		&& s[0] == 'S' && s[1] == 'O')
		return (1);
	else if (s[0] && s[1] && s[2] && (s[2] == ' ' || s[2] == '\t')
		&& s[0] == 'E' && s[1] == 'A')
		return (2);
	else if (s[0] && s[1] && s[2] && (s[2] == ' ' || s[2] == '\t')
		&& s[0] == 'W' && s[1] == 'E')
		return (3);
	else if (s[0] && s[1] && s[0] == 'C' && (s[1] == ' ' || s[1] == '\t'))
		return (4);
	else if (s[0] && s[1] && s[0] == 'F' && (s[1] == ' ' || s[1] == '\t'))
		return (5);
	else if (s[0] && s[1] && s[0] == 'D' && (s[1] == ' ' || s[1] == '\t'))
		return (6);
	else if (s[0] && s[1] && s[2] && (s[2] == ' ' || s[2] == '\t')
		&& s[0] == 'S' && s[1] == 'P')
		return (7);
	return (-1);
}

char	*ft_curr_word(char *s, int i, int cnt, char prev_c)
{
	char	*curr;

	if (s[0] && s[1] && s[0] == '.' && s[1] == '/')
		i += 2;
	while (s[i] && (!ft_isspace(s[i]) || (s[i] == ' ' && prev_c == '\\')))
	{
		if (s[i] != ' ' && s[i] != '\n')
			cnt++;
		prev_c = s[i];
		i++;
	}
	curr = (char *) malloc(sizeof(char) * (cnt + 1));
	i = 0;
	if (s[0] && s[1] && s[0] == '.' && s[1] == '/')
		i += 2;
	cnt = 0;
	while (s[i] && (!ft_isspace(s[i]) || (s[i] == ' ' && prev_c == '\\')))
	{
		if (s[i] != '\\' && s[i] != '\n')
			curr[cnt++] = s[i];
		prev_c = s[i];
		i++;
	}
	curr[cnt] = '\0';
	return (curr);
}

int	ft_fill_path(t_prs **prs, int status, char *s)
{
	if (status < 7)
	{
		(*prs)->texture->massiv[status] = ft_curr_word(s, 0, 0, '0');
		(*prs)->texture->check_cnt += 1;
	}
	else
		ft_pushback_sp(&(*prs)->texture->lst,
			ft_curr_word(s, 0, 0, '0'), *prs);
	return (0);
}

int	ft_search_settings(char	*s, t_prs **prs, int i, int status)
{
	if (!s)
		return (-1);
	if (ft_search_parties(s))
	{
		while (s[i])
		{
			i += ft_skip_space(&s[i]);
			status = ft_status(&s[i]);
			if (status == -1)
				ft_free_serch_helper(prs);
			i += 2;
			i += ft_skip_space(&s[i]);
			if (!s[i] || s[i] == '\n')
				return (-2);
			if (status == 7 || (*prs)->texture->massiv[status] == NULL)
				return (ft_fill_path(prs, status, &s[i]));
			else
				ft_free_serch_helper(prs);
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
		ft_prs_exit(*prs, 0);
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_pushback_p(&(*prs)->preprs, line, *prs);
		line = get_next_line(fd);
	}
	close(fd);
}
