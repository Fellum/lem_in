/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:17:06 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/17 01:46:43 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft.h"
# include <string.h>
# define BUF_MAX 10260
#define HASHTAB_MUL 31
# include <fcntl.h>
#include <stdio.h>
# include <sys/types.h>

typedef struct	s_mapdata
{
	int		ants;
	char	*start;
	char	*end;
	t_list	*nodes;
	t_list	*links;
}				t_mapdata;

typedef struct	s_flag
{
	int			p;
	int			c;
	int			k;
	int			i;
	int			j;
	int			poisk;
	int 		ants;
	int			line;
	int			status;
	int			hash_nbr;
	char		temp[100];
	char		temp1[100];
	char		*ptr;
	char		*ptr1;
}				t_flag;

typedef struct	s_connection
{
	struct s_v	*bonds; // нода с которой связь
	struct s_connection	*next;
	int			vizit;
}				t_connection;

typedef struct	s_v
{
	char		*key;
	int			value;
	int			vizit;
	int smezh_rebro;
	struct s_connection	*knot; // указатель на ноду с которой связь
	struct s_v	*next;
	int is_node_one;
}				t_v;

typedef struct	s_way
{
	struct s_v		*sosed;
	struct s_way	*next;
	struct s_way	*revnext;
	struct s_v		*prev;
	int				poryadok;
	int				status;
	int				number;
	int				nomer_ant;
}					t_way;

typedef struct s_allway
{
	struct s_way    *go;
	struct s_allway *next;
	struct s_allway *prev;
	struct s_allway *naposl;
	int size;
	int raznica;
}t_allway;

void			read_map(t_mapdata *p);
int				hashtab_hash(char *key, int n);
void			hashtab_init(t_v **hashtab, int n);
void			hashtab_add(t_v **hashtab, char *key, int value, int n);
t_v				*hashtab_lookup(t_v **hashtab, char *key, int n);
void			doconnect(t_v **hashtab, t_flag *fl, t_mapdata *p);//char **str1, int n1);
t_way			*ft_way(t_v **hashtab, char *start, char *end, t_flag *fl);
void			ft_bzero(void *str, size_t len);
void			dograf(t_mapdata *p);//char **str, int n, char **str1, int n1);
t_way  			*create_smallway(t_way *ochered, char *str);
void			close_way(t_way *way);
void			ft_multyway(t_v **hashtab, char *start, char *end, t_flag *fl);
t_way *poisk_vershin_s_indeksom_2(t_v **hashtab,t_flag *fl);
void    open_way(t_allway *map);
void close_rebra(t_way *rebra);
void go_ants(t_allway  *map_oneway, t_allway  *map , t_flag *fl);

void del_connect(t_connection **ptr);
void del_hash(t_v **hashtab,int i);
void del_map(t_way **map);
void del_allmap(t_allway **map);

void init_fl(t_flag *fl);
void create_ochered(t_way **ochered);
void doo(t_v **hashtab, char *start, t_way **ochered, t_flag *fl);
int check_ocher(t_way *dest, t_way *src);
void				a(t_way **ochered, t_connection *temp, t_v *node);
void			print_ostal(t_allway *map);
void			sortirivka_way(t_allway *map);
void			count_way(t_allway *map);
void			count_raznica(t_allway *map);



void poisk_vershin1(t_way **temp, t_v *node);

#endif
