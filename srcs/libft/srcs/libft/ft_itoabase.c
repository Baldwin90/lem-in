/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:39:38 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/11/01 15:39:39 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_itoabase(int value, int base)
{
	char	*str;
	char	*cache;
	char	polar;
	char	*bases;

	bases = "0123456789ABCDEF";
	if (!(cache = ft_strnew(32)))
		return (0);
	str = cache + 32;
	polar = value < 0 ? -1 : 1;
	if (!value)
		*(--str) = '0';
	while (value)
	{
		*(--str) = bases[value % base];
		value /= base;
	}
	if (base == 10 && polar == -1)
		*(--str) = '-';
	str = ft_strdup(str);
	free(cache);
	return (str);
}
