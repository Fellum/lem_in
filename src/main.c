/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:17:58 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/16 13:28:43 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init_mdata(t_mapdata *data)
{
	ft_bzero(data, sizeof(t_mapdata));
	data->nodes = ft_lstinit();
	data->links = ft_lstinit();
}

void	free_mdata(t_mapdata *data)
{
	free(data->links);
	free(data->nodes);
	free(data->start);
	free(data->end);
}

int	main(void)
{
	t_mapdata	mdata;

	init_mdata(&mdata);
	read_map(&mdata);
	dograf(&mdata);
	free_mdata(&mdata);
	return (0);
}
