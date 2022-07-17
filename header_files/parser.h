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

//prepars_list_func.c
void	ft_pushback_p(t_plist **head, char *line, t_prs *prs);
void	ft_delelem(t_plist **head, t_plist *delElem, t_prs *prs);
void	ft_pushback_sp(t_plist **head, char *line, t_prs *prs);
t_plist	*ft_getlast(t_plist *head);
void	ft_delelem_sp(t_plist **head, t_plist *delElem);

//parser.c
void	ft_parser(char *path, t_cub *cub);

//preparser.c
void	ft_preparser(t_prs *prs, char *path);
void	ft_coord(t_prs *prs, int i, int j);
void	ft_valid_cnt(t_prs *prs);

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
void	ft_create_lists(t_prs **prs, char *path);

//map.c
void	ft_horizontal_checking(t_prs *prs, int i, int j);
void	ft_verticatl_checking(t_prs *prs, int j, char prev, int i);

//dirty_utils.c
char	*ft_strtrim_v1(char *s1, char *set);
int		ft_dirty_strlen(char *s, int i, t_prs *prs);
void	ft_alloc_map(t_prs *prs);
void	ft_skip_endl(t_prs *prs);
void	ft_check_all_access(t_prs *prs);

//utils_1.c
void	ft_get_path(t_prs *prs);
void	ft_free_serch_helper(t_prs **prs);
void	ft_free_allocated_err(t_prs *prs, int key);
void	ft_broadcast_settings(t_prs *prs, int i);

void	ft_prs_exit(t_prs *prs, int key);

//utils_2.c
int		ft_check_xpm(char *path);
t_plist	*ft_firs_lst(t_plist *lst);

#endif
