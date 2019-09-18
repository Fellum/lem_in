/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mdata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:13:11 by blomo             #+#    #+#             */
/*   Updated: 2019/09/16 19:13:29 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"

void	print_mdata(t_mapdata *data)
{
	t_list_node	*cur;

	ft_printf("%d\n", data->ants);
	ft_printf("##start\n");
	ft_printf("%s\n", data->start);
	ft_printf("##end\n");
	ft_printf("%s\n", data->end);
	cur = data->nodes->begin;
	while (cur)
	{
		ft_printf("%s\n", cur->content);
		cur = cur->next;
	}
	cur = data->links->begin;
	while (cur)
	{
		ft_printf("%s\n", cur->content);
		cur = cur->next;
	}
}
