/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   person.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:50:00 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/07/15 15:07:58 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static void	west_direction(t_person *person)
{
	person->dir_x = 0;
	person->dir_y = -1;
	person->plane_x = -0.66;
	person->plane_y = 0;
}

static void	east_direction(t_person *person)
{
	person->dir_x = 0;
	person->dir_y = 1;
	person->plane_x = 0.66;
	person->plane_y = 0;
}

static void	south_direction(t_person *person)
{
	person->dir_x = 1;
	person->dir_y = 0;
	person->plane_x = 0;
	person->plane_y = -0.66;
}

static void	north_direction(t_person *person)
{
	person->dir_x = -1;
	person->dir_y = 0;
	person->plane_x = 0;
	person->plane_y = 0.66;
}

t_person	*person_init(int dir, int x, int y)
{
	t_person	*person;

	person = (t_person *)malloc(sizeof(t_person));
	if (person == NULL)
		return (NULL);
	person->pos_x = x;
	person->pos_y = y;
	if (dir == WEST)
		west_direction(person);
	else if (dir == EAST)
		east_direction(person);
	else if (dir == NORTH)
		north_direction(person);
	else if (dir == SOUTH)
		south_direction(person);
	person->mouse_x = 0;
	return (person);
}
