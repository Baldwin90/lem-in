/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:06:53 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:06:54 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <libft.h>

/*
** Error Codes:
** 1	invalid arg count
** 2	unable to allocate r_data memory
** 3	unable to allocate arraylist memory;
** 4	issue opening file
** 5	found empty line in input
** 6	ant data is not first
** 7	needs to have 2 spaces
** 8	room name starting with 'L' or contains a dash
** 9	duplicate name
** 10	colliding rooms
** 11	non-numeric characters in x or y data
** 12	unable to make new room
** 13	issue adding to array list
** 14	multiple start points
** 15	multiple end points
** 16	start and/or end not set before reaching linkage phase
** 17	needs to have 1 dash
** 18	room attempting to be linked doesn't exist in list
** 19	rooms are the same name
** 20	rooms are linked twice
** 21	incorrect number of fields
** 22	issue reading from file pointer
** 23	not all necessary parts are in the file
*/

# define FL if(v->line != NULL){free(v->line);} v->line = NULL;
# define FF_START if(v->fields){for
# define FF_END1 (int i=0;v->fields[i];i+=1){free(v->fields[i]);}
# define FF_END2 free(v->fields);};
# define FF FF_START FF_END1 FF_END2 v->fields = NULL;
# define CF(a, b, c, d) if(v->fd && close(v->fd)==-1){li_e(a+1000,b,c,d);};
# define ERROR(a, b, c, d) {FL FF CF(a,b,c,d) li_e(a,b,c,d);}

typedef enum	e_ntype
{
	NT_START,
	NT_NORMAL,
	NT_END
}				t_ntype;

typedef struct	s_node
{
	t_arraylist	*nodes;
	t_arraylist	*route;
	char		*name;
	t_ntype		type;
	int			x;
	int			y;
	int			dist;
}				t_node;

void			create_node_link(t_node *n1, t_node *n2);
t_node			*new_node(char *name, t_ntype type, int x, int y);

void			route_sort(t_arraylist *route);

typedef struct	s_puz
{
	int			ants;
	t_arraylist	*routes;
}				t_puz;

t_puz			*new_puz(int ants);

typedef struct	s_r_data {
	int			ants;
	t_arraylist	*list;
	t_node		*start;
	t_node		*end;
	int			has_links;
}				t_r_data;

typedef struct	s_reader_master
{
	int			fd;
	int			gnl_res;
	int			f_count;
	int			cmd;
	int			e_nbr;
	char		*line;
	char		**fields;
	t_ntype		type;
	t_r_data	*rd;
}				t_reader_master;

typedef struct	s_cds_master
{
	t_arraylist *cmds;
	t_arraylist *direction;
	int			route_idx;
	int			cmd_idx;
	int			cmd_len;
	int			ant_idx;
}				t_cds_master;

typedef struct	s_create_routes_master
{
	int			search;
	char		flag;
	t_arraylist	*nodes;
	int			a;
	int			b;
}				t_create_routes_master;

# define ARRL t_arraylist

t_arraylist		*create_direction_set(t_puz *puz);
void			ant_movement_gen(char *a, ARRL *b, int c, ARRL *d);
int				create_routes(t_r_data *rd, t_arraylist *routes);

# undef ARRL

void			free_puz(t_puz *puz);
void			routes_free(t_arraylist *routes);
void			node_free(t_node *node);
void			r_data_free(t_r_data *rd);
void			li_e(int e, t_r_data *a, t_puz *p, t_arraylist *m);
t_node			*name_search(char *needle, t_arraylist *nodes);
int				s_room(char **fields, t_ntype type, t_r_data *rd);
int				route_exists(t_node *r1, t_node *r2);
int				linker(char **fields, t_r_data *rd);
t_reader_master	*init_reader_master(void);
int				directly_linked(t_r_data *rd);

void			reader(int argc, char **argv, t_r_data **r_data);
int				add_link(char **fields, t_r_data *rd);
int				store_room(char **fields, t_ntype type, t_r_data *rd);
#endif
