/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:24:22 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/08 15:25:11 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/parser.h"

void	ft_strerr(char *s)
{
	write(2, s, ft_strlen(s));
}

int	ft_access(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_strerr("[ERROR] Failed to read the file ");
		ft_strerr(path);
		ft_strerr("\n");
		return (1);
	}
	close(fd);
	return (0);
}

int	ft_search_parties(char *s)
{
	if (!s || !(*s))
		return (0);
	if (ft_strnstr(s, "NO", ft_strlen(s)) || ft_strnstr(s, "SO", ft_strlen(s))
		|| ft_strnstr(s, "EA", ft_strlen(s)) || ft_strchr(s, 'C')
		|| ft_strnstr(s, "WE", ft_strlen(s)) || ft_strchr(s, 'F')
		|| ft_strchr(s, 'D') || ft_strnstr(s, "SP", ft_strlen(s)))
		return (1);
	return (0);
}

int	ft_is_map(char *line)
{
	int	i;

	if (!line || !(*line) || *line == '\n')
		return (0);
	i = 0;
	while (line[i] && (line[i] == '1' || line[i] == '0' || line[i] == ' '
			|| line[i] == 'N' || line[i] == 'E' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'Y' || line[i] == 'D'))
		i++;
	if (!line[i] || line[i] == '\n')
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
