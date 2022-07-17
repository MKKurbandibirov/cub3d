/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 05:22:28 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/17 05:22:30 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/parser.h"

int	ft_check_xpm(char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_strerr("[ERROR] Failed to read the file ");
		ft_strerr(path);
		ft_strerr("\n");
		return (1);
	}
	line = get_next_line(fd);
	if (line == NULL || ft_strnstr(line, "/* XPM */", ft_strlen(line)) == NULL)
	{
		free(line);
		ft_strerr("[ERROR] Not XPM file ");
		ft_strerr(path);
		ft_strerr("\n");
		return (1);
	}
	free(line);
	close(fd);
	return (0);
}

t_plist	*ft_firs_lst(t_plist *lst)
{
	t_plist	*curr;

	if (lst == NULL)
		return (NULL);
	curr = lst;
	while (curr->prev != NULL)
		curr = curr->prev;
	return (curr);
}
