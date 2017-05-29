/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:49:40 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/30 15:49:42 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define GNL_BS else if(BUF[i+BUF_IND]=='\n'){grow_string(file,&i,&result,
#define GNL_GARBAGE &r_len);break;}if(N_BYTES_READ == 0){return(result);}
#define GNL_NORM GNL_BS GNL_GARBAGE;
#define GNL_3 {*r_code = 0;return (result);}
#define GNL_4 {*r_code = -1;return (result);}

static t_file	*new_file(const int fd)
{
	static t_file file[F_COUNT_MAX];

	GNL_2;
	while (i <= total)
	{
		if (i == total && total < F_COUNT_MAX)
		{
			total += 1;
			file[i].fd = fd;
			file[i].buf_ind = 0;
			file[i].last_stored = NULL;
			file[i].n_bytes_read = 0;
			while (j < BUFF_SIZE)
			{
				file[i].buf[j] = 0;
				j += 1;
			}
			return (&file[i]);
		}
		else if (file[i].fd == fd)
			return (&file[i]);
		i += 1;
	}
	return (NULL);
}

static void		grow_string(t_file *file, int *i, char **result, int *r_len)
{
	char *tmp;

	tmp = *result;
	if (!(*result = (char*)ft_memalloc(*r_len + *i + 1)))
	{
		return ;
	}
	ft_memcpy(*result, tmp, *r_len);
	ft_memcpy(&(*result)[*r_len], &(BUF[BUF_IND]), *i);
	if (tmp)
		free(tmp);
	BUF_IND += *i + 1;
	*r_len += *i;
	*i = -1;
}

static char		*store_line(t_file *file, char *result, int r_len, int *r_code)
{
	int i;

	i = -1;
	if (BUF_IND >= N_BYTES_READ && (N_BYTES_READ =
		read(file->fd, BUF, BUFF_SIZE)) == 0)
		GNL_3;
	while (TRUE)
	{
		*r_code = 1;
		if (++i + BUF_IND >= BUFF_SIZE || i + BUF_IND >= N_BYTES_READ)
		{
			grow_string(file, &i, &result, &r_len);
			BUF_IND = 0;
			if ((N_BYTES_READ = read(file->fd, BUF, BUFF_SIZE)) < 0)
				GNL_4;
		}
		GNL_NORM;
	}
	if (++i + BUF_IND >= BUFF_SIZE || i + BUF_IND >= N_BYTES_READ)
	{
		BUF_IND = 0;
		if ((N_BYTES_READ = read(file->fd, BUF, BUFF_SIZE)) < 0)
			GNL_4;
	}
	return (result);
}

/*
** If you want it to automatically free the string insert this code in line 99
** if (*line != NULL && *line == file->last_stored){free (*line);}
** If you don't want it to do it then remove lines 99 and 100
*/

int				get_next_line(const int fd, char **line)
{
	t_file	*file;
	char	*result;
	int		r_code;

	r_code = -1;
	if (!(file = new_file(fd)) || line == NULL)
		return (r_code);
	if (*line != NULL && *line == file->last_stored)
		free(*line);
	if (!(result = (char*)ft_memalloc(1)))
		return (r_code);
	if (!(result = store_line(file, result, 0, &r_code)))
		return (-1);
	file->last_stored = result;
	*line = result;
	return (r_code);
}
