/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ochered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:01:45 by blomo             #+#    #+#             */
/*   Updated: 2019/09/17 03:31:46 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			check_ocher(t_way *dest, t_way *src)
{
	if (dest->sosed == NULL)
		return (1);
	while (src)
	{
		if (!ft_strcmp(dest->sosed->key, src->sosed->key))
			return (0);
		src = src->next;
	}
	return (1);
}

int			proverka_end(t_way *ochered, char *str)
{
	while (ochered)
	{
		if (!ft_strcmp(ochered->sosed->key, str))
			return (0);
		ochered = ochered->next;
	}
	return (1);
}

void		proverka_smezhreber(t_way *ochered, t_flag *fl)
{
	t_way	*temp;

	fl->i = 0;
	temp = ochered;
	while (temp)
	{
		if (temp->sosed->smezh_rebro == 1)
			fl->i++;
		if (fl->i == 2)
		{
			fl->k = 0;
			temp->status = 1;
			temp->sosed->smezh_rebro = 2;
			temp = ochered;
			while (temp)
			{
				if (temp->sosed->smezh_rebro == 1)
				{
					temp->sosed->smezh_rebro = 2;
					break ;
				}
				temp = temp->next;
			}
			break ;
		}
		temp = temp->next;
	}
}

t_way		*ft_way(t_v **hashtab, char *start, char *end, t_flag *fl)
{
	t_v		*node;
	t_way	*ochered;
	t_way	*temp;
	t_way	*way;

	temp = NULL;
	node = hashtab_lookup(hashtab, start, fl->hash_nbr);
	create_ochered(&ochered);
	ochered->sosed = node;
	temp = ochered;
	if(temp == NULL)
		del_map(&ochered);
	while (temp)
	{
		if (temp->status == 0)
		{
			doo(hashtab, temp->sosed->key, &ochered, fl);
			temp->status = 1;
		}
		if (fl->poisk == 0)
			proverka_smezhreber(ochered, fl);
		if (!proverka_end(ochered, end))
		{
			fl->c = 1;
			break ;
		}
		temp = temp->next;
		fl->c = 0;
	}
	return (ochered);
}
