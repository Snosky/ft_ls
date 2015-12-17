/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 11:26:56 by tpayen            #+#    #+#             */
/*   Updated: 2015/12/17 18:16:39 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	remove_option(int i)
{
	if (can(i))
		g_options ^= i;
}

static void	active_options_more(char c)
{
	if (c == 'm')
	{
		remove_option(OPT_L);
		g_options |= OPT_M;
	}
	else if (c == 'p')
		g_options |= OPT_P;
	else if (c == 'A')
		g_options |= OPT_A_M;
	else if (c == 'G')
		g_options |= OPT_G_COLOR;
}

static void	active_options(char c)
{
	if (c == 'l')
		g_options |= OPT_L;
	else if (c == '1')
		remove_option(OPT_L);
	else if (c == 'R')
		g_options |= OPT_REC;
	else if (c == 'a')
		g_options |= OPT_A;
	else if (c == 'r')
		g_options |= OPT_REV;
	else if (c == 't')
		g_options |= OPT_T;
	else if (c == 'd')
		g_options |= OPT_D;
	else if (c == 'g')
		g_options |= (OPT_G | OPT_L);
	else if (c == 'f')
		g_options |= (OPT_F | OPT_A);
	else if (c == 'n')
		g_options |= (OPT_N | OPT_L);
	else if (c == 'o')
		g_options |= (OPT_O | OPT_L);
	else
		active_options_more(c);
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
					active_options(av[y][x]);
	}
	return (y);
}
