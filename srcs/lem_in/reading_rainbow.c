/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_rainbow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:06:53 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/15 11:06:54 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static void	lem_in_r4(t_reader_master *v)
{
	ft_putstr("\n");
	if (v->line != NULL)
	{
		free(v->line);
		v->line = NULL;
	}
	if (v->gnl_res == -1)
		ERROR(22, v->rd, NULL, NULL);
	if (!((v->rd->ants > -1) && v->rd->start && v->rd->end &&\
		v->rd->has_links))
		ERROR(23, v->rd, NULL, NULL);
	if (v->fd && close(v->fd) == -1)
		li_e(1000, v->rd, NULL, NULL);
}

static void	lem_in_r3(t_reader_master *v)
{
	if (v->f_count == 1)
	{
		if (!v->rd->start || !v->rd->end)
			ERROR(16, v->rd, NULL, NULL);
		if (ft_char_tot(v->line, '-') != 1)
			ERROR(17, v->rd, NULL, NULL);
		FF;
		v->fields = ft_strsplit(v->line, '-');
		v->e_nbr = linker(v->fields, v->rd);
		if (v->e_nbr)
			ERROR(v->e_nbr, v->rd, NULL, NULL);
	}
	else if (v->f_count != 3)
		ERROR(21, v->rd, NULL, NULL);
	FF;
}

static void	lem_in_r2(t_reader_master *v)
{
	if (ft_isnumeric(v->line) && v->rd->ants == -1 && !v->cmd)
	{
		v->rd->ants = ft_atoi(v->line);
		if (v->rd->ants < 0)
			ERROR(6, v->rd, NULL, NULL);
		return ;
	}
	if (v->rd->ants < 0)
		ERROR(6, v->rd, NULL, NULL);
	v->fields = ft_strsplit(v->line, ' ');
	v->f_count = -1;
	while (v->fields[++(v->f_count)] != NULL)
		;
	if (v->f_count == 3)
	{
		if (ft_char_tot(v->line, ' ') != 2)
			ERROR(7, v->rd, NULL, NULL);
		v->e_nbr = s_room(v->fields, v->type, v->rd);
		if (v->e_nbr)
			ERROR(v->e_nbr, v->rd, NULL, NULL);
	}
	lem_in_r3(v);
}

static void	lem_in_r1(t_reader_master *v)
{
	while ((v->gnl_res = get_next_line(v->fd, &(v->line))) == 1)
	{
		ft_printf("%s\n", v->line);
		v->cmd = 0;
		v->type = NT_NORMAL;
		if (ft_strlen(v->line) == 0)
			ERROR(5, v->rd, NULL, NULL);
		if (!ft_strcmp(v->line, "##start") || !ft_strcmp(v->line, "##end"))
		{
			v->cmd = 1;
			if (v->rd->ants < 0)
				ERROR(6, v->rd, NULL, NULL);
			if (!ft_strcmp(v->line, "##start"))
				v->type = NT_START;
			else if (!ft_strcmp(v->line, "##end"))
				v->type = NT_END;
			get_next_line(v->fd, &(v->line));
			ft_printf("%s\n", v->line);
		}
		else if (v->line[0] == '#')
			continue;
		lem_in_r2(v);
	}
	lem_in_r4(v);
}

void		reader(int argc, char **argv, t_r_data **r_data)
{
	t_reader_master	*v;

	v = init_reader_master();
	if (argc > 2)
		li_e(1, v->rd, NULL, NULL);
	if (!(v->rd = (t_r_data*)ft_memalloc(sizeof(*(v->rd)))))
		li_e(2, v->rd, NULL, NULL);
	*r_data = v->rd;
	v->rd->ants = -1;
	if (!(v->rd->list = arraylist_new(2, 2)))
		li_e(3, v->rd, NULL, NULL);
	if (argc == 2)
		v->fd = open(argv[1], O_RDONLY);
	else
		v->fd = 0;
	if (v->fd == -1)
		li_e(4, v->rd, NULL, NULL);
	lem_in_r1(v);
}
