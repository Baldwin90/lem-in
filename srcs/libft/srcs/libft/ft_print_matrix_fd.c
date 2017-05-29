/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:09:19 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:09:20 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_print_matrix_fd(char **matrix, int fd)
{
	--matrix;
	while (*(++matrix))
		ft_putstr_fd(*matrix, fd);
}
