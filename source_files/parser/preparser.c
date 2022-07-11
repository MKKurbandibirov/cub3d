/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:15:14 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/11 14:45:44 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/parser.h"

int	ft_is_map(char *line)
{
	int	i;

	if (!line || !(*line) || *line == '\n')
		return (0);
	i = 0;
	while (line[i] && (line[i] == '1' || line[i] == '0' || line[i] == ' '
			|| line[i] == 'N' || line[i] == 'E' || line[i] == 'S'
			|| line[i] == 'W'))
		i++;
	if (!line[i] || line[i] == '\n')
		return (1);
	return (0);
}

int	ft_status(char *s)
{
	if (!s || !*s)
		return (-1);
	if (s[0] && s[1] && s[1] == 'N' && s[1] == 'O')
		return (0);
	else if (s[0] && s[1] && s[1] == 'S' && s[1] == 'O')
		return (1);
	else if (s[0] && s[1] && s[1] == 'E' && s[1] == 'A')
		return (2);
	else if (s[0] && s[1] && s[1] == 'W' && s[1] == 'E')
		return (3);
	return (-1);
}

int	ft_search_parties(char *s)
{
	if (!s || !(*s))
		return (0);
	if (ft_strnstr(s, "NO", ft_strlen(s)) || ft_strnstr(s, "SO", ft_strlen(s))
		|| ft_strnstr(s, "EA", ft_strlen(s))
		|| ft_strnstr(s, "WE", ft_strlen(s)))
		return (1);
	return (0);

}

int	ft_skip_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	return (i);
}

int	ft_search_path(char	*s, t_prs **prs)
{
	int	i;
	int	status;

	if (!s)
		return (-1);
	i = 0;
	if (ft_search_parties(s))
	{
		while (s[i++])
		{
			status = ft_status(&s[i]);
			if (status == -1)
				return (-1);
			i += ft_skip_space(&s[i]);
			if (!s[i] || s[i] == '\n')
				return (-1);
			if ((*prs)->texture->massiv[status] == NULL)
			{
				(*prs)->texture->massiv[status] = ft_strdup(&s[i]);
				(*prs)->texture->check_cnt += 1;
			}
			else
				return (-1);
		}
	}
}

char	*ft_path(char *s, t_prs **prs)
{
	while ()
	{
	}
	
}

int	ft_is_texture(t_prs **prs)
{
	t_plist	*curr;

	curr = (*prs)->preprs;
	while (curr && ft_is_map(curr->data) == 0)
	{
		
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
}

void	ft_preparser(t_prs *prs, char *path)
{
	ft_pars_texturs(&prs, path);
}
