/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 11:19:25 by tpayen            #+#    #+#             */
/*   Updated: 2015/12/17 18:10:06 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	init_space(void)
{
	if (!(g_space = (t_space *)malloc(sizeof(t_space))))
		exit(EXIT_FAILURE);
	g_space->link = 0;
	g_space->user = 0;
	g_space->group = 0;
	g_space->size = 0;
}

static void	do_files(t_list *files)
{
	t_list	*tmp;

	sort_files(files);
	reset_space();
	tmp = files;
	while (tmp)
	{
		get_spaces(tmp);
		g_pa++;
		tmp = tmp->next;
	}
	show_files(files);
}

int			main(int ac, char **av)
{
	int		path_start;
	t_list	*dir;
	t_list	*files;

	init_space();
	path_start = 1;
	dir = NULL;
	files = NULL;
	g_pa = 1;
	if (ac > 1)
		path_start = get_options(av);
	g_p = ((ac - path_start) == 0) ? 1 : ac - path_start;
	get_path(&(av[path_start]), &dir, &files);
	if (files)
		do_files(files);
	if (dir)
	{
		sort_files(dir);
		get_files(dir, NULL);
	}
	return (0);
}
