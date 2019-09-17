/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilization_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:44:45 by blomo             #+#    #+#             */
/*   Updated: 2019/09/17 01:29:09 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init_fl(t_flag *fl)
{
	fl->p = 0;
	fl->c = 0;
	fl->k = 0;
	fl->i = 0;
	fl->j = 0;
	fl->poisk = 0;
	fl->ants = 0;
	fl->line = 0;
	fl->status = 0;
	fl->hash_nbr = 0;
	ft_bzero(fl->temp, 100);
	ft_bzero(fl->temp1, 100);
	fl->ptr = NULL;
	fl->ptr1 = NULL;
}

void	create_ochered(t_way **ochered)
{
	if (!(*ochered = (t_way*)malloc(sizeof(t_way))))
		return ;
	(*ochered)->status = 0;
	(*ochered)->poryadok = 0;
	(*ochered)->revnext = NULL;
	(*ochered)->prev = NULL;
	(*ochered)->number = 0;
	(*ochered)->nomer_ant = 0;
	(*ochered)->sosed = NULL;
	(*ochered)->next = NULL;
}
