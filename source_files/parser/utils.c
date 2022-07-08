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
	int fd;
	
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_strerr("failed to read the file ");
		ft_strerr(path);
		return (1);
	}
	close(fd);
	return (0);
}

