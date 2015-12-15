/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 13:19:02 by tpayen            #+#    #+#             */
/*   Updated: 2015/09/29 17:13:05 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		alpha_sort(t_list *lst1, t_list *lst2, int rev)
{
	if ((!rev && ft_strcmp(g_name(lst1), g_name(lst2)) > 0) ||
		(rev && ft_strcmp(g_name(lst1), g_name(lst2)) < 0))
		return (1);
	return (0);
}
