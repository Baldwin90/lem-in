/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:06:53 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:06:54 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
#include <libft.h>

void	create_node_link(t_node *n1, t_node *n2)
{
	arraylist_add(n1->nodes, n2);
	arraylist_add(n2->nodes, n1);
}

t_node	*new_node(char *name, t_ntype type, int x, int y)
{
	t_node	*node;

	node = (t_node *)ft_memalloc(sizeof(*node));
	node->nodes = arraylist_new(10, 1.5);
	node->route = (type == NT_START) ? arraylist_new(10, 1.5) : 0;
	if (type == NT_START)
	{
		arraylist_add(node->route, node);
	}
	node->name = ft_strdup(name);
	node->type = type;
	node->x = x;
	node->y = y;
	node->dist = (type == NT_START) ? 0 : -1;
	return (node);
}
