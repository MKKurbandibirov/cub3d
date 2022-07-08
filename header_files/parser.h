/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:36:00 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/08 15:42:47 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "cub3d.h"

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		check_cnt;
}	t_texture;

typedef struct s_plist
{
	int				id;
	int				cnt;
	char			*data;
	struct s_plist	*next;
	struct s_plist	*prev;
}	t_plist;

typedef struct s_prs
{
	int			**map;
	t_texture	*texture;
	t_plist		*preprs;
	t_cub		*cub;
}	t_prs;

//parser.c
void	ft_preparser(char *path);

//utils.c
void	ft_strerr(char *s);
int	ft_access(char *path);


#endif
