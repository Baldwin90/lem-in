/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:06:53 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:06:54 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>

void	free_puz(t_puz *puz)
{
	if (puz)
	{
		routes_free(puz->routes);
		free(puz);
		puz = NULL;
	}
}

void	routes_free(t_arraylist *routes)
{
	int	i;

	if (routes)
	{
		i = 0;
		while (i < routes->size)
		{
			arraylist_free((t_arraylist *)routes->data[i]);
			i += 1;
		}
		arraylist_free(routes);
		routes = NULL;
	}
}

void	node_free(t_node *node)
{
	if (node)
	{
		if (node->name)
		{
			free(node->name);
			node->name = NULL;
		}
		if (node->nodes)
			arraylist_free(node->nodes);
		if (node->route)
		{
			arraylist_free(node->route);
			node->route = NULL;
		}
		free(node);
		node = NULL;
	}
}

void	r_data_free(t_r_data *rd)
{
	t_node	*node;
	int		i;
	int		limit;

	if (!rd)
		return ;
	if (rd->list)
	{
		if (rd->list->data)
		{
			node = rd->list->data[0];
			i = 0;
			limit = rd->list->size;
			while (i < limit)
			{
				node_free(node);
				i += 1;
				node = rd->list->data[i];
			}
		}
		arraylist_free(rd->list);
	}
	free(rd);
}

void	li_e(int e_nbr, t_r_data *rd, t_puz *puz, t_arraylist *routes)
{
	r_data_free(rd);
	free_puz(puz);
	routes_free(routes);
	ft_putstr_fd("ERROR\n", 1);
	exit(e_nbr);
}
