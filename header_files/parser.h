/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:36:00 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/11 14:45:07 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include "cub3d.h"

typedef struct s_texture
{
	char	*massiv[6];
	char	*f;
	char	*c;
	int		check_cnt;
}	t_texture;

typedef struct s_plist
{
	int				id;
	char			*data;
	struct s_plist	*next;
	struct s_plist	*prev;
}	t_plist;

typedef struct s_prs
{
	int			**map;
	t_texture	*texture;
	t_plist		*preprs;
	int			len_lists;
	t_cub		*cub;
}	t_prs;

//prepars_list_func.c
void	ft_pushback_p(t_plist **head, char *line, t_prs *prs);
void	ft_delelem(t_plist **head, t_plist *delElem, t_prs *prs);
t_plist	*ft_getlast(t_plist *head);

//parser.c
void	ft_parser(char *path, t_cub *cub);

//preparser.c
void	ft_preparser(t_prs *prs);
int		ft_is_map(char *line);

//utils.c
void	ft_strerr(char *s);
int		ft_access(char *path);

#endif
