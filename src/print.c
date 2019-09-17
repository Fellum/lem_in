/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:13:11 by blomo             #+#    #+#             */
/*   Updated: 2019/09/16 19:13:29 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			print_ostal(t_allway *map)
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
			{
				ft_putchar('L');
				ft_putnbr(temp->nomer_ant);
				ft_putchar('-');
				ft_putstr(temp->sosed->key);
				ft_putchar(' ');
			}
			temp = temp->next;
		}
		temp_map = temp_map->next;
	}
	ft_putchar('\n');
}
