/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_t_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 13:10:08 by tpayen            #+#    #+#             */
/*   Updated: 2015/09/29 17:23:14 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	opt_t_sort(t_list *lst1, t_list *lst2, int rev)
{
	if ((!rev && (g_stat(lst1)->st_mtime) - (g_stat(lst2)->st_mtime) < 0)
		|| (rev && (g_stat(lst1)->st_mtime) - (g_stat(lst2)->st_mtime) > 0)
		|| (g_stat(lst1)->st_mtime == g_stat(lst2)->st_mtime
		&& alpha_sort(lst1, lst2, rev)))
		return (1);
	return (0);
}
