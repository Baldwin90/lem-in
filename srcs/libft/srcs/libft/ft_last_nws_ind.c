/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_nws_ind.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:08:56 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:08:57 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_last_nws_ind(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = -1;
	while (str[++i])
		;
	if (i == 0)
		return (0);
	while (ft_isws(str[--i]))
		;
	return (i);
}
