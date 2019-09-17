/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ochered.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:08:37 by blomo             #+#    #+#             */
/*   Updated: 2019/09/17 01:14:54 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				b(t_way **ochered, t_connection *temp, t_v *node)
{
	t_way			*ochered1;
	t_way			*ochered2;

	ochered2 = (t_way*)malloc(sizeof(t_way));
	ochered1 = *ochered;
	while (ochered1->next != NULL)
		ochered1 = ochered1->next;
	ochered2->sosed = temp->bonds;
	if (check_ocher(ochered2, *ochered))
	{
		ochered2->next = NULL;
		ochered2->prev = node;
		ochered2->status = 0;
		ochered2->nomer_ant = 0;
		ochered2->revnext = ochered1;
		ochered1->next = ochered2;
	}
	else
		free(ochered2);
}

t_way				*poisk_node_v_ochered(t_way **ochered, t_v *node)
{
	t_way			*ptr;

	ptr = *ochered;
	while (ptr->sosed != node && ptr)
		ptr = ptr->next;
	return (ptr);
}

int					one_from(t_way *ptr, t_v *node, t_way **ochered)
{
	t_connection	*temp;

	temp = node->knot;
	while (temp != NULL && temp->bonds->vizit != 1)
	{
		if (ft_strcmp(temp->bonds->key, (*ochered)->sosed->key) == 0)
		{
			if (temp->vizit == 0)
				break ;
		}
		temp = temp->next;
	}
	if (temp)
	{
		if (temp->bonds->vizit == 1)
			a(ochered, temp, node);
		return (1);
	}
	return (0);
}

void				doo1(t_connection *temp, t_way **oc, t_v *node, t_flag *fl)
{
	temp = node->knot;
	if (node->vizit == 2)
		return ;
	while (temp)
	{
		if (fl->poisk == 0)
		{
			if (temp->vizit == 0 && temp->bonds->vizit != 2)
				b(oc, temp, node);
		}
		else
		{
			if (temp->vizit == 0 && temp->bonds->vizit == 0)
				b(oc, temp, node);
		}
		temp = temp->next;
	}
}

void				doo(t_v **hashtab, char *start, t_way **ochered, t_flag *fl)
{
	t_connection	*temp;
	t_v				*node;
	t_way			*ptr;

	node = hashtab_lookup(hashtab, start, fl->hash_nbr);
	if (node->knot)
	{
		if (node->vizit == 1 && node->is_node_one == 0)
		{
			ptr = poisk_node_v_ochered(ochered, node);
			if (ptr->prev->vizit == 0 && one_from(ptr, node, ochered) == 1)
				return ;
			else if (ptr->prev->vizit == 1)
			{
				temp = node->knot;
				while (temp)
				{
					if (temp->vizit == 0 && temp->bonds->vizit != 2)
						b(ochered, temp, node);
					temp = temp->next;
				}
			}
		}
		doo1(temp, ochered, node, fl);
	}
}
