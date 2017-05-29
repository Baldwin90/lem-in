/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 17:44:15 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/08/20 17:44:16 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define STAT_ISWHITESPACE ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')

static int	word_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && !STAT_ISWHITESPACE)
	{
		i += 1;
	}
	return (i);
}

static char	**store_strings(char **result, char *str)
{
	int i;
	int j;
	int k;
	int wlen;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (!STAT_ISWHITESPACE)
		{
			k = 0;
			wlen = word_len(&str[i]);
			while (k < wlen)
			{
				result[j][k] = str[i];
				k += 1;
				i += 1;
			}
			result[j][k] = '\0';
			j += 1;
		}
		i += 1;
	}
	return (result);
}

static int	word_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && STAT_ISWHITESPACE)
		{
			i += 1;
		}
		if (str[i] != '\0' && !STAT_ISWHITESPACE)
		{
			count += 1;
		}
		while (str[i] != '\0' && !STAT_ISWHITESPACE)
		{
			i += 1;
		}
	}
	return (count);
}

char		**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		wc;
	char	**result;

	wc = word_count(str);
	result = (char**)malloc(sizeof(*result) * (wc + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (j < wc)
	{
		while (STAT_ISWHITESPACE)
			i += 1;
		result[j] = (char*)malloc(sizeof(**result) * (word_len(&str[i]) + 1));
		if (!result[j])
			return (NULL);
		while (str[i] != '\0' && !STAT_ISWHITESPACE)
			i += 1;
		j += 1;
	}
	result[wc] = (NULL);
	return (store_strings(result, str));
}
