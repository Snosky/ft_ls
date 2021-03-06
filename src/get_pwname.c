/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:29:37 by tpayen            #+#    #+#             */
/*   Updated: 2015/12/15 16:39:42 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_pwname(t_list *lst)
{
	if (can(OPT_N))
		return (ft_itoa(g_stat(lst)->st_uid));
	return (getpwuid(g_stat(lst)->st_uid)->pw_name);
}
