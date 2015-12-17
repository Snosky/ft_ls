/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_m_show.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:00:02 by tpayen            #+#    #+#             */
/*   Updated: 2015/12/17 19:21:31 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	opt_m_show(t_list *lst)
{
	ft_putstr(show_color(lst));
	if (can(OPT_P) && S_ISDIR(g_stat(lst)->st_mode))
		ft_putchar('/');
	if (lst->next)
		ft_putstr(", ");
}
