/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:06:53 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:06:54 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
#include <libft.h>

void	route_sort(t_arraylist *route)
{
	char	swapped;
	void	*cache;
	int		i;

	while (TRUE)
	{
		swapped = FALSE;
		i = -1;
		while (++i < route->size - 1)
		{
			if (((t_arraylist *)route->data[i])->size >\
				((t_arraylist *)route->data[i + 1])->size)
			{
				cache = route->data[i];
				route->data[i] = route->data[i + 1];
				route->data[i + 1] = cache;
				swapped = TRUE;
			}
		}
		if (swapped == FALSE)
			break ;
	}
}
