/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poisk_vershin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:06:16 by blomo             #+#    #+#             */
/*   Updated: 2019/09/16 19:32:24 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		poisk_vershin2(t_way **temp, t_v *node)
{
	t_way	*temp1;

	temp1 = (t_way*)malloc(sizeof(t_way));
	temp1->sosed = node;
	temp1->next = *temp;
	(*temp)->revnext = temp1;
	(*temp) = temp1;
	node->smezh_rebro = 1;
}

void		poisk_vershin3(t_way **temp, t_v *hashtab2)
{
	*temp = (t_way*)malloc(sizeof(t_way));
	(*temp)->sosed = hashtab2->next;
	hashtab2->next->smezh_rebro = 1;
	(*temp)->next = NULL;
	(*temp)->revnext = NULL;
}

void		poisk_vershin4(t_way **temp, t_v *hashtab2)
{
	t_way *temp1;

	temp1 = (t_way*)malloc(sizeof(t_way));
	temp1->sosed = hashtab2->next;
	hashtab2->next->smezh_rebro = 1;
	temp1->next = *temp;
	(*temp)->revnext = temp1;
	(*temp) = temp1;
}

void		poisk_vershin5(t_way **temp, t_v *hashtab2)
{
	if (hashtab2)
	{
		while (hashtab2->next != NULL)
		{
			if (hashtab2->next->vizit == 2)
			{
				if (*temp == NULL)
					poisk_vershin3(temp, hashtab2);
				else
					poisk_vershin4(temp, hashtab2);
			}
			hashtab2 = hashtab2->next;
		}
	}
}

t_way		*poisk_vershin_s_indeksom_2(t_v **hashtab, t_flag *fl)
{
	t_way	*temp;
	t_v		**hashtab1;
	t_v		*hashtab2;
	int		i;

	temp = NULL;
	i = 0;
	hashtab1 = hashtab;
	while (i < fl->hash_nbr)
	{
		if (hashtab1[i])
		{
			if (hashtab1[i]->vizit == 2)
			{
				if (temp == NULL)
					poisk_vershin1(&temp, hashtab1[i]);
				else
					poisk_vershin2(&temp, hashtab1[i]);
			}
			poisk_vershin5(&temp, hashtab[i]);
		}
		i++;
	}
	return (temp);
}
