/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_tot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:06:53 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:06:54 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_tot(char *str, char c)
{
	int	count;

	count = 0;
	str--;
	while (*(++str))
	{
		if (*str == c)
		{
			count++;
		}
	}
	return (count);
}