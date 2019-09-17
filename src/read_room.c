//
// Created by Jasper Leann on 16/09/2019.
//

#include "lemin.h"

void	raise_error(int t);

int		is_room(const char *str)
{
	int i;

	i = 1;
	if (str[0] == 'L' || str[0] == '#')
		return (0);
	while (str[i] != ' ' && str[i])
		i++;
	if (str[i])
		i++;
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	else
		return (0);
	if (str[i++] != ' ')
		return (0);
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	else
		return (0);
	return (str[i] == 0);
}

int		is_unique(t_list *lst, const char *str)
{
	t_list_node *cur;

	cur = lst->begin;
	while (cur)
	{
		if (ft_strcmp(cur->content, str) == 0)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	read_room(t_mapdata *mdata, char *str, int *cmd_type)
{
	*(ft_strchr(str, ' ')) = 0;
	if (*cmd_type == 1)
	{
		if (mdata->start == NULL)
			mdata->start = ft_strdup(str);
		else
			raise_error(3);
	}
	else if (*cmd_type == 2)
	{
		if (mdata->end == NULL)
			mdata->end = ft_strdup(str);
		else
			raise_error(4);
	}
	*cmd_type = 0;
	if (!is_unique(mdata->nodes, str))
		raise_error(7);
	ft_lstaddend(mdata->nodes, ft_lstnew_node(str, ft_strlen(str) + 1));
}
