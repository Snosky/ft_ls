/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:31:04 by tpayen            #+#    #+#             */
/*   Updated: 2015/12/15 16:37:36 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_grname(t_list *lst)
{
	if (can(OPT_N))
		return ft_itoa(g_stat(lst)->st_gid);
	return (getgrgid(g_stat(lst)->st_gid)->gr_name);
}
