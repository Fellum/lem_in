#include "lemin.h"

int is_link(const char *str)
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
