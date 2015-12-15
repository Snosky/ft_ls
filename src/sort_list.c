/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 12:52:35 by tpayen            #+#    #+#             */
/*   Updated: 2015/12/15 16:30:45 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_swaplist(t_list *lst1, t_list *lst2)
{
	t_file	*tmp;

	tmp = ((t_file *)lst1->content);
	lst1->content = lst2->content;
	lst2->content = tmp;
}

static void	sort_list(t_list *list, int (*f)(t_list *, t_list *, int))
{
	t_list	*tmp_ptr;
	t_list	*tmp_nxt;

	tmp_ptr = list;
	tmp_nxt = list->next;
	while (tmp_nxt != NULL)
	{
		while (tmp_nxt != tmp_ptr)
		{
			if ((*f)(tmp_ptr, tmp_nxt, can(OPT_REV)))
				ft_swaplist(tmp_ptr, tmp_nxt);
			tmp_ptr = tmp_ptr->next;
		}
		tmp_ptr = list;
		tmp_nxt = tmp_nxt->next;
	}
}

void		sort_files(t_list *list)
{
	if (list)
	{
		if (can(OPT_T))
			sort_list(list, opt_t_sort);
		else if (!can(OPT_F))
			sort_list(list, alpha_sort);
	}
}
