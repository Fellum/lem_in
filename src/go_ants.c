/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:05:34 by blomo             #+#    #+#             */
/*   Updated: 2019/09/17 05:18:08 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	move_ants(t_allway *map)
{
	t_allway	*temp_map;
	t_way		*temp;
	int			c;

	temp_map = map;
	while (temp_map)
	{
		temp = temp_map->go;
		while (temp->next != NULL)
			temp = temp->next;
		while (temp->revnext != NULL)
		{
			c = temp->revnext->nomer_ant;
			temp->nomer_ant = c;
			temp = temp->revnext;
		}
		temp->nomer_ant = 0;
		temp_map = temp_map->next;
	}
}

int		how_much_way(t_allway *map, int ants)
{
	int			i;
	t_allway	*temp_map;

	temp_map = NULL;
	if (map->naposl != NULL)
		temp_map = map->naposl;
	i = 1;
	while (ants >= 0 && temp_map && temp_map->prev)
	{
		ants = ants - temp_map->raznica * i - 1;
		if (ants < 0)
			break ;
		i++;
		temp_map = temp_map->prev;
	}
	return (i);
}

void	first_way(t_allway *map, t_flag *fl, int i)
{
	t_allway	*temp_map;
	t_way		*temp;

	if (map->naposl != NULL)
		temp_map = map->naposl;
	while (i-- && temp_map && fl->ants)
	{
		temp = temp_map->go;
		if (temp->next->nomer_ant == 0)
			temp->next->nomer_ant = fl->p;
		fl->p++;
		fl->ants--;
		temp_map = temp_map->prev;
	}
}

int		proverka_room(t_allway *map, t_flag *fl)
{
	t_allway	*temp_map;
	t_way		*temp;

	temp_map = map;
	while (temp_map)
	{
		temp = temp_map->go;
		while (temp)
		{
			if (temp->nomer_ant != 0)
				return (-1);
			temp = temp->next;
		}
		temp_map = temp_map->next;
	}
	return (0);
}

void	go_go(t_allway *map, t_flag *fl)
{
	int			i;
	int			c;

	while (fl->ants)
	{
		i = how_much_way(map, fl->ants);
		move_ants(map);
		first_way(map, fl, i);
		print_ostal(map);
		fl->i++;
	}
	c = proverka_room(map, fl);
	while (c-- != 0)
	{
		move_ants(map);
		print_ostal(map);
		fl->i++;
		c = proverka_room(map, fl);
	}
}

void	go_ants(t_allway *map_oneway, t_allway *map, t_flag *fl)
{
	int i;

	if (map == NULL)
		return ;
	count_way(map);
	sortirivka_way(map);
	count_raznica(map);
	count_way(map_oneway);
	sortirivka_way(map_oneway);
	count_raznica(map_oneway);
	i = how_much_way(map, fl->ants);
	fl->p = 1;
	fl->i = 0;
	if (i == 1)
		go_go(map_oneway, fl);
	else
		go_go(map, fl);
	printf("%d\n\n", fl->i);
}
