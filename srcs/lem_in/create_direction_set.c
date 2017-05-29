/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_direction_set.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:06:53 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:06:54 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>

static t_cds_master	*init_cds_master(void)
{
	static t_cds_master	v;

	return (&v);
}

static void			cds_extended(t_cds_master *v, t_puz *puz)
{
	while (++(v->ant_idx) < puz->ants)
	{
		++(v->route_idx);
		if (v->route_idx >= v->direction->size)
		{
			v->route_idx = 0;
			++(v->cmd_idx);
		}
		else if (v->route_idx != 0)
		{
			if ((puz->ants - v->ant_idx) / (v->route_idx + 1) + \
				((t_arraylist *)v->direction->data[v->route_idx])->size >\
				(puz->ants - v->ant_idx) / (v->route_idx) + ((t_arraylist *)\
				v->direction->data[v->route_idx - 1]) ->size)
			{
				v->route_idx = 0;
				++(v->cmd_idx);
			}
		}
		ant_movement_gen(ft_variablejoin_free(3, ft_strdup("L"),\
			ft_itoa(v->ant_idx), ft_strdup("-")), v->cmds, v->cmd_idx,\
			v->direction->data[v->route_idx]);
	}
}

t_arraylist			*create_direction_set(t_puz *puz)
{
	t_cds_master	*v;
	int				i;

	v = init_cds_master();
	v->cmd_len = (puz->ants / puz->routes->size) + ((t_arraylist *)\
		puz->routes->data[puz->routes->size - 1])->size - 1;
	v->direction = puz->routes;
	if (!(v->cmds = arraylist_new(v->cmd_len, 1.5)))
		return (0);
	route_sort(v->direction);
	i = -1;
	while (++i < v->cmd_len)
		arraylist_add(v->cmds, ft_strnew(0));
	v->route_idx = -1;
	v->cmd_idx = 0;
	v->ant_idx = -1;
	cds_extended(v, puz);
	return (v->cmds);
}
