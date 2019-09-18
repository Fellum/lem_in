/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_graf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:32:29 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/17 03:18:53 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	dograf(t_mapdata *p)
{
	t_flag			*fl;
	t_v				*hashtab[p->nodes->len];
	t_list_node		*cur;
	int				i;

	if (!(fl = (t_flag*)malloc(sizeof(t_flag))))
		return ;
	init_fl(fl);
	fl->hash_nbr = p->nodes->len;
	hashtab_init(hashtab, p->nodes->len);
	i = 0;
	while (p->nodes->len != 0)
	{
		cur = ft_lsttake(p->nodes);
		hashtab_add(hashtab, cur->content, i++, fl->hash_nbr);
		free(cur->content);
		free(cur);
	}
	doconnect(hashtab, fl, p);
}

void	copydominus(t_flag *fl, char *str)
{
	int				i;

	fl->c = 0;
	i = 0;
	while (str[i] != '-')
	{
		fl->temp[i] = str[i];
		i++;
	}
	fl->temp[i] = '\0';
	i++;
	fl->c = i;
}

void	copyposleminus(t_flag *fl, char *str)
{
	int				i;

	i = 0;
	while (str[fl->c] != '\0')
	{
		fl->temp1[i] = str[fl->c];
		fl->c++;
		i++;
	}
	fl->temp1[i] = '\0';
}

void	list_with_connect(t_v *node, t_v *node1)
{
	t_connection	*tt;
	t_connection	*ptr;

	if (!(tt = (t_connection*)malloc(sizeof(t_connection))))
		return ;
	if (node->knot == NULL)
	{
		node->knot = tt;
		tt->bonds = node1;
		tt->next = NULL;
		tt->vizit = 0;
	}
	else
	{
		ptr = node->knot;
		while (ptr->next)
			ptr = ptr->next;
		tt->bonds = node1;
		tt->vizit = 0;
		tt->next = NULL;
		ptr->next = tt;
	}
}

void	doconnect(t_v **hashtab, t_flag *fl, t_mapdata *p)
{
	t_v				*node;
	t_v				*node1;
	t_list_node		*cur;

	fl->p = -1;
	while (p->links->len)
	{
		fl->k = 0;
		cur = ft_lsttake(p->links);
		copydominus(fl, cur->content);
		copyposleminus(fl, cur->content);
		node = hashtab_lookup(hashtab, fl->temp, fl->hash_nbr);
		node1 = hashtab_lookup(hashtab, fl->temp1, fl->hash_nbr);
		if (node == node1 || node == NULL || node1 == NULL)
			raise_error(6);
		if (check_for_double_con(node, node1))
			raise_error(7);
		list_with_connect(node, node1);
		list_with_connect(node1, node);
		free(cur->content);
		free(cur);
	}
	fl->ants = p->ants;
	ft_multyway(hashtab, p->start, p->end, fl);
}
