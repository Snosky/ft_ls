/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 11:26:56 by tpayen            #+#    #+#             */
/*   Updated: 2015/12/15 16:43:30 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	active_options(char c)
{
	if (c == 'l')
		return (OPT_L);
	else if (c == 'R')
		return (OPT_REC);
	else if (c == 'a')
		return (OPT_A);
	else if (c == 'r')
		return (OPT_REV);
	else if (c == 't')
		return (OPT_T);
	else if (c == 'd')
		return (OPT_D);
	else if (c == 'g')
		return (OPT_G | OPT_L);
	else if (c == 'f')
		return (OPT_F | OPT_A);
	else if (c == 'n')
		return (OPT_N | OPT_L);
	else if (c == 'o')
		return (OPT_O | OPT_L);
	return (0);
}

int			get_options(char **av)
{
	int	x;
	int	y;

	g_options = 0;
	y = 0;
	while (av[++y] && av[y][0] == '-' && av[y][1] != 0)
	{
		x = 0;
		if (!ft_strcmp(av[y], "--"))
		{
			y++;
			break ;
		}
		else
			while (av[y][++x])
				if (!ft_strchr(VALID_ARG, av[y][x]))
					err_arg(av[y][x]);
				else
					g_options |= active_options(av[y][x]);
	}
	return (y);
}
