/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:11:15 by tpayen            #+#    #+#             */
/*   Updated: 2015/12/17 19:08:55 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*show_color(t_list *file)
{
	char	*color;
	int		st;
	char	*name;

	color = "";
	name = ft_strjoin(g_name(file), "\x1b[0m");
	st = g_stat(file)->st_mode;
	if (can(OPT_G_COLOR))
	{
		if (S_ISVTX & st && st & S_IWOTH)
			color = "\x1b[32m";
		else if (S_ISLNK(st))
			color = "\x1B[35m";
		else if (st & S_IFREG && !(st & S_IXUSR))
			color = "\x1b[0m";
		else if (S_ISDIR(st))
			color = "\x1B[34m";
		else if (st & S_IXUSR)
			color = "\x1b[31m";
	}
	return (ft_strjoin(color, name));
}
