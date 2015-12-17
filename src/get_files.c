/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 17:16:10 by tpayen            #+#    #+#             */
/*   Updated: 2015/12/17 17:29:11 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	*ft_opendir(char *path, int *total)
{
	t_list			*ret;
	DIR				*dir;
	struct dirent	*f;
	t_list			*t;

	ret = NULL;
	if ((dir = opendir(path)))
	{
		while ((f = readdir(dir)))
			if (can(OPT_A) || (can(OPT_A_M) && (ft_strcmp(f->d_name, ".") &&
					ft_strcmp(f->d_name, ".."))) ||
					(!can(OPT_A) && f->d_name[0] != '.'))
				if ((t = ft_lstnew(new_file(f->d_name, path), sizeof(t_file))))
				{
					ft_lstpush(&ret, t);
					if (can(OPT_L))
						*total += g_stat(t)->st_blocks;
					get_spaces(t);
				}
		closedir(dir);
	}
	return (ret);
}

static void		show_path(void)
{
	if ((can(OPT_REC) && g_p > 1) || g_p > 1)
	{
		if (g_pa != 1)
			ft_putchar('\n');
		ft_putstr(g_path);
		ft_putendl(":");
	}
	g_p++;
	g_pa++;
}

static void		show_total(int total, t_list *n_files, char *name)
{
	if (n_files == NULL)
		err_path(name);
	else
	{
		if (can(OPT_L))
		{
			ft_putstr("total ");\
			ft_putendl(ft_itoa(total));
		}
	}
}

static t_list	*get_dirs(t_list *files)
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*tmp2;

	ret = NULL;
	if (!can(OPT_A))
		return (files);
	while (files)
	{
		tmp = files->next;
		if (S_ISDIR(g_stat(files)->st_mode) && ft_strcmp(g_name(files), ".")
			&& ft_strcmp(g_name(files), ".."))
		{
			if (!(tmp2 = ft_lstnew(files->content, files->content_size)))
				return (NULL);
			ft_lstpush(&ret, tmp2);
		}
		files = NULL;
		free(files);
		files = tmp;
	}
	return (ret);
}

void			get_files(t_list *files, char *path)
{
	t_list	*tmp;
	t_list	*n_files;
	int		total;

	total = 0;
	while (files)
	{
		tmp = files->next;
		if (S_ISDIR(g_stat(files)->st_mode))
		{
			g_path = create_path(g_name(files), path);
			reset_space();
			n_files = ft_opendir(g_path, &total);
			sort_files(n_files);
			show_path();
			show_total(total, n_files, g_name(files));
			show_files(n_files);
			if (n_files && can(OPT_REC))
				get_files(get_dirs(n_files), g_path);
		}
		ft_memdel((void**)&files);
		files = tmp;
	}
}
