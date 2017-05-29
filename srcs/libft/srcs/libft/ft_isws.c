/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isws.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:07:58 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:08:44 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_ISWS_START(c)	switch(c){case 9:case 10:case 11:case 12:
#define FT_ISWS_END		case 13:case 32:return(1);}return(0);

int	ft_isws(char c)
{
	FT_ISWS_START(c);
	FT_ISWS_END;
}
