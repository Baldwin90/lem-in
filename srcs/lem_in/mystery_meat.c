/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystery_meat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:06:53 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:06:54 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>

#define ARRL t_arraylist
#define ANT_MOVEMENT ant_movement_gen

void	ant_movement_gen(char *ant_name, ARRL *cmds, int cmd_idx, ARRL *route)
{
	char	*cache;
	int		i;

	i = 0;
	while (++i < route->size)
	{
		cache = cmds->data[cmd_idx + i - 1];
		if (ft_strlen(cache) == 0)
		{
			cmds->data[cmd_idx + i - 1] = ft_variablejoin(2, ant_name,\
				((t_node *)route->data[i])->name);
		}
		else
		{
			cmds->data[cmd_idx + i - 1] = ft_variablejoin(4, cache,\
				" ", ant_name, ((t_node *)route->data[i])->name);
		}
		free(cache);
	}
	free(ant_name);
}

int		directly_linked(t_r_data *rd)
{
	int	idx;

	idx = -1;
	while (++idx < rd->start->nodes->size)
		if (((t_node *)rd->start->nodes->data[idx])->type == NT_END)
			return (TRUE);
	return (FALSE);
}
