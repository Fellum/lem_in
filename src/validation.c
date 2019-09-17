/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:29:43 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/17 03:21:40 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	raise_error(int t);
int is_comment(const char *str);
int is_command(const char *str);
int	is_entirely_numeric(const char *str);
int		read_int(char *str);
int		is_room(const char *str);
void	read_room(t_mapdata *mdata, char *str, int *cmd_type);
int is_link(const char *str);
void	read_link(t_mapdata *mdata, char *str);
void print_mdata(t_mapdata *data);
int fd;

void	get_ants_num(t_mapdata *mdata)
{
	char	*line;
	int		res;
	while (ft_get_next_line(fd, &line) == GNL_SUCCESS)
	{
		if (is_comment(line))
		{
			free(line);
			continue ;
		}
		if (!is_entirely_numeric(line))
			raise_error(1);
		res = read_int(line);
		if (res <= 0)
			raise_error(1);
		free(line);
		mdata->ants = res;
		break ;
	}
}

void	get_nodes(t_mapdata *mdata)
{
	char	*line;
	int 	cmd_type;

	while (ft_get_next_line(fd, &line) == GNL_SUCCESS)
	{
		if (is_room(line))
			read_room(mdata, line, &cmd_type);
		else if ((cmd_type = is_command(line)))
		{
			if (cmd_type == -1)
				raise_error(5);
		}
		else if (is_link(line))
		{
			read_link(mdata, line);
			free(line);
			break ;
		}
		else if (!is_comment(line))
			raise_error(5);
		free(line);
	}
}

void	get_links(t_mapdata *mdata)
{
	char	*line;

	while (ft_get_next_line(fd, &line) == GNL_SUCCESS)
	{
		if (is_link(line))
			read_link(mdata, line);
		else if (!is_comment(line))
			raise_error(6);
		free(line);
	}
}

void	read_map(t_mapdata *mdata)
{
	//fd = open("../misc/map9",O_RDONLY);
	get_ants_num(mdata);
	get_nodes(mdata);
	get_links(mdata);
	print_mdata(mdata);
}