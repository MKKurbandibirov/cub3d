/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:36:00 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/13 00:50:08 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include "cub3d.h"

typedef struct s_texture
{
	char	*massiv[6];
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
	char		**map;
	int			*strlen;
	int			max_len_str;
	t_texture	*texture;
	t_plist		*preprs;
	int			len_lists;
	int			cnt_str_in_map;
	int			cnt_ewns;
	int			cnt_doors;
	int			cnt_yoda;
	t_cub		*cub;
}	t_prs;

//prepars_list_func.c
void	ft_pushback_p(t_plist **head, char *line, t_prs *prs);
void	ft_delelem(t_plist **head, t_plist *delElem, t_prs *prs);
t_plist	*ft_getlast(t_plist *head);

//parser.c
void	ft_parser(char *path, t_cub *cub);

//preparser.c
void	ft_preparser(t_prs *prs, char *path);

//utils.c
void	ft_strerr(char *s);
int		ft_search_parties(char *s);
int		ft_skip_space(char *s);
int		ft_access(char *path);
int		ft_is_map(char *line);

// prepars_continue.c
int		ft_status(char *s);
char	*ft_curr_word(char *s, int i, int cnt, char prev_c);
int		ft_search_settings(char	*s, t_prs **prs, int i, int status);
void	ft_get_path(t_prs *prs);
void	ft_create_lists(t_prs **prs, char *path);

//map.c
void	ft_horizontal_checking(t_prs *prs);
void	ft_verticatl_checking(t_prs *prs);

//dirty_utils.c
char	*ft_strtrim_v1(char *s1, char *set);
int		ft_dirty_strlen(char *s, int i, t_prs *prs);

#endif
