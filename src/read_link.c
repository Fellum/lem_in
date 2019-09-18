/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:46:35 by blomo             #+#    #+#             */
/*   Updated: 2019/09/17 05:15:39 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_link(const char *str)
{
	char *tmp;

	if (str[0] == '#')
		return (0);
	tmp = ft_strchr(str, '-');
	if (tmp == NULL || tmp == str)
		return (0);
	return (1);
}

void	read_link(t_mapdata *mdata, char *str)
{
	ft_lstaddend(mdata->links, ft_lstnew_node(str, ft_strlen(str) + 1));
}
