/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_misc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:46:35 by blomo             #+#    #+#             */
/*   Updated: 2019/09/17 05:15:39 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	raise_error(int t)
{
	if (t == 1)
		ft_putstr("Error: wrong number of ants.\n");
	else if (t == 2)
		ft_putstr("Error: invalid name of a node.\n");
	else if (t == 3)
		ft_putstr("Error: wrong number of start commands.\n");
	else if (t == 4)
		ft_putstr("Error: wrong number of end commands.\n");
	else if (t == 5)
		ft_putstr("Room expected.\n");
	else if (t == 6)
		ft_putstr("Link expected.\n");
	else if (t == 7)
		ft_putstr("Double room def.\n");
	exit(1);
}

int		is_comment(const char *str)
{
	return (str[0] == '#' && str[1] != '#');
}

int		is_command(const char *str)
{
	if (str[0] == '#' && str[1] == '#')
	{
		if (ft_strcmp(str + 2, "start") == 0)
			return (1);
		else if (ft_strcmp(str + 2, "end") == 0)
			return (2);
		else
			return (-1);
	}
	return (0);
}

int		is_entirely_numeric(const char *str)
{
	while (*str != 0)
	{
		if (*str > '9' || *str < '0')
			return (0);
		str++;
	}
	return (1);
}

int		read_int(char *str)
{
	long			res;
	int				sign;
	int				treshold_dig;

	while (*str && *str == '0')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	treshold_dig = sign == 1 ? 2147483647 % 10 : (-2147483648 % 10) * -1;
	res = 0;
	while (*str && ft_isdigit(*str))
	{
		if (res > 2147483647 / 10 || (res == 2147483647 / 10 &&
				(*str - '0') > treshold_dig))
			return (1);
		res = res * 10 + (*str - '0');
		str++;
	}
	res = (int)res * sign;
	return ((int)res);
}
