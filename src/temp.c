/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:41:16 by blomo             #+#    #+#             */
/*   Updated: 2019/09/17 03:57:16 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	a(t_way **ochered, t_connection *temp, t_v *node)
{
	t_way			*ochered1;
	t_way			*ochered2;

	ochered2 = (t_way*)malloc(sizeof(t_way));
	ochered1 = *ochered;
	while (ochered1->next != NULL)
		ochered1 = ochered1->next;
	ochered2->sosed = temp->bonds;
	ochered2->next = NULL;
	ochered2->prev = node;
	ochered2->nomer_ant = 0;
	ochered2->status = 0;
	ochered2->revnext = ochered1;
	ochered1->next = ochered2;
	temp->bonds->is_node_one = 1;
}

void	sortirivka_way(t_allway *map)
{
	t_allway	*temp_map;
	t_allway	*temp;
	t_allway	*temp1;
	t_allway	*temp2;
	int			i;

	i = 0;
	while (i == 0)
	{
		temp_map = map;
		i = 1;
		while (temp_map && temp_map->next)
		{
			if (temp_map->size < temp_map->next->size)
			{
				temp = temp_map;
				temp1 = temp_map->next;
				if (temp_map->prev)
					temp2 = temp_map->prev;
				temp->next = temp1->next;
				temp1->next = temp;
				temp2->next = temp1;
				i = 0;
			}
			temp_map = temp_map->next;
		}
	}
}

void	count_way(t_allway *map)
{
	t_way		*temp;
	t_allway	*temp_map;
	int			i;

	i = 0;
	temp_map = map;
	while (temp_map)
	{
		i = 0;
		temp = temp_map->go;
		while (temp->next)
		{
			temp = temp->next;
			i++;
		}
		temp_map->size = i;
		temp_map = temp_map->next;
	}
}

void	count_raznica(t_allway *map)
{
	t_way		*temp;
	t_allway	*temp_map;
	int			i;

	i = 0;
	temp_map = map;
	temp_map->raznica = 0;
	while (temp_map->next)
	{
		i = temp_map->size - temp_map->next->size;
		temp_map->next->raznica = i;
		temp_map = temp_map->next;
	}
	map->naposl = temp_map;
}

void	poisk_vershin1(t_way **temp, t_v *node)
{
	*temp = (t_way*)malloc(sizeof(t_way));
	(*temp)->sosed = node;
	(*temp)->next = NULL;
	(*temp)->revnext = NULL;
	node->smezh_rebro = 1;
}
