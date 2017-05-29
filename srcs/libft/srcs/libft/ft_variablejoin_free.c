/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variablejoin_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:47:15 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:10:20 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#define SF n_cache=n;va_end(va);va_start(va, n);

char	*ft_variablejoin_free(int n, ...)
{
	va_list	va;
	int		len;
	char	*ret;
	int		n_cache;
	char	*cpy;

	va_start(va, n);
	len = 0;
	n_cache = n;
	while (n_cache--)
		len += ft_strlen(va_arg(va, char *));
	SF;
	if ((ret = ft_strnew(len) - 1))
		while (n_cache--)
		{
			cpy = va_arg(va, char *) - 1;
			while (*(++cpy))
				*(++ret) = *cpy;
		}
	SF;
	while (n_cache--)
		free(va_arg(va, char *));
	va_end(va);
	return (ret - len + 1);
}
