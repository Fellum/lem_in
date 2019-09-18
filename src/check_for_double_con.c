#include "lemin.h"

int		check_for_double_con(t_v *n1, t_v *n2)
{
	t_connection	*cur;

	cur = n1->knot;
	while (cur)
	{
		if (cur->bonds == n2)
			return (1);
		cur = cur->next;
	}
	return (0);
}