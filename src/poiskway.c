/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poiskway.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:46:35 by blomo             #+#    #+#             */
/*   Updated: 2019/09/17 05:15:39 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			one_of_map(t_allway **map, t_way *temp1)
{
	if (!(*map = (t_allway*)malloc(sizeof(t_allway))))
		return ;
	(*map)->go = temp1;
	(*map)->next = NULL;
	(*map)->prev = NULL;
	(*map)->naposl = NULL;
	(*map)->size = 0;
	(*map)->raznica = 0;
}

void			more_of_map(t_allway **map, t_way *temp1)
{
	t_allway	*map1;
	map1 = NULL;

	if (!(map1 = (t_allway*)malloc(sizeof(t_allway))))
		return ;
	map1->go = NULL;
	map1->next = NULL;
	map1->prev = NULL;
	map1->size = 0;
	map1->raznica = 0;

	map1->go = temp1;
	map1->next = *map;
	map1->naposl = NULL;
	map1->size = 0;
	map1->raznica = 0;

	(*map)->prev = map1;
	*map = map1;
	
}

t_allway		*create_map(t_v **hashtab, char *start, char *end, t_flag *fl)
{
	t_allway	*map;
	t_way		*temp;
	t_way		*temp1;
	
	map = NULL;
	temp1 = NULL;
	fl->k = 1;
	while (fl->c)
	{
		temp = ft_way(hashtab, start, end, fl);
		if (fl->c)
		{
			// if (temp1 != NULL)
			// 	del_map(&temp1);
			temp1 = create_smallway(temp, end);
			if (temp)
				del_map(&temp);
			close_way(temp1);
		}
		else
		{
			if (temp)
				del_map(&temp);
		}
		if (map == NULL)
		{
			if (fl->c)
				one_of_map(&map, temp1);
		}
		else
		{
			if (fl->c)
				more_of_map(&map, temp1);
		}
	}
	// if (temp1 != NULL)
	// 	del_map(&temp1);
	return (map);
}

t_allway		*create_smal(t_v **hashtab, char *start, char *end, t_flag *fl)
{
	t_allway	*map;
	t_way		*temp;
	t_way		*temp1;

	if (!(map = (t_allway*)malloc(sizeof(t_allway))))
		return (NULL);
	map->go = NULL;
	map->next = NULL;
	map->prev = NULL;
	map->size = 0;
	map->raznica = 0;
	temp = ft_way(hashtab, start, end, fl);
	temp1 = create_smallway(temp, end);
	del_map(&temp);
	map->go = temp1;
	map->next = NULL;
	open_way(map);
	fl->c = 1;
	fl->poisk = 0;
	return (map);
}

void			podschet_reber(t_way *rebra, t_allway *map, t_flag *fl)
{
	t_way		*temp;
	int			z;

	z = 0;
	temp = rebra;
	while (temp)
	{
		z++;
		temp = temp->next;
	}
	if (z > 10)
	{
		fl->poisk = -1;
		open_way(map);
	}
	else
	{
		open_way(map);
		close_rebra(rebra);
	}
	fl->c = 1;
}

void			ft_multyway(t_v **hashtab, char *start, char *end, t_flag *fl)
{
	t_allway	*map;
	t_allway	*map2;
	t_way		*rebra;
	int			i;
	
	map2 = create_smal(hashtab, start, end, fl);
	map = create_map(hashtab, start, end, fl);
	rebra = poisk_vershin_s_indeksom_2(hashtab, fl);
	podschet_reber(rebra, map, fl);
	del_allmap(&map);
	
	map = create_map(hashtab, start, end, fl);
	go_ants(map2, map, fl);
	del_hash(hashtab, fl->hash_nbr);
	del_allmap(&map2);
	del_allmap(&map);
	del_map(&rebra);
	free(fl);
}
