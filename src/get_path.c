/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 12:10:17 by tpayen            #+#    #+#             */
/*   Updated: 2015/09/29 17:19:05 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	sort_alpha_tab(char **tab)
{
	int	i;
	int	swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (tab[i + 1])
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				ft_strswap(&tab[i], &tab[i + 1]);
				swap = 1;
			}
			i++;
		}
	}
}

void		get_path(char **av, t_list **dir, t_list **files)
{
	t_list	*t;

	if (*av == NULL)
	{
		if (can(OPT_D))
			*files = ft_lstnew(new_file(".", NULL), sizeof(t_file));
		else
			*dir = ft_lstnew(new_file(".", NULL), sizeof(t_file));
		return ;
	}
	sort_alpha_tab(av);
	while (*av)
	{
		if ((t = ft_lstnew(new_file(*av, NULL), sizeof(t_file)))
				&& t->content != NULL)
			if (!can(OPT_D) && S_ISDIR(g_stat(t)->st_mode))
				ft_lstpush(dir, t);
			else
				ft_lstpush(files, t);
		else
			err_path(*av);
		av++;
	}
}
