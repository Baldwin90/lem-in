/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:06:53 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:06:54 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>

#define CRVAR1 t_node *node = v->nodes->data[v->a];
#define CRVAR2 t_node *target_node = node->nodes->data[v->b];
#define CRVAR3 t_node *node = v->nodes->data[v->a];
#define CRVAR4HELPER data[routes->size-1])->data[v->b]
#define CRVAR4 t_node *target=((t_arraylist *)routes->CRVAR4HELPER;
#define LEMCRM t_create_routes_master

static LEMCRM	*init_create_route_master(void)
{
	static t_create_routes_master	v;

	return (&v);
}

static void		cr2(LEMCRM *v, t_r_data *rd, t_arraylist *routes)
{
	arraylist_add(routes, arraylist_clone(rd->end->route));
	v->a = -1;
	while (++(v->a) < v->nodes->size)
	{
		CRVAR3;
		v->b = -1;
		while (++(v->b) < ((t_arraylist *)routes->data[routes->size - 1])->size)
		{
			CRVAR4;
			if (target->type == NT_NORMAL)
			{
				arraylist_del(node->nodes, target);
			}
		}
		if (node->type != NT_START)
		{
			node->dist = -1;
			if (node->route)
			{
				arraylist_free(node->route);
				node->route = 0;
			}
		}
	}
}

static void		cr1(t_create_routes_master *v)
{
	while (v->flag)
	{
		++(v->search);
		v->flag = 0;
		v->a = -1;
		while (++(v->a) < v->nodes->size)
		{
			CRVAR1;
			if (node->dist != v->search)
				continue ;
			v->b = -1;
			while (++(v->b) < node->nodes->size)
			{
				CRVAR2;
				if (target_node->dist != -1)
					continue ;
				target_node->dist = v->search + 1;
				target_node->route = arraylist_clone(node->route);
				arraylist_add(target_node->route, target_node);
				v->flag = 1;
			}
		}
	}
}

int				create_routes(t_r_data *rd, t_arraylist *routes)
{
	t_create_routes_master	*v;

	v = init_create_route_master();
	v->nodes = rd->list;
	while (TRUE)
	{
		v->search = -1;
		if (directly_linked(rd))
		{
			while (++(v->search) < rd->ants)
			{
				ft_printf("%sL%i-%s", v->search ? " " : "", v->search,\
					((t_node *)rd->end)->name);
			}
			ft_printf("\n");
			return (1);
		}
		v->flag = 1;
		cr1(v);
		if (rd->end->route)
			cr2(v, rd, routes);
		else
			break ;
	}
	return (0);
}
