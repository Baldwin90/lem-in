/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:47:15 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:10:20 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	arraylist_free(t_arraylist *list)
{
	if (list->data != NULL)
	{
		free(list->data);
		list->data = NULL;
	}
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
}
