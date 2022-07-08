/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:35:34 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/08 15:26:03 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/parser.h"

static void	ft_validatede_path(char *path)
{
	char	*skip;
	char	*name;

	skip = ft_strrchr(path, '/');
	if (skip == NULL)
		skip = path;
	name = ft_strnstr(skip, ".cub", ft_strlen(skip));
	if (name == NULL || name == skip || name[4] != '\0')
	{
		ft_strerr("Incorrect map name\n");
		exit(EXIT_FAILURE); //TODO СДЕЛАТЬ НОРМАЛЬНЫЙ ВЫХОД С ОЧИСТКОЙ ПАМЯТИ
	}
}

void	ft_preparser(char *path)
{
	ft_validated_path(path);
	if (ft_access(path))
		exit(EXIT_FAILURE); //TODO СДЕЛАТЬ НОРМАЛЬНЫЙ ВЫХОД С ОЧИСТКОЙ ПАМЯТИ

}

