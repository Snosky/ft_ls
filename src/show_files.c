/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 16:55:07 by tpayen            #+#    #+#             */
/*   Updated: 2015/04/13 15:30:36 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	show_files(t_list *files)
{
	while (files)
	{
		if (can(OPT_L))
			opt_l_show(files);
		else
			ft_putendl(g_name(files));
		files = files->next;
	}
}
