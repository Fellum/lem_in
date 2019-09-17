/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:03:21 by blomo             #+#    #+#             */
/*   Updated: 2019/09/16 19:14:48 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				vizit_room(t_way *way)
{
	t_way			*temp;

	temp = way;
	if (temp)
	{
		if (temp->next != NULL)
			temp = temp->next;
		while (temp->next)
		{
			if (temp->sosed->vizit == 1)
				temp->sosed->vizit = 2;
			if (temp->sosed->vizit == 0)
				temp->sosed->vizit = 1;
			temp = temp->next;
		}
	}
}

void				open_vizit(t_way *way)
{
	t_way			*temp;

	temp = way;
	if (temp)
	{
		if (temp->next != NULL)
			temp = temp->next;
		while (temp->next)
		{
			temp->sosed->vizit = 0;
			temp->sosed->is_node_one = 0;
			temp = temp->next;
		}
	}
}

void				close_way(t_way *way)
{
	t_way			*temp;
	t_connection	*temp1;

	temp = way;
	while (temp->next)
	{
		temp1 = temp->sosed->knot;
		while (temp1->bonds != temp->next->sosed && temp1 != NULL
			&& temp1->next != NULL)
			temp1 = temp1->next;
		if (temp1 != NULL)
			temp1->vizit = 1;
		if (temp != NULL)
			temp = temp->next;
	}
	vizit_room(way);
}

void				open_way_2(t_way *way)
{
	t_way			*temp;
	t_connection	*temp1;

	temp = way;
	while (temp->next)
	{
		temp1 = temp->sosed->knot;
		while (temp1->bonds != temp->next->sosed
			&& temp1 != NULL && temp1->next != NULL)
			temp1 = temp1->next;
		if (temp1 != NULL)
			temp1->vizit = 0;
		if (temp != NULL)
			temp = temp->next;
	}
	open_vizit(way);
}

void				open_way(t_allway *map)
{
	t_allway		*temp;

	temp = map;
	while (temp)
	{
		open_way_2(temp->go);
		temp = temp->next;
	}
}
