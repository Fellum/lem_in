/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:09:10 by blomo             #+#    #+#             */
/*   Updated: 2019/09/17 03:43:56 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				del_connect(t_connection **ptr)
{
	t_connection	*temp;

	while (*ptr)
	{
		temp = (*ptr)->next;
		(*ptr)->vizit = 0;
		(*ptr)->next = NULL;
		(*ptr)->bonds = NULL;
		free(*ptr);
		(*ptr) = temp;
	}
	ptr = NULL;
}

void				del_hash(t_v **hashtab, int i)
{
	t_v				*temp;
	t_v				*temp1;
	t_connection	*tt;

	while (--i >= 0)
	{
		temp = hashtab[i];
		while (temp)
		{
			tt = temp->knot;
			del_connect(&tt);
			temp1 = temp->next;
			free(temp->key);
			temp->value = 0;
			temp->vizit = 0;
			temp->smezh_rebro = 0;
			temp->knot = NULL;
			temp->next = NULL;
			temp->is_node_one = 0;
			free(temp);
			temp = temp1;
		}
		hashtab[i] = NULL;
	}
}

void				del_map(t_way **map)
{
	t_way			*temp;

	if (*map == NULL)
		return ;
	while (*map)
	{
		temp = (*map)->next;
		(*map)->sosed = NULL;
		(*map)->next = NULL;
		(*map)->revnext = NULL;
		(*map)->prev = NULL;
		(*map)->poryadok = 0;
		(*map)->status = 0;
		(*map)->number = 0;
		(*map)->nomer_ant = 0;
		free(*map);
		(*map) = temp;
	}
	map = NULL;
}

void				del_allmap(t_allway **map)
{
	t_allway		*temp;
	t_way			*tt;

	while (*map)
	{
		temp = (*map)->next;
		tt = (*map)->go;
		del_map(&tt);
		(*map)->go = NULL;
		(*map)->next = NULL;
		(*map)->prev = NULL;
		(*map)->naposl = NULL;
		(*map)->size = 0;
		(*map)->raznica = 0;
		free(*map);
		(*map) = temp;
	}
	map = NULL;
}
