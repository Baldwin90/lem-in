/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 00:16:26 by pbaldwin          #+#    #+#             */
/*   Updated: 2016/12/12 21:52:23 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** TODO LIST:
**
** line ?? - you need to write function for handling "--" commands
** OLD NOTE - check if "--" commands are legal, like "git config --global"
** line 30-33 and 35-40 - prints out the same things as below
** sprintf("%s: illegal option -- %c\n", &argv[0][2], argv[i][j]);
** sprintf("usage: %s [-%s] %s\n", &argv[0][2], FLAG_LIST, USAGE);
**
** line 41 - make sure exit is allowed
*/

#include <libft.h>

static void	gf_print_error(char c, char **argv, int ernbr)
{
	ft_putstr_fd(argv[0], 2);
	ft_putstr_fd(": illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(GF_FILE_NAME, 2);
	ft_putstr_fd(" [-", 2);
	ft_putstr_fd(FLAG_LIST, 2);
	ft_putstr_fd("] ", 2);
	ft_putstr_fd(USAGE, 2);
	ft_putchar_fd('\n', 2);
	exit(ernbr);
}

static int	checkfor_flagstr(t_flagobj *flagobj, int *i, char **argv)
{
	if (argv[*i][1] == '-' || ft_indexof(argv[*i][1], FLAG_EXEMPT) > -1)
	{
		if (argv[*i][1] == '-')
		{
			flagobj->args_start += 1;
			if (argv[*i][2] != '\0')
			{
				gf_print_error('-', argv, 1);
			}
			return (0);
		}
	}
	return (1);
}

static void	store_flags(t_flagobj *flagobj, int *i, char **argv)
{
	int	j;
	int	curflag;

	j = 1;
	while (argv[*i][j] != '\0')
	{
		curflag = ft_indexof(argv[*i][j], FLAG_LIST);
		if (curflag == -1)
		{
			gf_print_error(argv[*i][j], argv, 1);
		}
		flagobj->flags |= 1 << curflag;
		j += 1;
	}
}

t_flagobj	ft_getflags(char **argv)
{
	int			i;
	t_flagobj	flagobj;

	flagobj.flags = 0;
	flagobj.args_start = 1;
	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] != '\0' \
		&& checkfor_flagstr(&flagobj, &i, argv))
	{
		store_flags(&flagobj, &i, argv);
		flagobj.args_start += 1;
		i += 1;
	}
	return (flagobj);
}
