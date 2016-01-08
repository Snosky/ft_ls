/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:02:09 by tpayen            #+#    #+#             */
/*   Updated: 2016/01/08 17:53:35 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_spaces(t_list *lst)
{
	int	i;

	if (can(OPT_L))
	{
		if ((i = ft_intlen(g_stat(lst)->st_nlink)) > g_space->link)
			g_space->link = i;
		if (getpwuid(g_stat(lst)->st_uid) &&
			(i = ft_strlen(get_pwname(lst))) > g_space->user)
			g_space->user = i;
		if (getgrgid(g_stat(lst)->st_gid) &&
			(i = ft_strlen(get_grname(lst))) > g_space->group)
			g_space->group = i;
		else if ((i = ft_intlen(g_stat(lst)->st_uid)) > g_space->group)
			g_space->group = i;
		if ((i = ft_intlen(g_stat(lst)->st_size)) > g_space->size)
			g_space->size = i;
	}
	else
	{
		if ((i = ft_strlen(g_name(lst))) > g_space->name)
			g_space->name = i;
	}
}
