/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hashtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:46:03 by blomo             #+#    #+#             */
/*   Updated: 2019/09/17 00:48:47 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			hashtab_hash(char *key, int n)
{
	size_t	h;
	char	*p;

	h = 0;
	p = key;
	while (*p)
	{
		h = h * HASHTAB_MUL + (int)*p;
		p++;
	}
	return (h % n);
}

void		hashtab_init(t_v **hashtab, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		hashtab[i] = NULL;
		i++;
	}
}

void		hashtab_add(t_v **hashtab, char *key, int value, int n)
{
	t_v		*node;
	t_v		*temp;
	int		index;

	index = hashtab_hash(key, n);
	node = malloc(sizeof(*node));
	ft_bzero(node, sizeof(t_v));
	node->key = ft_strdup(key);
	node->value = value;
	if (hashtab[index] == NULL)
	{
		node->next = NULL;
		node->knot = NULL;
		node->vizit = 0;
		node->smezh_rebro = 0;
		hashtab[index] = node;
	}
	else
	{
		temp = hashtab[index];
		node->next = NULL;
		node->knot = NULL;
		node->vizit = 0;
		node->smezh_rebro = 0;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}
}

t_v			*hashtab_lookup(t_v **hashtab, char *key, int n)
{
	int		index;
	t_v		*node;

	index = hashtab_hash(key, n);
	node = hashtab[index];
	while (node != NULL)
	{
		if (ft_strcmp(node->key, key) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}
