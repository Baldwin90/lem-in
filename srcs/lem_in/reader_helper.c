/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:06:53 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:06:54 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define R return
#define S_ROOM_VARS t_node *room;t_node *cur_room;int x;int y;int i;
#define SR1 else{R(11);}if(!(room=new_node(fields[0],type,x,y))){R(12);}
#define SR2 if (arraylist_add(rd->list, room) == FALSE){return (13);}
#define SR3 if(type==NT_START){if(rd->start!= NULL){R(14);}rd->start=room;}
#define SR4 else if(type==NT_END){if(rd->end!=NULL){R(15);}rd->end=room;}
#define SRM SR1 SR2 SR3 SR4;

t_node			*name_search(char *needle, t_arraylist *nodes)
{
	t_node	*room;
	int		i;
	int		size;

	if (!nodes)
		return (NULL);
	i = -1;
	size = nodes->size;
	while (++i < size)
	{
		room = (t_node*)nodes->data[i];
		if (ft_strcmp(needle, room->name) == 0)
		{
			return (nodes->data[i]);
		}
	}
	return (NULL);
}

/*
** this goes in the while loop under line 70
** if (x == cur_room->x && y == cur_room->y)
** 	return (10)
*/

int				s_room(char **fields, t_ntype type, t_r_data *rd)
{
	S_ROOM_VARS;
	if (fields[0][0] == 'L' || ft_char_tot(fields[0], '-'))
		return (8);
	if (name_search(fields[0], rd->list))
		return (9);
	if (ft_isnumeric(&fields[1][(fields[1][0] != '-' ? 0 : 1)]) &&\
		ft_isnumeric(&fields[2][(fields[2][0] != '-' ? 0 : 1)]))
	{
		x = ft_atoi(fields[1]);
		y = ft_atoi(fields[2]);
		i = -1;
		while (++i < rd->list->size)
		{
			cur_room = (t_node*)rd->list->data[i];
		}
	}
	SRM;
	return (0);
}

int				route_exists(t_node *r1, t_node *r2)
{
	int	i;
	int	limit;

	i = -1;
	limit = r1->nodes->size;
	while (++i < limit)
	{
		if (r2 == r1->nodes->data[i])
		{
			return (TRUE);
		}
	}
	return (FALSE);
}

/*
** change line 114 to 20 to enable the error code
*/

int				linker(char **fields, t_r_data *rd)
{
	t_node	*r1;
	t_node	*r2;

	if (!(r1 = name_search(fields[0], rd->list)) ||\
		!(r2 = name_search(fields[1], rd->list)))
	{
		return (18);
	}
	if (r1 == r2)
	{
		return (19);
	}
	if (route_exists(r1, r2))
	{
		return (0);
	}
	rd->has_links = 1;
	create_node_link(r1, r2);
	return (0);
}

t_reader_master	*init_reader_master(void)
{
	static t_reader_master	v;

	v.fd = 0;
	v.gnl_res = 0;
	v.f_count = 0;
	v.cmd = 0;
	v.e_nbr = 0;
	v.line = NULL;
	v.fields = NULL;
	v.rd = NULL;
	return (&v);
}
