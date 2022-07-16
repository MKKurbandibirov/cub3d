/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepars_list_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:18:05 by gtaggana          #+#    #+#             */
/*   Updated: 2022/07/08 16:18:07 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/parser.h"

t_plist	*ft_getlast(t_plist *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_delelem(t_plist **head, t_plist *delElem, t_prs *prs)
{
	if (*head == NULL || delElem == NULL)
		return ;
	if (*head == delElem)
		*head = delElem->next;
	if (delElem->next != NULL)
		delElem->next->prev = delElem->prev;
	if (delElem->prev != NULL)
		delElem->prev->next = delElem->next;
	prs->len_lists -= 1;
	free(delElem->data);
	free(delElem);
}

void	ft_pushback_p(t_plist **head, char *line, t_prs *prs)
{
	t_plist	*tmp;
	t_plist	*last;

	last = ft_getlast(*head);
	tmp = (t_plist *) malloc(sizeof(t_plist));
	if (!tmp)
		ft_free_allocated_err(prs, 0);
	tmp->data = line;
	prs->len_lists += 1;
	tmp->id = prs->len_lists;
	tmp->next = NULL;
	if (!last)
	{
		*head = tmp;
		(*head)->prev = NULL;
	}
	else
	{
		last->next = tmp;
		tmp->prev = last;
	}
}

void	ft_pushback_sp(t_plist **head, char *line, t_prs *prs)
{
	t_plist	*tmp;
	t_plist	*last;

	last = ft_getlast(*head);
	tmp = (t_plist *) malloc(sizeof(t_plist));
	if (!tmp)
		ft_free_allocated_err(prs, 0);
	tmp->data = line;
	prs->texture->cnt_lst += 1;
	tmp->id = prs->texture->cnt_lst;
	tmp->next = NULL;
	if (!last)
	{
		*head = tmp;
		(*head)->prev = NULL;
	}
	else
	{
		last->next = tmp;
		tmp->prev = last;
	}
}

void	ft_delelem_sp(t_plist **head, t_plist *delElem)
{
	if (*head == NULL || delElem == NULL)
		return ;
	if (*head == delElem)
		*head = delElem->next;
	if (delElem->next != NULL)
		delElem->next->prev = delElem->prev;
	if (delElem->prev != NULL)
		delElem->prev->next = delElem->next;
	free(delElem->data);
	free(delElem);
}
