/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hasflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:24:07 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/09 19:24:11 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_hasflag(char needle, long long haystack)
{
	int	answer;

	answer = ft_indexof(needle, FLAG_LIST);
	if (answer == -1)
	{
		return (FALSE);
	}
	answer = 1 << answer;
	return ((haystack & (long long)answer) ? 1 : 0);
}
