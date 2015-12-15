/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_acl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 18:04:09 by tpayen            #+#    #+#             */
/*   Updated: 2015/04/29 16:23:12 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	show_type(mode_t st_mode)
{
	if (S_ISBLK(st_mode))
		ft_putchar('b');
	else if (S_ISCHR(st_mode))
		ft_putchar('c');
	else if (S_ISDIR(st_mode))
		ft_putchar('d');
	else if (S_ISLNK(st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(st_mode))
		ft_putchar('s');
	else if (S_ISFIFO(st_mode))
		ft_putchar('p');
	else if (S_ISREG(st_mode))
		ft_putchar('-');
}

static char	exec_right(mode_t st_mode, int s)
{
	if ((s & S_IXUSR) && (st_mode & s) && (st_mode & S_ISUID))
		return ('s');
	else if ((s & S_IXUSR) && (st_mode | s) && (st_mode & S_ISUID))
		return ('S');
	if ((s & S_IXGRP) && (st_mode & s) && (st_mode & S_ISGID))
		return ('s');
	else if ((s & S_IXGRP) && (st_mode | s) && (st_mode & S_ISGID))
		return ('S');
	if ((s & S_IXOTH) && (st_mode & s) && (st_mode & S_ISVTX))
		return ('t');
	else if ((s & S_IXOTH) && (st_mode | s) && (st_mode & S_ISVTX))
		return ('T');
	else if ((st_mode & s))
		return ('x');
	return ('-');
}

static char	acl(char *s)
{
	if (listxattr(create_path(s, g_path), NULL, 256, 1) > 0)
		return ('@');
	else if (acl_get_link_np(create_path(s, g_path), ACL_TYPE_EXTENDED))
		return ('+');
	return ('\0');
}

void		show_acl(t_list *lst)
{
	char	r[11];

	show_type(g_stat(lst)->st_mode);
	r[0] = (g_stat(lst)->st_mode & S_IRUSR) ? 'r' : '-';
	r[1] = (g_stat(lst)->st_mode & S_IWUSR) ? 'w' : '-';
	r[2] = exec_right(g_stat(lst)->st_mode, S_IXUSR);
	r[3] = (g_stat(lst)->st_mode & S_IRGRP) ? 'r' : '-';
	r[4] = (g_stat(lst)->st_mode & S_IWGRP) ? 'w' : '-';
	r[5] = exec_right(g_stat(lst)->st_mode, S_IXGRP);
	r[6] = (g_stat(lst)->st_mode & S_IROTH) ? 'r' : '-';
	r[7] = (g_stat(lst)->st_mode & S_IWOTH) ? 'w' : '-';
	r[8] = exec_right(g_stat(lst)->st_mode, S_IXOTH);
	r[9] = acl(g_name(lst));
	r[10] = '\0';
	write(1, r, 11);
}
