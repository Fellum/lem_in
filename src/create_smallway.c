/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_smallway.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:45:51 by blomo             #+#    #+#             */
/*   Updated: 2019/09/17 03:38:29 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				flag_creatsmall(t_way **ochered, t_way **way)
{
	t_way			*tempway;
	t_way			*temp;

	tempway = (t_way*)malloc(sizeof(t_way));
	temp = (*ochered);
	while ((*ochered)->sosed != temp->prev && (*ochered)->revnext != NULL)
		*ochered = (*ochered)->revnext;
	tempway->sosed = (*ochered)->sosed;
	tempway->next = *way;
	(*way)->revnext = tempway;
	(*way) = tempway;
	(*way)->nomer_ant = 0;
}

t_way				*create_smallway(t_way *ochered, char *str)
{
	t_way			*way;
	t_way			*temp;
	t_way			*tempway;
	
	if(ochered != NULL)
		create_ochered(&way);
	while (ochered->next)
	{
		if (!ft_strcmp(ochered->sosed->key, str))
			break ;
		ochered = ochered->next;
	}
	way->sosed = ochered->sosed;
	while (ochered->revnext)
	{
		flag_creatsmall(&ochered, &way);
		if (ochered->revnext == NULL)
		{
			way->revnext = NULL;
			way->nomer_ant = 0;
			break ;
		}
	}
	return (way);
}

void				close_rebra(t_way *rebra)
{
	t_way			*temp;
	t_way			*temp1;
	t_connection	*connect;

	temp = rebra;
	while (temp)
	{
		connect = temp->sosed->knot;
		while (connect)
		{
			temp1 = rebra;
			while (temp1)
			{
				if (connect->bonds == temp1->sosed)
					connect->vizit = 1;
				temp1 = temp1->next;
			}
			connect = connect->next;
		}
		temp = temp->next;
	}
}
