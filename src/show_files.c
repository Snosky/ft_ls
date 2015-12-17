/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 16:55:07 by tpayen            #+#    #+#             */
/*   Updated: 2015/12/17 19:58:53 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	show_files(t_list *files)
{
	if (can(OPT_L) || can(OPT_M) || can(OPT_ONE))
		while (files)
		{
			if (can(OPT_L))
				opt_l_show(files);
			else if (can(OPT_M))
				opt_m_show(files);
			else if (can(OPT_ONE))
			{
				ft_putstr(show_color(files));
				if (can(OPT_P) && S_ISDIR(g_stat(files)->st_mode))
					ft_putstr("/ \n");
				else
					ft_putchar('\n');
			}
			files = files->next;
		}
	else
		show_column(files);
}
