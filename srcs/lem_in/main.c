/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:06:53 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:06:54 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <lemin.h>

#define LEMMAINVARS1 t_r_data *r_data;t_puz *puz;
#define LEMMAINVARS2 t_arraylist *cmds;int i;
#define LEMMAINVARS LEMMAINVARS1;LEMMAINVARS2;

int	main(int argc, char **argv)
{
	LEMMAINVARS;
	reader(argc, argv, &r_data);
	puz = new_puz(r_data->ants);
	if (!create_routes(r_data, puz->routes))
	{
		if (!puz->routes->size)
			ft_printf("ERROR\n");
		else
		{
			cmds = create_direction_set(puz);
			i = -1;
			while (++i < cmds->size)
			{
				if (ft_strlen(cmds->data[i]))
					ft_printf("%s\n", cmds->data[i]);
				free(cmds->data[i]);
			}
			arraylist_free(cmds);
		}
	}
	free_puz(puz);
	r_data_free(r_data);
	return (0);
}
