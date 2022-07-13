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
	if (s[0] && s[1] && s[2] && s[2] == ' ' && s[0] == 'N' && s[1] == 'O')
		return (0);
	else if (s[0] && s[1] && s[2] && s[2] == ' ' && s[0] == 'S' && s[1] == 'O')
		return (1);
	else if (s[0] && s[1] && s[2] && s[2] == ' ' && s[0] == 'E' && s[1] == 'A')
		return (2);
	else if (s[0] && s[1] && s[2] && s[2] == ' ' && s[0] == 'W' && s[1] == 'E')
		return (3);
	else if (s[0] && s[1] && s[0] == 'C' && (s[1] == ' ' || s[1] == '\t'))
		return (4);
	else if (s[0] && s[1] && s[0] == 'F' && (s[1] == ' ' || s[1] == '\t'))
		return (5);
	return (-1);
}

char	*ft_curr_word(char *s, int i, int cnt)
{
	char	*curr;
	char	prev_c;

	prev_c = '0';
	while (s[i] && (!ft_isspace(s[i]) || (s[i] == ' ' && prev_c == '\\')))
	{
		if (s[i] != ' ' && s[i] != '\n')
			cnt++;
		prev_c = s[i];
		i++;
	}
	curr = (char *) malloc(sizeof(char) * (cnt + 1));
	i = 0;
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
				exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
			i += 2;
			i += ft_skip_space(&s[i]);
			if (!s[i] || s[i] == '\n')
				return (-2);
			if ((*prs)->texture->massiv[status] == NULL)
			{
				(*prs)->texture->massiv[status] = ft_curr_word(&s[i], 0, 0);
				(*prs)->texture->check_cnt += 1;
				return (0);
			}
			else
				exit(EXIT_FAILURE);//TODO NORM OBRABOTKA + VIVOD ERR
			i++;
		}
	}
	return (0);
}

void	ft_get_path(t_prs *prs)
{
	t_plist	*curr;

	curr = prs->preprs;
	while (curr && prs->texture->check_cnt != 6)
	{
		ft_search_settings(curr->data, &prs, 0, 0);
		ft_delelem(&prs->preprs, prs->preprs, prs);
		curr = curr->next;
	}
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
	close(fd);
}
