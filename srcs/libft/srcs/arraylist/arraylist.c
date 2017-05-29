/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:47:15 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:10:20 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_arraylist	*arraylist_new(int default_size, double multiplier)
{
	t_arraylist	*list;

	if (!(list = (t_arraylist *)ft_memalloc(sizeof(t_arraylist))))
		return (NULL);
	list->size = 0;
	list->multiplier = multiplier;
	list->alloc_size = default_size;
	if (!(list->data = (void *)ft_memalloc(sizeof(void *) * list->alloc_size)))
	{
		free(list);
		return (NULL);
	}
	return (list);
}

int			arraylist_add(t_arraylist *list, void *item)
{
	if (list->size >= list->alloc_size)
	{
		if (!(list->data = ft_realloc(list->data, sizeof(void *) * \
			list->size, sizeof(void *) * list->alloc_size * \
			list->multiplier)))
			return (0);
		list->alloc_size = list->alloc_size * list->multiplier;
	}
	list->data[list->size++] = item;
	return (1);
}

int			arraylist_indexof(t_arraylist *list, void *item)
{
	int	idx;

	idx = -1;
	while (++idx < list->size)
		if (list->data[idx] == item)
			return (idx);
	return (-1);
}

int			arraylist_del(t_arraylist *list, void *item)
{
	int	idx;

	idx = -1;
	while (++idx < list->size)
		if (list->data[idx] == item)
			break ;
	if (idx >= list->size)
		return (0);
	ft_memmove(list->data + idx, list->data + idx + 1, \
		sizeof(void *) * (list->size - idx + 1));
	list->data[list->size--] = 0;
	return (1);
}

t_arraylist	*arraylist_clone(t_arraylist *list)
{
	t_arraylist *new_list;

	if (!(new_list = arraylist_new(list->alloc_size, list->multiplier)))
		return (0);
	new_list->size = list->size;
	ft_memcpy(new_list->data, list->data, sizeof(void *) * list->size);
	return (new_list);
}
