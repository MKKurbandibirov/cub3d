/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:35:34 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/08 16:59:40 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/parser.h"

static void	ft_init_prs(t_prs *prs, t_cub *cub)
{
	prs->len_lists = 0;
	prs->cub = cub;
	prs->texture = NULL;
	prs->preprs = NULL;
	prs->map = NULL;
}

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

void	ft_parser(char *path, t_cub *cub)
{
	t_prs	prs;

	ft_validated_path(path);
	if (ft_access(path))
		exit(EXIT_FAILURE); //TODO СДЕЛАТЬ НОРМАЛЬНЫЙ ВЫХОД С ОЧИСТКОЙ ПАМЯТИ
	ft_init_prs(&prs, cub);
	ft_preparser(&prs, path);
}

