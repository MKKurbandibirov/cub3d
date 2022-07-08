/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:15:14 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/08 17:31:08 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/parser.h"

void	ft_pars_texturs(t_prs **prs, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if(fd < 0)
	{
		ft_strerr("Problems reading a file\n");
		exit(EXIT_FAILURE); //TODO СДЕЛАТЬ НОРМАЛЬНЫЙ ВЫХОД С ОЧИСТКОЙ ПАМЯТИ
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_pushback_p();//TODO
		line = get_next_line(fd);
	}
}

void	ft_preparser(t_prs *prs, char *path)
{
	ft_pars_texturs(&prs, path);
}
